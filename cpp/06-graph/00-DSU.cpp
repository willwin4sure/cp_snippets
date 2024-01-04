/*
    DSU.cpp

    Disjoint set union with path compression and union by size.
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
 * Disjoint set union with path compression and union by size.
*/
class DSU {
public:
    DSU(int n) {
        m_parent.resize(n);

        m_size.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            m_parent[i] = i;
        }
    }

    /// Returns the root of the set containing x.
    int find(int x) {
        if (m_parent[x] != x) {
            // Path compression
            m_parent[x] = find(m_parent[x]);
        }
        return m_parent[x];
    }

    /// Unites the sets containing x and y.
    bool unite(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);

        if (root_x == root_y) return false;

        // Union by size
        if (m_size[root_x] < m_size[root_y]) {
            m_parent[root_x] = root_y;
            m_size[root_y] += m_size[root_x];
        } else {
            m_parent[root_y] = root_x;
            m_size[root_x] += m_size[root_y];
        }
        return true;
    }

    /// Returns true if x and y are in the same set.
    bool sameSet(int x, int y) {
        return find(x) == find(y);
    }

    /// Returns the size of the set containing x.
    int getSize(int x) {
        return m_size[find(x)];
    }

private:
    std::vector<int> m_parent;
    std::vector<int> m_size;
};
////////// SNIPPET END //////////

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

    DSU dsu(10);

    dsu.unite(1, 2);
    dsu.unite(3, 4);
    dsu.unite(4, 5);
    dsu.unite(6, 7);
    dsu.unite(8, 9);

    assert(dsu.sameSet(1, 2));
    assert(dsu.sameSet(3, 5));
    assert(!dsu.sameSet(2, 6));
    assert(!dsu.sameSet(4, 8));
    assert(dsu.sameSet(8, 9));

    dsu.unite(1, 3);
    dsu.unite(6, 8);

    assert(dsu.getSize(1) == 5);
    assert(dsu.getSize(6) == 4);
    assert(dsu.getSize(9) == 4);

    dsu.unite(2, 6);
    dsu.unite(1, 7);

    assert(dsu.sameSet(1, 8));
    assert(dsu.getSize(1) == 9);
    assert(dsu.getSize(2) == 9);

    DSU dsu2(5);
    assert(!dsu2.sameSet(1, 2));
    assert(dsu2.getSize(3) == 1);
}
