#ifndef __UTILS_BASE__
#define __UTILS_BASE__

// #define NDEBUG
#include <assert.h>

// #include <typeinfo>
#define var_name(x) #x
// cout << var_name(aInt) << endl; // 输出: aInt
#define var_type(x) typeid(x).name()

#endif  // __UTILS_BASE__
