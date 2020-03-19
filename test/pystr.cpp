// g++ test/pystr.cpp pystring/pystring.cpp fmt/format.cc --std=c++11

#include "../pystr.h"

int main(){
    auto sentence = "ahtsahiotesn";  // char*
    auto tpl = "ahts";
    auto boolean = startswith(sentence, tpl);
    if(boolean){
        auto idx = index(strfmt("1234{}", sentence), tpl);
        std::cout << "Index of 'ahts' in string: " << idx << std::endl;
    }
    auto str = strfmt("{0} is {1}", "ahts", 12);  // std::string
    print("String format test: %s", str.c_str());
    return 0;
}
