#include "libloader.h"
#include "utils.h"

#ifdef _WIN32
    #include <windows.h>
#else
#include <dlfcn.h>
/*
// 获取一个应用程序或动态链接库的模块句柄，失败则返回nullptr
static HMODULE__ GetModuleHandleA(const char* filename){
    if (!filename) {
        return NULL;
    }
    if (PathIsRelativeA(filename)
        && 0 == strcmp(PathFindFileNameA(filename), PathFindFileNameA(_filename))) {
        return _hmod;
    }

    typedef HMODULE__ (*F)(const char*);
    F f = (F)GetProcAddress(_manager, "unixFindModule");

    return f ? f(filename) : NULL;
}

// 通过HMODULE句柄获取模块的物理路径(lib/exe)
void GetModuleFileNameA(HMODULE__ hmod, char* filename, int size){
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
*/

static inline void _except(const char* err){
    if(err){
        debug << "module载入失败: " << err << endl;
        exit(1);
    }
    assert(err == nullptr);
}

// 通过HMODULE句柄获取函数指针（句柄）
static void* GetProcAddress(HMODULE__ hmod, const char* name){
    void* sym = NULL;
    if (hmod) {
        sym = dlsym(hmod, name);
        _except(dlerror());
    }
    return sym;
}
#endif  // _WIN32

namespace sys{

HMODULE__ x4LoadLibrary(const char* path_module){
    string path_abs(path_module);
    if (!osp::isabs(path_abs)){
        path_abs = osp::abspath(path_abs, os::getcwd());
    }
    debug << ">> path_abs = " << path_abs << endl;
    assert(os::exists(path_abs));
    debug << "Find plugin.dll file" << endl;

#ifdef _WIN32
    HMODULE__ hModule = ::LoadLibraryExA(path_module, NULL, LOAD_WITH_ALTERED_SEARCH_PATH);
    debug << var_name(hModule) << ": " << var_type(hModule) << endl;

#else
    HMODULE__ hModule = dlopen(path_module, RTLD_LAZY);
    _except(dlerror());
#endif  // _WIN32

    return hModule;
}

bool x4FreeLibrary(HMODULE__ hModule){
    // 执行模块的析构函数

    // 系统资源释放
#ifdef _WIN32
    return ::FreeLibrary((HMODULE)hModule);
#else
    int ret = hModule ? dlclose(hModule) : 0;
    _except(dlerror());
    return 0 == ret;
#endif  // _WIN32
}

PROC__ x4GetProcFromDll(HMODULE__ hModule, const char* proc_name){
#ifdef _WIN32
    return (PROC__)GetProcAddress((HMODULE)hModule, proc_name);
#else
    return (PROC__)GetProcAddress(hModule, proc_name);
#endif
}

}  // namespace sys
