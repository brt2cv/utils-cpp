#include "../pystr.h"
#include "../stl2.h"

void test_array(){
    debug();

    Array<int> array{1,2,3,4};
    array.pop_back();
    array.push_back(5);
    for(auto &i: array){
        print("%d", i*2);
    }
}

void test_pair(){
    debug();

    Pair<int, const char*> x(502, "胶水");
    println(">> %d - %s", x._key, x._value);
}

void test_dict(){
    debug();

    Dict<int, float> dict;
    // Map<int, float> dict;
    for(auto i=0; i<5; i++){
        // dict.insert(make_pair(i, i*3.14));
        dict[i] = i*3.14;
    }
    for(auto it = dict.begin(); it != dict.end(); it++){  // std::map<char,int>::iterator
        print("%d : %f", it->_key, it->_value);
    }
}

void test_list(){
    debug();

    List<int> list{1,2,3,4};
    list.pop_back();
    list.push_back(5);
    list.remove(2);
    for(auto &i: list){
        print("%d", i*2);
    }
}

int main(){
    test_array();
    test_list();
    test_pair();
    test_dict();
}
