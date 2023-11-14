#include "TokenType.hpp"

namespace KiloLang
{
    std::string tokentypeToString(TokenType type)
    {
        switch(type) {
            case TokenType::IDENTIFIER: return "IDENTIFER";
            case TokenType::KEYWORD: return "KEYWORD";
            case TokenType::LPAREN: return "LPAREN";
            case TokenType::RPAREN: return "RPAREN";
            case TokenType::COLON: return "COLON";
            case TokenType::EOL: return "EOL";
            case TokenType::END: return "END";
            
            default: return "UNKNOWN";
        }
    }
}