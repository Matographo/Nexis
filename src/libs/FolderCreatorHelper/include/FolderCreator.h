#ifndef FOLODER_CREATOR_H
#define FOLODER_CREATOR_H

#include <string>
#include <vector>
#include <fstream>
#include <sys/stat.h>    // Für mkdir auf POSIX
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_set>

// Für plattformübergreifendes mkdir
#ifdef _WIN32
    #include <direct.h>
    #define mkdir(path, mode) _mkdir(path)
#else
    #include <sys/types.h>
    #include <sys/stat.h>
#endif

class FolderCreator {
    private:
        std::string basePath;
        std::vector<std::string> paths;
        
        void sortPaths();
        int countSlashes(const std::string &path);
        std::string getParentPath(const std::string &path);
        void insertAll(std::vector<std::string> toAdd);
    public:
        FolderCreator(std::string basePath);
        FolderCreator(std::string basePath, std::vector<std::string> paths);
        FolderCreator(std::string basePath, std::string projectName);
        FolderCreator(std::string basePath, std::string projectName, std::vector<std::string> paths);
        ~FolderCreator();
        void add(std::string path);
        void add(std::vector<std::string> paths);
        void create();
        void createAll();
};

#endif