#include <stdarg.h>
#include <stdio.h>

void println(const char *format, ...){
    // printf("%s %s ", __DATE__, __TIME__);
    va_list args;
    va_start(args, format);  // 使args指向可变参数的第一个参数
    vprintf(format, args);  // 必须用vprintf等带v的
    va_end(args);  // 结束可变参数的获取
    printf("\n");
}
