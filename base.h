#ifndef __UTILS_BASE__
#define __UTILS_BASE__

// #define NDEBUG
#include <assert.h>

// #include <typeinfo>
#define var_name(x) #x
// cout << var_name(aInt) << endl; // 输出: aInt
#define var_type(x) typeid(x).name()

// #define print(...) printf(__VA_ARGS__);printf("\n")
#define print(fmt, ...) printf(fmt"\n", ##__VA_ARGS__)
#define debug(fmt, ...) printf("[DEBUG] " __FILE__"::%s:%d --> " fmt"\n", __FUNCTION__, __LINE__ , ##__VA_ARGS__)

#endif  // __UTILS_BASE__
