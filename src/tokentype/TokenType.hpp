#ifndef TOKEN_TYPE_HPP
#define TOKEN_TYPE_HPP

#include <string>

namespace KiloLang
{
    enum class TokenType
    {
        KEYWORD, IDENTIFIER, NUMBER,
        LPAREN, RPAREN, COLON,
        EQ, PLUS, MINUS, MUL, DIV,
        EOL, END
    };

    std::string tokentypeToString(TokenType type);

}

#endif