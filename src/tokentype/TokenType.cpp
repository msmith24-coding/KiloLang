#include "TokenType.hpp"

namespace KiloLang
{
    std::string tokentypeToString(TokenType type)
    {
        switch(type) {
            case TokenType::IDENTIFIER: return "IDENTIFER";
            case TokenType::KEYWORD: return "KEYWORD";
            case TokenType::NUMBER: return "NUMBER";

            case TokenType::LPAREN: return "LPAREN";
            case TokenType::RPAREN: return "RPAREN";
            case TokenType::COLON: return "COLON";

            case TokenType::EQ: return "EQ"; 
            case TokenType::PLUS: return "PLUS";
            case TokenType::MINUS: return "MINUS";
            case TokenType::MUL: return "MUL";
            case TokenType::DIV: return "DIV";
            
            case TokenType::EOL: return "EOL";
            case TokenType::END: return "END";
            
            default: return "UNKNOWN";
        }
    }
}