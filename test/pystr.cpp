// g++ test/pystr.cpp pystring/pystring.cpp fmt/format.cc --std=c++11

#include "pystr.h"
#include "os.h"

int main(){
    // 字符串函数
    auto sentence = "ahtsahiotesn";  // char*
    auto tpl = "ahts";
    auto boolean = startswith(sentence, tpl);
    if(boolean){
        auto idx = index(strfmt("1234{}", sentence), tpl);
        cout << "Index of 'ahts' in string: " << idx << endl;
    }

    // 字符串拼接
    auto str_cat = str("abc") + str("234");
    print("字符串拼接: %s", str_cat.c_str());

    // 格式化
    auto str = strfmt("{0} is {1}", "ahts", 12);  // std::string
    print("String format test: %s", str.c_str());

    // 关于path路径
    auto str_path = osp::join("D:/workspace", "dir/readme.txt");
    print(">> join path: %s", str_path.c_str());
    cout << ">> basename: " << osp::basename(str_path) << endl;

    // 工作路径
    auto currdir = os::getcwd();
    cout << ">> currdir: " << currdir << endl;

    // 文件列表
    auto vec_files = os::listdir(currdir);
    for(auto path_file: vec_files){
        cout << path_file << endl;
    }

    // 文件IO
    string path_file = "./.gitignore";
    if(!osp::isabs(path_file)){
        debug("转换为绝对路径");
        path_file = osp::abspath(path_file, currdir);
        cout << ">> abspath: " << path_file << endl;
    }
    cout << strfmt("文件IO: file [{}] {} exist.", path_file, os::exists(path_file)) << endl;
}
