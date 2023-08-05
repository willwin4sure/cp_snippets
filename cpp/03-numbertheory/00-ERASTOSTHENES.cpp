/*
    ERASTOSTHENES.cpp

    Sieve for generating primes up to `MAX_PR`.
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
constexpr int MAX_PR = 1e7;
std::bitset<MAX_PR> is_prime;

// REMEMBER TO RUN THIS FUNCTION!
void compute_primes() {
    is_prime.set();
    is_prime[0] = false;
    is_prime[1] = false;

    for (int i = 4; i < MAX_PR; i += 2)
        is_prime[i] = false;

    for (int i = 3; i * i < MAX_PR; i += 2)
        if (is_prime[i])
            for (int j = i * i; j < MAX_PR; j += i * 2)
                is_prime[j] = 0;
}
$0
////////// SNIPPET END //////////

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

    Timer t {};
    compute_primes();
    cout << t.elapsed() << nl;

    int num = 0;
    for (int i = 0; i < 1000000; ++i) {
        if (is_prime[i]) ++num;
    }
    assert(num == 78498);
}
