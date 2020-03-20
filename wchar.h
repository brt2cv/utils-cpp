#include "typeext.h"

int WideCharToMultiByte(int codepage, DWORD flags,
                        const wchar_t* wstr, int wchars,
                        char* astr, int achars,
                        const char* defaultChar, void*);

int MultiByteToWideChar(int codepage, DWORD flags,
                        const char* astr, int achars,
                        wchar_t* wstr, int wchars);
