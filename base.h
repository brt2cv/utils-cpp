#ifndef __UTILS_BASE__
#define __UTILS_BASE__

// #define NDEBUG
#include <assert.h>
#include <typeinfo>

#define var_name(x) #x
// cout << var_name(aInt) << endl;  // 输出: aInt
#define var_type(x) typeid(x).name()

// Macro-Define
#define pass

// __attribute__
#define OUTAPI extern "C" __attribute__((visibility("default")))

#if defined(__APPLE__)
#define LOCALAPI
#else
#define LOCALAPI __attribute__((visibility("hidden")))
#endif

#endif  // __UTILS_BASE__
