/*
    FENWICK.cpp

    Fenwick tree for range sums and point updates.
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
 * Fenwick tree for range sums and point updates. 1-indexed internally.
*/
struct Fenwick {
    int n;
    std::vector<ll> bit;

    Fenwick(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0LL);
    }

    Fenwick(std::vector<ll> a) : Fenwick(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            update(i, a[i]);
    }

    /// Returns the sum of the range [0, idx].
    ll prefix(int idx) {
        ll ret = 0LL;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    /// Returns the sum of the range [l, r].
    ll sum(int l, int r) {
        if (l > r) return 0LL;
        if (l == 0) return prefix(r);
        return prefix(r) - prefix(l - 1);
    }

    /// Adds `delta` to the value at index `idx`.
    void update(int idx, ll delta) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }
};
////////// SNIPPET END //////////

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

    ll n = 1e5;
    Fenwick f(n);
    for (ll i = 0; i < n; ++i) {
        f.update(i, i*i);
    }
    assert(f.sum(2, 4) == 29 && f.prefix(n-1) == ((n-1)*n*(2*n-1))/6);
    f.update(2, 1000);
    assert(f.sum(2, 4) == 1029 && f.sum(1, 2) == 1005);
    f.update(0, 1);
    assert(f.prefix(0) == 1);
    std::cout << "ALL TESTS PASSED\n";
}
