/*
    FENWICK.cpp

    Fenwick tree for range sums and point updates.
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
struct Fenwick {
    // 1-indexed internally
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

    // query operations are inclusive
    ll prefix(int idx) {
        ll ret = 0LL;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    ll sum(int l, int r) {
        if (l > r) return 0LL;
        if (l == 0) return prefix(r);
        return prefix(r) - prefix(l - 1);
    }

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
}
