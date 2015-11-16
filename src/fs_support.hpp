#ifndef __FS_SUPPORT_HPP
#define __FS_SUPPORT_HPP

#include <string>
#include <vector>

#include <sys/types.h>
#include <dirent.h>

bool is_directory(const std::string& file_name)
{
    auto dir = opendir(file_name.c_str());
    if (not dir) return false;
    closedir(dir);
    return true;
}

std::vector< std::string > list_directory(const std::string& file_name)
{
    std::vector< std::string > res;
    DIR* dir;
    struct dirent *ent;

    dir = opendir(file_name.c_str());
    if (not dir) return res;
    while ((ent = readdir(dir)) != nullptr)
    {
        res.push_back(ent->d_name);
    }
    closedir(dir);
    return res;
}

#endif
