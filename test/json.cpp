#pragma execution_character_set("utf-8")

#include <fstream>
#include <iomanip>

#include "utils.h"
#include "json.hpp"
using json = nlohmann::json;
using namespace std;

string path_demofile = "test/json_demo.json";

int main(){
    auto struct_json = R"(
    {
        "happy": true,
        "pi": 3.141
    }
    )"_json;

    print(var_type(struct_json));
    // 修改参数
    struct_json["happy"] = false;
    struct_json["pi"] = "哇，可以直接改变类型？动态语法了都……";
    auto str_json = struct_json.dump();
    print(">>> Dump_to_string: ", str_json);

    std::ofstream o("pretty.json");
    o << std::setw(4) << struct_json << std::endl;

    assert_(os::exists(path_demofile), strfmt("不存在文件【{}】", path_demofile))
    std::ifstream i(path_demofile);
    json j;
    i >> j;
    print(">> Load the Json file: ", j.dump());

    print("Well Done.");
}
