#ifndef __UTILS_BASE__
#define __UTILS_BASE__

// modules
#include "pystr.h"
#include "os.h"
#include "container.h"

// #define NDEBUG
#include <assert.h>
#include <typeinfo>

#define ASSERT(expr, description) \
    if(!(expr)) std::cout<<description<<std::endl; \
    assert(expr);

static inline void assert_(int expression, string description){
    if(!expression){
        std::cout << description << std::endl;
    }
    assert(expression);
}

#define var_name(x) #x
// cout << var_name(aInt) << endl;  // 输出: aInt
#define var_type(x) typeid(x).name()

// Macro-Define
#define pass

/*
// __attribute__
#define OUTAPI extern "C" __attribute__((visibility("default")))

#if defined(__APPLE__)
    #define LOCALAPI
#else
    #define LOCALAPI __attribute__((visibility("hidden")))
#endif

////
#ifdef __GNUC__
    #define OUTAPI extern "C" __attribute__((dllexport))
#else
    #define OUTAPI extern "C" __declspec(dllexport)
#endif  // __GNUC__

#define LOCALAPI
*/

#endif  // __UTILS_BASE__
