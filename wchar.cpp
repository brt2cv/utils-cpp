#include "wchar.h"
#include <stdlib.h>

int WideCharToMultiByte(int /*codepage*/, DWORD /*flags*/,
                        const wchar_t* wstr, int wchars,
                        char* astr, int achars,
                        const char*, void*){
    return (int)(astr ? wcstombs(astr, wstr, achars) : (wchars * sizeof(char)));
}

int MultiByteToWideChar(int /*codepage*/, DWORD /*flags*/,
                        const char* astr, int achars,
                        wchar_t* wstr, int wchars){
    return wstr ? (int)mbstowcs(wstr, astr, wchars) : achars;
}
