/*
    DEBUG.cpp

    Overloads ostream operators for standard types.
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
template <typename T, typename U>
std::ostream& operator<<(std::ostream& out, const std::pair<T, U>& pair) {
    return out << "(" << pair.first << ", " << pair.second << ")";
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec) {
    if (vec.empty()) {
        out << "[]";
        return out;
    }
    out << "[" << vec[0];
    for (size_t i = 1; i < vec.size(); ++i) {
        out << ", " << vec[i];
    }
    out << "]";
    return out;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::deque<T>& deq) {
    if (deq.empty()) {
        out << "[]";
        return out;
    }
    out << "[" << deq[0];
    for (size_t i = 1; i < deq.size(); ++i) {
        out << ", " << deq[i];
    }
    out << "]";
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::unordered_set<T>& set) {
    out << '{';
    for (auto it = set.begin(); it != set.end(); it++) {
        T element = *it;
        out << element;
        if (std::next(it) != set.end()) {
            out << ", ";   
        }
    }
    return out << '}';
}

template <typename T, typename U>
std::ostream& operator<<(std::ostream& out, const std::map<T, U>& map) {
    out << '{';
    for (auto it = map.begin(); it != map.end(); it++) {
        std::pair<T, U> element = *it;
        out << element.first << ": " << element.second;
        if (std::next(it) != map.end()) {
            out << ", ";   
        }
    }
    return out << '}';
}
$0
////////// SNIPPET END //////////

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

    
}
