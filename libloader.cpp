#include "pystr.h"
#include "os.h"
#include <assert.h>

#ifdef _WIN32
    #include <windows.h>
#else
#include <dlfcn.h>

// 获取一个应用程序或动态链接库的模块句柄，返回nullptr->失败
static HMODULE GetModuleHandleA(const char* filename){
    if (!filename) {
        return NULL;
    }
    if (PathIsRelativeA(filename)
        && 0 == strcmp(PathFindFileNameA(filename), PathFindFileNameA(_filename))) {
        return _hmod;
    }

    typedef HMODULE (*F)(const char*);
    F f = (F)GetProcAddress(_manager, "unixFindModule");

    return f ? f(filename) : NULL;
}

// 通过HMODULE句柄获取模块的物理路径(lib/exe)
void GetModuleFileNameA(HMODULE hmod, char* filename, int size){
    *filename = 0;
    if (!hmod) {
        size_t bytes = readlink("/proc/self/exe", filename, size);
        if (bytes > 0)
            filename[bytes < size - 1 ? bytes : size - 1] = '\0';
    }
    else {
        typedef bool (*F)(char*, int);
        F f = (F)GetProcAddress(hmod, "_getdlname");
        if (f) f(filename, size);
    }
}

// 通过HMODULE句柄获取函数指针（句柄）
static void* GetProcAddress(HMODULE hmod, const char* name){
    void* sym = NULL;
    if (hmod) {
        sym = dlsym(hmod, name);
        seterr(dlerror());
    }
    return sym;
}
#endif  // _WIN32

namespace sys{

HMODULE LoadLibrary(const char* path_module){
    string path_abs(path_module);
    if (!osp::isabs(path_abs)){
        path_abs = osp::abspath(path_abs, os::getcwd());
    }
    debug(">> path_abs = %s", path_abs);

#ifdef _WIN32
    HMODULE hModule = ::LoadLibraryExA(path_module, NULL, LOAD_WITH_ALTERED_SEARCH_PATH);
#else
    HMODULE hModule = dlopen(path_module, RTLD_LAZY);
    seterr(dlerror());
#endif  // _WIN32

    return hModule;
}

bool FreeLibrary(HMODULE hModule){
    // 执行模块的析构函数

    // 系统资源释放
#ifdef _WIN32
    return ::FreeLibrary(hModule);
#else
    int ret = hModule ? dlclose(hModule) : 0;
    seterr(dlerror());
    return 0 == ret;
#endif  // _WIN32
}

static PROC GetProcFromDll(HMODULE hModule, const char* proc_name){
    return GetProcAddress(hModule, proc_name);
}

}  // namespace sys
