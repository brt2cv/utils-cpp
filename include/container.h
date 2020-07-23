#ifndef __UTILS_CONTAINER__
#define __UTILS_CONTAINER__

// #define IN(item,collection) (collection.find(item) != collection.end())
// #define set_add(va_set,item)
// #define data_append(va_list,item) va_list.push_back(item)
// #define data_pop(va_list) va_list.pop_back()

/*-----------------------------------------------------------------*\
    Array
\*-----------------------------------------------------------------*/
#include <array>
#include <vector>

template <typename Arg1, int size>
using Array = std::array<Arg1, size>;

template <typename Args>
using Vector = std::vector<Args>;

/**
 * @brief 匹配Golang标准库: 适用于Vector的push_back
 *
 * @tparam T
 * @param va_vector
 * @param item
 */
template <typename T>
void append(std::vector<T> va_vector, T item){
    va_vector.push_back(item);
}

/**
 * @brief alias for vector.pop_back()
 *
 * @tparam T
 * @param va_list
 */
template <typename T>
void pop(std::vector<T> va_list){
    va_list.pop_back();
}

/**
 * @brief 匹配Python语法: 判断元素的存在性
 *
 * @tparam T
 * @param target
 * @param va_list
 * @return true
 * @return false
 */
template <typename T>
bool in_vector(T target, std::vector<T> va_list){
    // for(auto iter=va_list.begin(), iter != va_list.end(), iter++){
    //     if(*iter == item)
    for(auto item: va_list){
        if(item == target)  return true;
    }
    return false;
}

template <typename T>
int list_index(std::vector<T> va_list, T target){
    int index = 0;
    bool hasItem = false;
    auto iter = va_list.begin();
    while(iter != va_list.end()){
        if(*iter == target){
            hasItem = true;
            break;
        }
        index += 1;
        iter++;
    }
    if(hasItem)  return index;
    else  return -1;
}

/*-----------------------------------------------------------------*\
    List
\*-----------------------------------------------------------------*/
#include <list>

template <typename Args>
using List = std::list<Args>;

template <typename T>
void list_append(std::list<T> va_list, T item){
    va_list.push_back(item);
}

template <typename T>
void list_pop(std::list<T> va_list){
    va_list.pop_back();
}

template <typename T>
bool in_list(T target, std::list<T> va_list){
    for(auto item: va_list){
        if(item == target)  return true;
    }
    return false;
}

template <typename T>
int list_index(std::list<T> va_list, T target){
    int index = 0;
    bool hasItem = false;
    auto iter = va_list.begin();
    while(iter != va_list.end()){
        if(*iter == target){
            hasItem = true;
            break;
        }
        index += 1;
        iter++;
    }
    if(hasItem)  return index;
    else  return -1;
}

/*-----------------------------------------------------------------*\
    Pair
\*-----------------------------------------------------------------*/
#include <utility>

template <typename Arg1, typename Arg2>
using Pair = std::pair<Arg1, Arg2>;
using std::make_pair;

#define Key first
#define Value second

/*-----------------------------------------------------------------*\
    Tuple
\*-----------------------------------------------------------------*/
#include <tuple>

template <typename Args>
using Tuple = std::tuple<Args>;

using std::make_tuple;
using std::tie;  // tuple::tie()
using std::tuple_size;
using std::get;  // array::get(), tuple::get(), pair::get()
using std::swap;  // array, string, forward_list, tuple, ...
using std::tuple_cat;
// extern variant tuple_index(tuple, index);
// extern variant tuple_at(tuple, index);  // same to tuple_index
// extern int tuple_len(tuple);

#ifdef __STD_CPP17__

// 运行期索引（使用变量索引tuple元素）
#include <variant>

template <size_t n, typename... T>
constexpr std::variant<T...> _tuple_index(const std::tuple<T...>& tpl, size_t i) {
    if constexpr (n >= sizeof...(T))
        throw std::out_of_range("越界.");
    if (i == n)
        return std::variant<T...>{ std::in_place_index<n>, std::get<n>(tpl) };
    return _tuple_index<(n < sizeof...(T)-1 ? n+1 : 0)>(tpl, i);
}

