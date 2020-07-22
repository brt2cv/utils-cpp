#include "utils.h"

class Test2{};

int main(){
    std::string check_var("This is a test");
    print(Var_name(check_var));
    print(Var_type(check_var));
    print(Var_name(Test2));  // Test2
    auto instance = new Test2();
    print(Var_type(instance));
}
