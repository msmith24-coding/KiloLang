#include "FileReader.hpp"

#include <fstream>

namespace KiloLang
{
    /**
     * @brief Method to get the FileReader instance.
     * 
     * @details If the static instance is a null pointer, it will create a new instance of
     * FileReader. This method ensures that the FileReader class can be accessed as a Singleton.
     * 
     * @return Reference to FileReader instance.
    */
    FileReader & FileReader::get()
    {
        if(instance == nullptr) {
            instance = new FileReader();
        }

        return *instance;
    }

    /**
     * @brief Reads the content of a file specified by the given file path.
     * 
     * @param filePath - A string containing the path to the file to be read.
     * 
     * @return A string containing the entire content of the file. 
     * If the file fails to open, it displays an error message to 
     * stderr and returns "NULL".
     * 
    */
    std::string FileReader::readFile(std::string & filePath)
    {
        std::ifstream inputFile(filePath);
        if(!inputFile.is_open()) {
            std::cerr << "[ERR] Failed to open provided file." << std::endl;
            return "NULL";
        }

        std::string content;
        std::string line;
        while(getline(inputFile, line)) {
            content += line + "\n";
        }

        inputFile.close();

        return content;
    }

    /**
     * @brief Removes the static instance of this class.
    */
    void FileReader::clean()
    {
        delete instance;
    }

    FileReader::FileReader() = default;
    FileReader::~FileReader() = default;
}