#ifndef TOKEN_HPP
#define TOKEN_HPP

#include "../tokentype/TokenType.hpp"

#include <string>

namespace KiloLang
{
    class Token
    {
        public:
            Token(TokenType type);
            Token(TokenType type, std::string value);
            ~Token();

            std::string toString();
        private:
            TokenType type;
            std::string value;

    };
}

#endif