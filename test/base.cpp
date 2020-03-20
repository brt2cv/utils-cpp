#include "../base.h"
#include "../pystr.h"

class Test2{};

int main(){
    auto check_var = string("ahts");
    print(var_name(check_var));
    print(var_type(check_var));
    print(var_name(Test2));  // Test2
}
