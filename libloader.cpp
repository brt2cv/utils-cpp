#include "pystr.h"
#include <dlfcn.h>

namespace sys{

// 获取一个应用程序或动态链接库的模块句柄，返回nullptr->失败
HMODULE GetModuleHandleA(const char* path_module){
    assert(false);  // no implement
}

// 通过HMODULE句柄获取模块的物理路径(lib/exe)
char* GetModuleFileNameA(HMODULE hModule){
    assert(false);  // no implement
}

// 通过HMODULE句柄获取函数指针（句柄）
PROC GetProcAddress(HMODULE hModule, const char* proc_name){
    void* sym = NULL;
    if (hModule){
        sym = dlsym(hModule, proc_name);
        seterr(dlerror());
    }
    return sym;
}

HMODULE LoadLibrary(const char* path_module){
    string path_abs(path_module);
    if (!osp::isabs(path_abs)){
        path_abs = osp::abspath(path_abs, os::getcwd());
    }
    debug(">> path_abs = %s", path_abs);

    HMODULE hModule = dlopen(path_module, RTLD_LAZY);
    seterr(dlerror());

    return hModule;
}

bool FreeLibrary(HMODULE hModule){
    // 执行模块的析构函数

    // 系统资源释放
    int ret = hModule ? dlclose(hModule) : 0;
    seterr(dlerror());
    return 0 == ret;
}

}  // namespace sys