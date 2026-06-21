#include "../include/fileUtil.h"

std::vector<std::string> FileUtil::FileList(std::string directory){
    std::vector<std::string> files;
    unsigned int directoryStringLength = directory.length();
    for (const auto & entry : std::filesystem::directory_iterator(directory)){
        std::string fPath = entry.path().string();
        std::string fFile = fPath.substr(directoryStringLength,fPath.length()-directoryStringLength);
        //std::cout << " file : " << fFile << std::endl;
        files.push_back(fFile);
    }
    return files;
}

std::string FileUtil::LoadPlainText(std::string filePath){
    std::ifstream ifs(filePath, std::ifstream::in);
    std::string data;
    if(ifs.bad() || ifs.fail()){
        return data;
    }
    char c = ifs.get();
    while (ifs.good()) {
        data += c;
        c = ifs.get();
    }
    ifs.close();
    return data;
}