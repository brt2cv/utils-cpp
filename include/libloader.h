#ifndef __UTILS_LIBLOADER__
#define __UTILS_LIBLOADER__

// #include "typeext.h"
typedef void* HMODULE__;
typedef void* PROC__;

namespace sys{

HMODULE__ LoadLibrary_(const char* path_module);
bool FreeLibrary(HMODULE__ hModule);
PROC__ GetProcFromDll(HMODULE__ hModule, const char* proc_name);

}  // namespace sys

#endif  // __UTILS_LIBLOADER__