template <typename... T>
constexpr std::variant<T...> tuple_at(const std::tuple<T...>& tpl, size_t i) {
    return _tuple_index<0>(tpl, i);
}

template <typename T0, typename ... Ts>
std::ostream & operator<< (std::ostream & s, std::variant<T0, Ts...> const & v) {
    std::visit([&](auto && x){ s << x;}, v);
    return s;
}

// So, we can...
// int i = 1;
// std::cout << tuple_index(t, i) << std::endl;

// 元祖遍历
template <typename T>
auto len_tuple(T &tpl) {
    return std::tuple_size<T>::value;
}

// for(int i = 0; i != tuple_len(new_tuple); ++i)
//     std::cout << tuple_index(new_tuple, i) << std::endl;

template <typename T>
bool in_tuple(T target, std::list<T> va_list){
    for(int i = 0; i != tuple_len(va_list); ++i){
        if(target == tuple_index(va_list, i))  return true;
    }
    return false;
}

#endif  // __STD_CPP17__

/*-----------------------------------------------------------------*\
    Sets / Multiset
\*-----------------------------------------------------------------*/
#include <set>

template <typename Args>
using OrderedSet = std::set<Args>;

template <typename Args>
using OrderedMultiset = std::multiset<Args>;

#include <unordered_set>

template<
    class Key,
    class Hash = std::hash<Key>,
    class KeyEqual = std::equal_to<Key>,
    class Allocator = std::allocator<Key>
>
using Set = std::unordered_set<Key, Hash, KeyEqual, Allocator>;

template<
    class Key,
    class Hash = std::hash<Key>,
    class KeyEqual = std::equal_to<Key>,
    class Allocator = std::allocator<Key>
>
using Multiset = std::unordered_multiset<Key, Hash, KeyEqual, Allocator>;

#define in_set(item,set) (set.find(item) != set.end())
#define set_add(set,item) set.insert(item)
#define set_remove(set,item) set.erase(item)

/*-----------------------------------------------------------------*\
    Dict / Multimap
\*-----------------------------------------------------------------*/
#include <map>

template <typename Arg1, typename Arg2>
using OrderedDict = std::map<Arg1, Arg2>;

template <typename Arg1, typename Arg2>
using OrderedMultimap = std::multimap<Arg1, Arg2>;

#include <unordered_map>

template<
    class Key,
    class T,
    class Hash = std::hash<Key>,
    class KeyEqual = std::equal_to<Key>,
    class Allocator = std::allocator< std::pair<const Key, T> >
>
using Dict = std::unordered_map<Key, T, Hash, KeyEqual, Allocator>;

template<
    class Key,
    class T,
    class Hash = std::hash<Key>,
    class KeyEqual = std::equal_to<Key>,
    class Allocator = std::allocator< std::pair<const Key, T> >
>
using Multimap = std::unordered_multimap<Key, T, Hash, KeyEqual, Allocator>;

/*
template <typename Arg1, typename Arg2>
bool in_dict(Arg1 map_key, std::map<Arg1, Arg2> d){
    // return 1 == d.count(map_key);
    return d.find(map_key) != d.end();
} */
#define in_dict(item,dict) (dict.find(item) != dict.end())

/*-----------------------------------------------------------------*\
    Queue
\*-----------------------------------------------------------------*/
#include <queue>

template <typename Args>
using Queue = std::queue<Args>;

/* A priority queue is a container that provides constant time extraction of the largest element.
   In a priority queue, an element with high priority is served before an element with low priority.
   All insertion / deletion operations takes place in Logarithmic time. */

template <typename Args>
using PriorityQueue = std::priority_queue<Args>;

/*-----------------------------------------------------------------*\
    Stack
\*-----------------------------------------------------------------*/
#include <stack>

template <typename Args>
using Stack = std::stack<Args>;

/*-----------------------------------------------------------------*\
    Bitsets
\*-----------------------------------------------------------------*/

#endif  // __UTILS_CONTAINER__
