/*
    LINECONTAINER.cpp

    Container to add lines of the form m*x + b, and query maximum y-coordinates at given x.
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
// https://github.com/kth-competitive-programming/kactl/blob/main/content/data-structures/LineContainer.h

struct Line {
    mutable ll m, b, p;
    bool operator<(const Line& o) const { return m < o.m; }
    bool operator<(ll x) const { return p < x; }
};

/**
 * Container to add lines of the form m*x + b, and query maximum y-coordinates at given x.
*/
struct LineContainer : std::multiset<Line, std::less<>> {
    /// For doubles, use INF = 1/.0, div(a,b) = a/b.
    static const ll INF = LLONG_MAX;

    /// Floored division.
    ll div(ll a, ll b) {
        return a / b - ((a ^ b) < 0 && a % b);
    }

    bool isect(iterator x, iterator y) {
        if (y == end()) {
            x->p = INF;
            return false;
        }
        if (x->m == y->m)
            x->p = (x->b > y->b ? INF : -INF);
        else
            x->p = div(y->b - x->b, x->m - y->m);
        return (x->p >= y->p);
    }

    /// Add line m*x + b.
    void add(ll m, ll b) {
        auto z = insert({m, b, 0}), y = z++, x = y;
        while (isect(y, z))
            z = erase(z);
        if (x != begin() && isect(--x, y))
            isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }

    /// Query maximum y-coordinate at given x.
    ll query(ll x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return l.m * x + l.b;
    }
};
$0
////////// SNIPPET END //////////

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

    LineContainer lc {};
    lc.add(1, -5); lc.add(0, -6);
    assert(lc.query(0) == -5 && lc.query(-10) == -6 && lc.query(10) == 5);
    lc.add(-1, -2); lc.add(-3, -15); lc.add(-3, -12);
    assert(lc.query(0) == -2 && lc.query(-6) == 6 && lc.query(-2) == 0 && lc.query(12) == 7);
    std::cout << "ALL TESTS PASSED\n";
}
