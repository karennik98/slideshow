#include "command_parser.h"

#include <QString>
#include <QVector>

#include <algorithm>

QVector<Token> CommandParser::parse()
{
    QVector<Token> tokens;

    while(!isAtEnd())
    {
        eatWhitespaces();
        if(isAtEnd()) {
            break;
        }
        const auto token = getNextToken();
        tokens.push_back(token);
    }

    return tokens;
}

Token CommandParser::getNextToken()
{
    if(isCommandToken())
    {
        return getCommandToken();
    }
    else if(isOptionToken())
    {
        return getOptionToken();
    }
    else if(isValueToken())
    {
        return getValueToken();
    }

    return {};
}

Token CommandParser::getCommandToken()
{
    const auto pred = [&](const QChar ch)
    {
        return !ch.isLetter() && '_' != ch;
    };

    return getEatTokenForPredicate(TokenType::command, pred);
}

Token CommandParser::getOptionToken()
{
    eat();
    const auto pred = [&](const QChar ch)
    {
        return !ch.isLetter();
    };

    return getEatTokenForPredicate(TokenType::option, pred);
}

Token CommandParser::getValueToken()
{
    eat();
    const auto pred = [&](const QChar ch)
    {
        return !ch.isDigit() && ch != ',';
    };

    return getEatTokenForPredicate(TokenType::value, pred);
}

template <typename Predicate>
Token CommandParser::getEatTokenForPredicate(TokenType type, Predicate&& pred)
{
    const auto begin = mChar;
    const auto found = std::find_if(begin, mEnd, pred);
    const auto str = QStringView{ &current_ref(), static_cast<QString::size_type>(std::distance(begin, found)) }; //TODO check

    eat(str.size());
    if(')' == *mChar) {
        eat();
    }

    return {type, str.toString()};
}

bool CommandParser::isCommandToken() const
{
    return !isAtEnd() && current().isLetter();
}

bool CommandParser::isOptionToken() const
{
    return '-' == *mChar;
}

bool CommandParser::isValueToken() const
{
    return '(' == *mChar;
}

bool CommandParser::isAtEnd() const
{
    return mChar == mEnd;
}

QChar CommandParser::current() const
{
    return *mChar;
}

const QChar& CommandParser::current_ref() const
{
    return *mChar;
}

void CommandParser::eat(size_t size)
{
    std::advance(mChar, size);
}

void CommandParser::eatWhitespaces()
{
    const auto begin = mChar;
    const auto pred = [](const QChar ch)
    {
        return !ch.isSpace();
    };
    const auto found = std::find_if(begin, mEnd, pred);
    const auto whitespaces_count = std::distance(begin, found);
    if(whitespaces_count > 0)
    {
        eat(whitespaces_count);
    }
}















