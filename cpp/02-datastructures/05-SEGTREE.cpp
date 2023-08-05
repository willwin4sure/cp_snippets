/*
    SEGTREE.cpp

    Standard segment tree that supports range queries and point setting.
*/

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
template <typename T>
T op(T a, T b) {
    return a + b; /* combine answers (any associative op) */
}

template <typename T>
T e() {
    return 0; /* initial value for queries (e.g. 0 for sum, -inf for max) */
}

template <typename T, T(*op)(T, T), T(*e)()>
struct SegTree {
    // e.g. use SegTree<ll, op, e> tree(a);
    int n;
    std::vector<T> tree;

    SegTree(int n) {
        this->n = n;
        tree.assign(4*n+1, e());
    }

    SegTree(std::vector<T> a) : SegTree(a.size()) {
        build(a, 1, 0, n-1);
    }

    void build(std::vector<T>& a, int idx, int tl, int tr) {
        if (tl > tr) return;
        if (tl == tr) {
            tree[idx] = a[tl];
        } else {
            int tm = (tl+tr)/2;
            build(a, 2*idx, tl, tm);
            build(a, 2*idx+1, tm+1, tr);
            tree[idx] = op(tree[2*idx], tree[2*idx+1]);
        }
    }

    T query(int idx, int tl, int tr, int l, int r) {
        if (l > r) return e();
        if (l == tl && r == tr) return tree[idx];
        int tm = (tl+tr)/2;
        return op(
            query(2*idx, tl, tm, l, min(r, tm)),
            query(2*idx+1, tm+1, tr, max(l, tm+1), r)
        );
    }

    void update(int idx, int tl, int tr, int pos, T new_val) {
        if (tl == tr) {
            tree[idx] = new_val;
        } else{
            int tm = (tl+tr)/2;
            if (pos <= tm)
                update(2*idx, tl, tm, pos, new_val);
            else
                update(2*idx+1, tm+1, tr, pos, new_val);
            tree[idx] = op(tree[2*idx], tree[2*idx+1]);
        }
    }

    T query(int l, int r) {
        // queries are *inclusive* [l,r]
        return query(1, 0, n-1, l, r);
    }

    void update(int pos, T new_val) {
        update(1, 0, n-1, pos, new_val);
    }

    void print() {
        for (T x : tree) cout << x << " ";
        cout << nl;
    }
};
////////// SNIPPET END //////////

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

    std::vector<ll> a { 3, 1, 4, 1, 5, 9, 2 };
    SegTree<ll, op, e> tree(a);
    assert(tree.query(0, 6) == 25);
    tree.update(0, 10);
    assert(tree.query(0, 1) == 11);
    for (int i = 0; i < 7; ++i) {
        tree.update(i, 1);
    }
    assert(tree.query(2, 4) == 3);
}
