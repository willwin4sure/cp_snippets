/*
    SAFEMAP.cpp

    Hash map data structure safe from hacking due to randomization to prevent forced collisions.
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

class Timer {
private:
    using Clock = std::chrono::steady_clock;
    using Second = std::chrono::duration<double, std::ratio<1>>;

    std::chrono::time_point<Clock> m_beg { Clock::now() };

public:
    void reset() {
        m_beg = Clock::now();
    }

    double elapsed() const {
        return std::chrono::duration_cast<Second>(Clock::now() - m_beg).count();
    }
};

////////// SNIPPET BEGIN //////////
// https://codeforces.com/blog/entry/62393
struct custom_hash {
    static std::uint64_t splitmix64(std::uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    std::size_t operator()(std::uint64_t x) const {
        static const std::uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template <typename T>
using safe_umap = unordered_map<long long, T, custom_hash>;

template <typename T>
using safe_gp_hash = gp_hash_table<long long, T, custom_hash>;
$0
////////// SNIPPET END //////////

constexpr int N = 1e6;

template <typename T>
void insert_numbers(long long x, T mp) {
    Timer t {};

    for (int i = 0; i < N; ++i) {
        mp[i*x] = 1;
    }

    long long sum = 0;
    for (auto& entry : mp) {
        sum += (entry.first / x) * entry.second;
    }
    
    cout << x << ' ' << sum << " took " << t.elapsed() << " seconds.\n";
}

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

    Timer t {};

    unordered_map <long long, int> umap;
    gp_hash_table <long long, int> gp_hash;
    safe_umap<int> s_umap;
    safe_gp_hash<int> s_gp_hash;

    // bruh I can't even blow up the unordered_map. halp.
    // can only break it in cf custom invocation G++17

    insert_numbers(107897, umap);
    insert_numbers(126279, umap);
    insert_numbers(6442450933, umap);
    insert_numbers(8589934583, umap);
    insert_numbers(12884901857, umap);
    insert_numbers(17179869143, umap);
    insert_numbers(25769803693, umap);
    insert_numbers(34359738337, umap);
    insert_numbers(51539607367, umap);
    insert_numbers(68719476731, umap);
    insert_numbers(103079215087, umap);
    insert_numbers(137438953447, umap);
    
    cout << t.elapsed() << nl;
}
