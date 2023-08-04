/*
    INDEXEDSET.cpp

    Augmented set with support for finding n-th element, or the index of an element.
*/

#define $0 ;

#include <iostream>
#include <cstdio>
#include <cassert>
#include <chrono>
#include <random>
#include <cstdint>
#include <string>
#include <array>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <numeric>
#include <utility>
#include <algorithm>
#include <bitset>
#include <cmath>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define nl '\n'

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using vi = std::vector<int>;
using pii = std::pair<int, int>;

////////// SNIPPET BEGIN //////////
// operations: insert, erase (takes a pointer), find, find_by_order (returns a pointer), order_of_key
template <typename T>
using indexed_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
// use pair<int, int> with indices as second for multiset

template <typename T, typename U>
using indexed_map = __gnu_pbds::tree<T, U, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
$0
////////// SNIPPET END //////////

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

    indexed_set<int> s, s2; s.insert(8);
    auto it = s.insert(10).first; assert(it == s.lower_bound(9));
    assert(s.order_of_key(10) == 1 && s.order_of_key(11) == 2 && *s.find_by_order(0) == 8);
    s2.insert(12); s.join(s2); // only works if s < s2 or s > s2 entirely
    for (int x : s) cout << x << nl;

    indexed_map<int, int> m;
    m[10] = 2;
    assert(m.lower_bound(9)->first == 10 && m.lower_bound(9)->second == 2);
}
