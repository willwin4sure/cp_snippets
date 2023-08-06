/*
    PAIRIO.cpp

    Overloads istream operator for pair.
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
template <typename T, typename U>
std::istream& operator>>(std::istream& in, std::pair<T, U>& pair) {
    in >> pair.first >> pair.second;
    return in;
}
$0
////////// SNIPPET END //////////

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

    pii x; cin >> x;
    cout << x.first << ' ' << x.second << nl;
}
