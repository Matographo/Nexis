#include <string>
#include <iostream>

#ifndef DEPENDENCIEDOWNLOADER_H
#define DEPENDENCIEDOWNLOADER_H


bool downloadDependencieWithGit(std::string owner, std::string repo, std::string path);

bool downloadDependencie(std::string url, std::string path);





#endif