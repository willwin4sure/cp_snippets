/*
    FILEIO.cpp

    Allows C++ file I/O by redirecting to standard input and output.
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
////////// SNIPPET BEGIN //////////
std::freopen("$1.in", "r", stdin);
std::freopen("$1.out", "w", stdout);

$0
////////// SNIPPET END //////////
}
