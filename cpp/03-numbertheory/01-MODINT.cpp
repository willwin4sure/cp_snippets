/*
    MODINT.cpp

    Allows easy integer modular arithmetic, modulo a constant prime.
*/

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
 * Allows easy integer modular arithmetic, modulo a constant prime.
*/
template <ll N>
struct ModInt {
    ll value;

    ModInt(const ll x = 0) : value { x % N } {
        if (value < 0) value += N;
    }
    ModInt(const ll n, const ll d) : value { 0 } {
        *this += n; *this /= d;
    }

    ModInt operator+(const ModInt& other) const noexcept { return ModInt(*this) += other; }
    ModInt operator-(const ModInt& other) const noexcept { return ModInt(*this) -= other; }
    ModInt operator*(const ModInt& other) const noexcept { return ModInt(*this) *= other; }
    ModInt operator/(const ModInt& other) const noexcept { return ModInt(*this) /= other; }

    ModInt& operator+=(const ModInt& other) noexcept {
        value += other.value;
        if (value >= N) value -= N;
        return *this;
    }
    ModInt& operator-=(const ModInt& other) noexcept {
        value -= other.value;
        if (value < 0) value += N;
        return *this;
    }
    ModInt& operator*=(const ModInt& other) noexcept {
        value = value * other.value % N;
        return *this;
    }
    ModInt& operator/=(const ModInt& other) noexcept {
        return *this *= other.inv();
    }

    ModInt pow(ll e) const noexcept {
        ModInt res(1), tmp(*this);
        while (e) {
            if (e & 1) res *= tmp;
            tmp *= tmp;
            e >>= 1;
        }
        return res;
    }
    ModInt inv() const noexcept {
        return pow(N - 2);
    }

    explicit operator int() const { return value; }
    friend std::ostream& operator<<(std::ostream& os, const ModInt& obj) {
        return os << obj.value;
    }
    friend std::istream& operator>>(std::istream& is, ModInt& obj) {
        ll t; is >> t;
        obj = ModInt(t);
        return is;
    }
};
constexpr int MOD = 1e9 + 7; // CHANGE!
using MI = ModInt<MOD>;
////////// SNIPPET END //////////

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

    MI a = 10;
    MI b = 20;
    MI c = a + b;
    MI d = a - b;
    MI e = a * b;
    MI f = a / b;

    assert(int(a) == 10 && int(b) == 20 && int(c) == 30 && int(d) == 999999997 && int(e) == 200 && int(f) == 500000004);

    MI x = 1;
    for (int i = 1; i < 101; ++i) {
        x *= MI(i);
    }
    assert(int(x) == 437918130);

    x = 1;
    for (int i = 1; i < 101; ++i) {
        x *= MI(i, 101-i);
    }
    assert(int(x) == 1);

    for (int i = 0; i < 1000000; ++i) {
        x += MI(i);
    }
    assert(int(x) == 999496508);

    MI y = 12345;
    assert(int(y.pow(0)) == 1 && int(y.pow(5)) == 607110006 && int(y.pow(100)) == 744524091);

    std::cout << "ALL TESTS PASSED\n";
}
