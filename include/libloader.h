#ifndef __UTILS_LIBLOADER__
#define __UTILS_LIBLOADER__

#include "typeext.h"

namespace sys{

HMODULE LoadLibrary(const char* path_module);
bool FreeLibrary(HMODULE hModule);
PROC GetProcFromDll(HMODULE hModule, const char* proc_name);

}  // namespace sys

#endif  // __UTILS_LIBLOADER__
