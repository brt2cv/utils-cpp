#ifndef __UTILS_LIBLOADER__
#define __UTILS_LIBLOADER__

// #include "typeext.h"
typedef void* HMODULE__;
typedef void* PROC__;

namespace sys{

HMODULE__ x4LoadLibrary(const char* path_module);
bool x4FreeLibrary(HMODULE__ hModule);
PROC__ x4GetProcFromDll(HMODULE__ hModule, const char* proc_name);

}  // namespace sys

#endif  // __UTILS_LIBLOADER__
