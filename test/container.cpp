#include "utils.h"

#define isEmpty empty
#define append push_back
#define pop pop_back
#define remove_ erase
#define add insert

void test_vector(){
    debug << endl;

    Vector<int> vector{1,2,3,4};
    // vector.pop_back();
    list_pop(vector);
    // vector.push_back(5);
    list_append(vector, 5);
    for(auto &i: vector){
        print(i*2);
    }

    auto item = 3;
    string is_in;
    if(in_list(3, vector))  is_in = "is";
    else  is_in = "is not";
    print(strfmt("Item 【{}】 {} in collection.", item, is_in));
    print(strfmt("Item 【{}】 index is {}.", item, list_index(vector, item)));
}

void test_list(){
    debug << endl;

    List<int> list{1,2,3,4};
    list.pop_back();
    // list.push_back(5);
    list_append(list, 5);
    list.remove(2);
    for(auto &i: list){
        print(i*2);
    }
}

void test_tuple(){
    debug << endl;

    auto tuple = make_tuple("Jenny", false, 18, 168.25);
#ifdef __STD_CPP17__
    print(strfmt("{}的年龄是【{}】，身高【{}】", tuple_index(tuple, 0),
                 tuple_index(tuple, 2), tuple_index(tuple, 3)));
    debug << "遍历Tuple:" << endl;
    for(auto i=0; i != tuple_len(tuple), i++){
        print(i);
    }
#else
    int len_tuple = tuple_size<decltype(tuple)>::value;
    string a; bool b; int c; float d;
    tie(a, b, c, d) = tuple;
    print(strfmt("Tuple对象的长度为【{}】，元素1【{}】，元素2【{}】，元素3【{}】",
                 len_tuple, get<0>(tuple), b, c));
#endif
}

void test_pair(){
    debug << endl;

    Pair<int, const char*> x(502, "胶水");
    println(">> %d - %s", x._key, x._value);
}

void test_set(){
    debug << endl;

    Set<int> set{1,2,3,4};
    debug << "Type of 'Set' is: " << var_type(set) << endl;

    auto item = 9;
    string has_item = "in";
    if(!in_set(item, set))  has_item = "not in";
    print(strfmt("Item 【{}】 is {} set.", item, has_item));

    set_add(set, item);
    for(auto item: set){
        print(item);
    }
}

void test_dict(){
    debug << endl;

    Dict<int, float> dict;
    // Map<int, float> dict;
    for(auto i=0; i<5; i++){
        // dict.insert(make_pair(i, i*3.14));
        dict[i] = i*3.14;
    }
    for(auto it = dict.begin(); it != dict.end(); it++){  // std::map<char,int>::iterator
        print(it->_key, it->_value);
    }

    for(auto item: dict){
        print(item._key, item._value);
    }
}

int main(){
    test_vector();
    test_list();
    test_tuple();
    test_set();
    test_pair();
    test_dict();
}
