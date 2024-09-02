#include "DependencieDownloader.h"

bool downloadDependencieWithGit(std::string owner, std::string repo, std::string path) {
    static const std::string command = "git clone https://github.com/" + owner + "/" + repo + " " + path;
    std::cout << command << std::endl;
    return system(command.c_str()) == 0;
}
bool downloadDependencie(std::string url, std::string path) {
    return false;
}