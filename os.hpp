#ifndef __UTILS_OS__
#define __UTILS_OS__

#include "pystr.h"
// #include "pystring/pystring.h"
#ifdef WINDOWS
    #include <io.h>
    #include <direct.h>
#else
    #include <unistd.h>
#endif

// #include <filesystem>
#include <dirent.h>
#include <vector>


namespace os{
// using std::filesystem;  // g++ 7.4 尚不支持
// bool exists(const path& pval);

bool exists(const str& path_file){
    #ifdef WINDOWS
        return !_access(path_file.c_str(), 0);
    #else
        return !access(path_file.c_str(), F_OK);
    #endif
}

string getcwd(){
    char* currdir = ::getcwd(nullptr, 0);
    string currdir_(currdir);
    free(currdir);
    return currdir_;
}

int chdir(const string path){
    return ::chdir(path.c_str());
}

// void _listdir(string path_dir, std::vector<string>& files){
//     intptr_t hFile = 0;
//     _finddata_t fileinfo;
//     if ((hFile = _findfirst(path_dir.append("/*").c_str(), &fileinfo)) != -1) {
//         while (_findnext(hFile, &fileinfo) == 0) {
//             if (strcmp(fileinfo.name, ".."))
//                 files.push_back(fileinfo.name);
//         }
//         _findclose(hFile);
//     }
// }

// std::vector<string> listdir(string path_dir){
//     std::vector<string> vec_files;
//     _listdir(path_dir, vec_files);
//     return vec_files;
// }

std::vector<string> listdir(const string dirPath)
{
    std::vector<string> filesNameList;
    DIR *dir = opendir(dirPath.c_str());
    dirent *entry = NULL;
    while((entry = readdir(dir)) != NULL)
    {
        if(!strcmp(entry->d_name,".") || !strcmp(entry->d_name,".."))  continue;
        string pathFile = osp::join(dirPath, entry->d_name);
        filesNameList.push_back(pathFile);
    }
    closedir(dir);
    return filesNameList;
}

}  // namespace os

#endif  // __UTILS_OS__
