/*
    CF.cpp
    
    C++ template for Codeforces problems.
*/

#define $0 ;
#define $1 ;

////////// SNIPPET BEGIN //////////
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define nl '\n'

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using vi = std::vector<int>;
using pii = std::pair<int, int>;

template <typename T, typename U>
std::istream& operator>>(std::istream& in, std::pair<T, U>& pair) {
    in >> pair.first >> pair.second;
    return in;
}

template <typename T>
std::istream& operator>>(std::istream& in, std::vector<T>& vec) {
    for (T& x : vec) {
        in >> x;
    }
    return in;
}

$1

void solve() {
    $0
}

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    
    int t; std::cin >> t;
    while (t--) {
        solve();
    }
}
////////// SNIPPET END //////////
