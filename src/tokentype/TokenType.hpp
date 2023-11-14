#ifndef TOKEN_TYPE_HPP
#define TOKEN_TYPE_HPP

#include <string>

namespace KiloLang
{
    enum class TokenType
    {
        KEYWORD, IDENTIFIER, 
        LPAREN, RPAREN,
        COLON,
        EOL, END
    };

    std::string tokentypeToString(TokenType type);

}

#endif