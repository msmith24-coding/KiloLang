#include "Lexer.hpp"

#include <iostream>
#include <cctype>
#include <algorithm>

namespace KiloLang
{
    Lexer & Lexer::get()
    {
        if(instance == nullptr) {
            instance = new Lexer();
        }

        return *instance;
    }

    void Lexer::clean()
    {
        delete instance;
    }

    LexResult Lexer::makeTokens()
    {
        LexResult result;
        std::vector<Token> tokens;

        this->advance();
        while(this->currentChar != 0) {
            if(this->isWhitespace()) {
                this->advance();
            }
            else if(this->isValidCharForWord()) {
                tokens.push_back(this->makeWordToken());
            }
            else if(this->currentChar == '(') {
                tokens.push_back(Token(TokenType::LPAREN));
                this->advance();
            }
            else if(this->currentChar == ')') {
                tokens.push_back(Token(TokenType::RPAREN));
                this->advance();
            }
            else if(this->currentChar == ':') {
                tokens.push_back(Token(TokenType::COLON));
                this->advance();
            }
            else if(this->isEOL()) {
                tokens.push_back(Token(TokenType::EOL));
                this->advance();
            }
            else if(this->isComment()) {
                while(this->currentChar != '\n') {
                    this->advance();
                }
            }

        }

        tokens.push_back(Token(TokenType::END));

        result.tokens = tokens;

        return result;
    }

    Token Lexer::makeWordToken()
    {
        std::string word;
        while(this->isValidCharForWord()) {
            word += this->currentChar;
            this->advance();
        }

        bool isKey = std::find(std::begin(keywords), std::end(keywords), word) != std::end(keywords);

        if(isKey) {
            return Token(TokenType::KEYWORD, word);
        }
        return Token(TokenType::IDENTIFIER, word);

    }

    bool Lexer::isWhitespace()
    {
        if(std::isspace(this->currentChar)) {
            return true;
        }
        return false;
    }

    bool Lexer::isValidCharForWord()
    {
        return isalpha(this->currentChar) || this->currentChar == '_';
    }

    bool Lexer::isEOL()
    {
        return this->currentChar == ';';
    }

    bool Lexer::isComment()
    {
        return this->currentChar == '#';
    }

    void Lexer::setSource(std::string & src)
    {
        this->src = src;
    }

    std::string Lexer::getSource() const
    {
        return this->src;
    }

    void Lexer::advance()
    {
        this->position++;
        if(this->position < this->src.size()) {
            this->currentChar = this->src[this->position];
            
            return;
        }
        this->currentChar = 0;
    }

    Lexer::Lexer()
    {
        this->position = -1;
        this->currentChar = 0;
        this->src = "";
    }

    Lexer::~Lexer() = default;

}