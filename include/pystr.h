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

#define print(...) printf(__VA_ARGS__);printf("\n")
// #define print(fmt, ...) printf(fmt"\n", ##__VA_ARGS__)
#define debug(fmt, ...) printf("[DEBUG] " __FILE__"::%s:%d --> " fmt"\n", __FUNCTION__, __LINE__ , ##__VA_ARGS__)

void println(const char *format, ...);

#endif  // __UTILS_STRING__
