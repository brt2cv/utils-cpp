#ifndef __UTILS_STRING__
#define __UTILS_STRING__

#include <string.h>
#include <string>
using std::string;
using str = std::string;

/*-----------------------------------------------------------------*\
    PyString
\*-----------------------------------------------------------------*/
#include "pystring/pystring.h"
using namespace pystring;

/*-----------------------------------------------------------------*\
    Fmtlib
\*-----------------------------------------------------------------*/
#include "fmt/format.h"
// using namespace fmt;
#define strfmt fmt::format

/*-----------------------------------------------------------------*\
    iostream
\*-----------------------------------------------------------------*/
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

/*-----------------------------------------------------------------*\
    println
\*-----------------------------------------------------------------*/

void println(const char *format, ...);

template<typename T>
void print(T arg){
    std::cout << arg << std::endl;
}

template<typename T, typename... Ts>
void print(T arg1, Ts... arg_left){
    std::cout << arg1 << " ";
    print(arg_left...);
}

// #define print(...) printf(##__VA_ARGS__);printf("\n")
#define prfmt(fmt, ...) printf(fmt"\n", ##__VA_ARGS__)
// #define debug(...) printf("[DEBUG] " __FILE__"::%s:%d --> " , __FUNCTION__, __LINE__);print(__VA_ARGS__)
#define debug std::cout<<"[DEBUG] "<<__FILE__<<"::"<<__FUNCTION__<<":"<<__LINE__<<" "
// Usage: debug << var << endl;
#define dbgfmt(fmt, ...) printf("[DEBUG] " __FILE__"::%s:%d --> " fmt"\n", __FUNCTION__, __LINE__ , ##__VA_ARGS__)

#endif  // __UTILS_STRING__
