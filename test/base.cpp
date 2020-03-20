#include "../base.h"
#include "../pystr.h"

class Test2{};

int main(){
    string check_var("ahts");
    print(var_name(check_var));
    print(var_type(check_var));
    print(var_name(Test2));  // Test2
    auto instance = new Test2();
    print(var_type(instance));
}
