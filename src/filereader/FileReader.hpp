#ifndef FILE_READER_HPP
#define FILE_READER_HPP

#include <iostream>

namespace KiloLang
{
    class FileReader /* Singleton */
    {
        public:
            static FileReader & get();
        private:
            static inline FileReader * instance = nullptr;
        public:
            std::string readFile(std::string & filePath);
            void clean();
            ~FileReader();
        private:
            FileReader();
    };
}

#endif