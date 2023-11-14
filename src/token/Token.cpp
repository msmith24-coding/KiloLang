#include "Token.hpp"

#include <sstream>

namespace KiloLang
{
    Token::Token(TokenType type)
    {
        this->type = type;
        this->value = "";
    }

    Token::Token(TokenType type, std::string value)
    {
        this->type = type;
        this->value = value;
    }

    Token::~Token() = default;

    std::string Token::toString()
    {
        std::stringstream ss;
        if(this->value == "") {
            ss << "(" << tokentypeToString(this->type) << ")";
        } else {
            ss << "(" <<  tokentypeToString(this->type) << ":" << this->value << ")";
        }
        return ss.str();

    }
}