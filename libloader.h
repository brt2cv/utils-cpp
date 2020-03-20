#include "typeext.h"

namespace sys{

HMODULE LoadLibrary(const char* path_module);
bool FreeLibrary(HMODULE hModule);

char* GetModuleFileNameA(HMODULE hModule);
HMODULE GetModuleHandleA(const char* path_module);
PROC GetProcAddress(HMODULE hModule, const char* proc_name);

}  // namespace sys
