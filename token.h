#ifndef TOKEN_H
#define TOKEN_H

#include <QString>

enum class TokenType
{
    command,
    option,
    value
};

struct Token
{
    TokenType type;
    QString name;

    bool operator ==(const Token& rhs) const
    {
        return (type == rhs.type && name == rhs.name);
    }

    bool operator !=(const Token& rhs) const
    {
        return !(rhs == *this);
    }
};


#endif // TOKEN_H
