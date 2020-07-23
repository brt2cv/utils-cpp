#include "utils.h"

#include "pybind11/embed.h"
namespace py = pybind11;
using namespace pybind11::literals;

py::scoped_interpreter guard{};

class PythonInterpreter{
public:
    PythonInterpreter(string dir_packages=""){
        this->syspath_append(dir_packages);
    }
    ~PythonInterpreter(){}

    void syspath_append(string path_dir){
        if(path_dir.empty()){
            return;
        }

        auto kwargs = py::dict("name"_a=path_dir);
        py::exec(R"(
import sys
if '{name}' not in sys.path:
    sys.path.append('{name}')
)"_s.format(**kwargs)
        );
    }

    py::module import_module(string path_module, string path_dir=""){
        this->syspath_append(path_dir);
        auto module = py::module::import(path_module.c_str());
        return module;
    }

    void call_func(py::module module, string func_name){
        auto func = module.attr((const char*)func_name.c_str());
        // 执行python函数
        auto ret = func();
        // 转换python对象
        auto str_ret = ret.cast<std::string>();
        print(str_ret);
    }

    void call_func(py::module module, string func_name, Vector<const char*> args){
        auto func = module.attr((const char*)func_name.c_str());
        auto ret = func(args[0], args[1]);
        // 解析dict...
        print(">> Return a py::dict: ", Var_type(ret));
    }
};

int main(){
    auto python = PythonInterpreter();
    auto module = python.import_module("pybind11_demo", "test");
    python.call_func(module, "get_demo_value");

    Vector<const char*> args{"test/json_demo.json", "hello"};
    python.call_func(module, "get_json_value", args);

    // 手动传参
    auto func = module.attr("get_json_value_recursed");
    py::list list_args;
    list_args.append("hello");
    list_args.append("world");
    auto ret = func("test/json_demo.json", list_args);
    print(">> Return by get_json_value_recursed(): ", ret.cast<string>());
}
