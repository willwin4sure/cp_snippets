/*
    GOSPERHACK.cpp

    Iterates through all subsets of size `k` from `n` elements using bitmasks in increasing order.
*/

#define $0 ;

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
