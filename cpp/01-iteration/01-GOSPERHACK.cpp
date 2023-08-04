/*
    GOSPERHACK.cpp

    Iterates through all subsets of size `k` from `n` elements using bitmasks in increasing order.
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


int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

    int n, k; cin >> n >> k;
////////// SNIPPET BEGIN //////////
// http://programmingforinsomniacs.blogspot.com/2018/03/gospers-hack-explained.html
int set = (1 << k) - 1;
int limit = (1 << n);
while (set < limit) {
    // use the subset
    $0

    int c = set & -set;
    int r = set + c;
    set = (((r ^ set) >> 2) / c) | r;
}
////////// SNIPPET END //////////
}
