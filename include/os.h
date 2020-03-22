#ifndef __UTILS_OS__
#define __UTILS_OS__

#include "pystr.h"
#include <vector>

namespace os{

bool exists(const string& path_file);
string getcwd();
int chdir(const string path);
std::vector<string> listdir(const string dirPath);

}

#endif  // __UTILS_OS__
