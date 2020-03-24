#ifndef __UTILS_CONTAINER__
#define __UTILS_CONTAINER__

#define IN(item,collection) (collection.find(item) != collection.end())

/*-----------------------------------------------------------------*\
    Array
\*-----------------------------------------------------------------*/
#include <vector>

template <typename Args>
using Array = std::vector<Args>;

template <typename Args>
using Vector = std::vector<Args>;

/*-----------------------------------------------------------------*\
    List
\*-----------------------------------------------------------------*/
#include <list>

template <typename Args>
using List = std::list<Args>;

/*-----------------------------------------------------------------*\
    Pair
\*-----------------------------------------------------------------*/
#include <utility>

template <typename Arg1, typename Arg2>
using Pair = std::pair<Arg1, Arg2>;
using std::make_pair;

#define _key first
#define _value second

/*-----------------------------------------------------------------*\
    Tuple
\*-----------------------------------------------------------------*/
#include <tuple>

template <typename Args>
using Tuple = std::tuple<Args>;

/*-----------------------------------------------------------------*\
    Sets / Multiset
\*-----------------------------------------------------------------*/
#include <set>

template <typename Args>
using Set = std::set<Args>;

template <typename Args>
using Multiset = std::multiset<Args>;

/*-----------------------------------------------------------------*\
    Dict / Multimap
\*-----------------------------------------------------------------*/
#include <map>

template <typename Arg1, typename Arg2>
using Dict = std::map<Arg1, Arg2>;

template <typename Arg1, typename Arg2>
using Map = std::map<Arg1, Arg2>;

template <typename Arg1, typename Arg2>
using Multimap = std::multimap<Arg1, Arg2>;

template <typename Arg1, typename Arg2>
bool in_dict(Arg1 map_key, std::map<Arg1, Arg2> d){
    // return 1 == d.count(map_key);
    return d.find(map_key) != d.end();
}

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
