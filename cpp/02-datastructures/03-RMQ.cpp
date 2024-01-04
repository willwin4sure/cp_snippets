/*
    RMQ.cpp

    One-dimensional range minimum queries using a sparse table.
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

////////// SNIPPET BEGIN //////////
/**
 * One-dimensional range minimum queries using a sparse table.
*/
template <typename T>
struct RMQ {
    /// jmp[lvl][j] stores the minimum value and index (ties broken leftwards) in [j, j + 2^lvl).
    std::vector<std::vector<std::pair<T, int>>> jmp;
    
    RMQ(const std::vector<T>& V) : jmp(1, std::vector<std::pair<T, int>>(V.size())) {
        for (int i = 0; i < V.size(); ++i) 
            jmp[0][i] = { V[i], i };
        for (int pw = 1, k = 1; pw * 2 <= static_cast<int>(V.size()); pw *= 2, ++k) {
            jmp.emplace_back(static_cast<int>(V.size()) - pw * 2 + 1);
            for (int j = 0; j < jmp[k].size(); ++j) 
                jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
        }
    }

    /// Queries are inclusive over [l, r].
    std::pair<T, int> query(int l, int r) {
        assert (l <= r);
        int lvl = 31 - __builtin_clz(r - l + 1);
        return min(jmp[lvl][l], jmp[lvl][r - (1 << lvl) + 1]);
    }
};
$0
////////// SNIPPET END //////////

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

    std::vector<ll> v { 3, 1, 4, 1, 5, 9, 2, 6, 5 };
    RMQ<ll> rmq(v);
    assert(rmq.query(0, 3) == std::make_pair(1LL, 1) && rmq.query(4, 4) == std::make_pair(5LL, 4) && rmq.query(5, 6) == std::make_pair(2LL, 6));
    assert(rmq.query(0, 0) == std::make_pair(3LL, 0) && rmq.query(1, 3) == std::make_pair(1LL, 1));
    std::cout << "ALL TESTS PASSED\n";
}
