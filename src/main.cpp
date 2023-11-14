#include "filereader/FileReader.hpp"
#include "lexer/Lexer.hpp"

using namespace KiloLang;

int main(int argc, char* argv[])
{
    if(argc > 1) {
        FileReader fileReader = FileReader::get();
        Lexer lex = Lexer::get();

        std::string filePath = argv[1];
        std::string src = fileReader.readFile(filePath);

        fileReader.clean(); // <-- Removes the static instance of the file reader singleton.

        src += "\n";
        src += "# Generated code to force main function.\n";
        src += "_main();";

        std::cout << src << std::endl; // <-- Debug line to output the contents of the file.

        lex.setSource(src);
        
        LexResult lexResult;
        lexResult = lex.makeTokens();

        std::cout << "[" << std::endl;

        for(unsigned int i = 0; i < lexResult.tokens.size(); ++i) {
            std::cout << "\t" << lexResult.tokens.at(i).toString() << " " << std::endl;
        }

        std::cout << "]" << std::endl;

        lex.clean(); // <-- Removes the static instance of the lexer singleton.
    }
    return 0;
}