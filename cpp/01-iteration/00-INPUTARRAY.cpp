/*
    INPUTARRAY.cpp

    Reads `n` integers from standard input into a vector named `a`.
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

    int n; cin >> n;
////////// SNIPPET BEGIN //////////
std::vector<int> a(n);
for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
}
$0
////////// SNIPPET END //////////

    for (int i = 0; i < n; ++i) {
        cout << a[i] << nl;
    }
}
