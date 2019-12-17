#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include "token.h"

#include <QString>
#include <QChar>

class ICommand;

class CommandParser
{
public:
    CommandParser()=default;
    CommandParser(const QString& line)
        : mChar{ line.cbegin() }
        , mEnd { line.cend()   }
    {}
    QVector<Token> parse();
private:
    bool isAtEnd() const;
    bool isCommandToken() const;
    bool isOptionToken() const;
    bool isValueToken() const;

    Token getNextToken();
    Token getCommandToken();
    Token getOptionToken();
    Token getValueToken();

    template<typename Predicate>
    Token getEatTokenForPredicate(TokenType type, Predicate&& pred);

    void eatWhitespaces();
    void eat(size_t size = 1u);
    QChar current() const;
    const QChar& current_ref() const;
private:
    QString::const_iterator mChar;
    QString::const_iterator mEnd;
};

#endif // COMMANDPARSER_H
