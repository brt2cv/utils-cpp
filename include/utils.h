#ifndef __UTILS_BASE__
#define __UTILS_BASE__

// compiler

#if (__cplusplus > 201402L || defined(_LIBCPP_VERSION)) || \
    (defined(_MSVC_LANG) && _MSVC_LANG > 201402L && _MSC_VER >= 1910)
    #define __STD_CPP17__
#endif

#if (__cplusplus > 201103L) || (defined(_MSVC_LANG) && _MSVC_LANG > 201103L)
    #define __STD_CPP14__
#endif

#if (__cplusplus > 199711L) || (defined(_MSVC_LANG) && _MSVC_LANG > 199711L)
    #define __STD_CPP11__
#endif

// modules
#include "pystr.h"
#include "os.h"
#include "container.h"

// #define NDEBUG
#include <assert.h>
#include <typeinfo>

// #define Assert(expr, description) \
//     if(!(expr)) std::cout<<description<<std::endl; \
//     assert(expr);

// #define TypeOf decltype
// #define VarName(x) #x
// // cout << var_name(aInt) << endl;  // 输出: aInt
// #define VarType(x) typeid(x).name()

#define assert_(expr, description) \
    if(!(expr)) std::cout<<description<<std::endl; \
    assert(expr);

#define typeof_ decltype
#define var_name(x) #x
// cout << var_name(aInt) << endl;  // 输出: aInt
#define var_type(x) typeid(x).name()

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
