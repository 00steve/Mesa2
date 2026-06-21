#ifndef UTIL_File
#define UTIL_File

#include <fstream>
#include <iostream>
#include <filesystem>
#include <string>
#include <vector>

class FileUtil{
public:
    static std::vector<std::string> FileList(std::string directory);
    static std::string LoadPlainText(std::string filePath);
};

#endif