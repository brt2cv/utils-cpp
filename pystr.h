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
#include <stdarg.h>

// #define print(...) printf(__VA_ARGS__);printf("\n")
#define print(fmt, ...) printf(fmt"\n", ##__VA_ARGS__)
#define debug(fmt, ...) printf("[DEBUG] " __FILE__"::%s:%d --> " fmt"\n", __FUNCTION__, __LINE__ , ##__VA_ARGS__)

void println(const char *format, ...)
{
    // printf("%s %s ", __DATE__, __TIME__);
    va_list args;
    va_start(args, format);  // 使args指向可变参数的第一个参数
    vprintf(format, args);  // 必须用vprintf等带v的
    va_end(args);  // 结束可变参数的获取
    printf("\n");
}

#endif  // __UTILS_STRING__
