#ifndef LEXER_HPP
#define LEXER_HPP

#include "../token/Token.hpp"

#include <vector>
#include <string>

namespace KiloLang
{

    struct LexResult
    {
        std::vector<Token> tokens;
    };

    const std::string keywords[] = {
        "func", "end",
        "let", "define"
    };

    class Lexer /* Singleton */
    {
        public:
            static Lexer & get();
        private:
            static inline Lexer * instance = nullptr;
        public:
            void clean();
            LexResult makeTokens();

            Token makeWordToken();
            Token makeNumberToken();

            bool isWhitespace();
            bool isValidCharForWord();
            bool isEOL();
            bool isComment();

        public:
            void setSource(std::string & src);
            std::string getSource() const;
            ~Lexer();
        private:
            void advance();
            Lexer();
        private:
            unsigned int position;
            char currentChar;
            std::string src;
    };
}

#endif