# Competitive Programming Snippets

This repository contains the snippets that I use for competitive programming (still under development, likely to grow greatly... will gradually add templates as I encounter necessary uses of them). Much of the organization is inspired by [KACTL](https://github.com/kth-competitive-programming/kactl), and snippets are often inspired or taken from various sources (if the technique is nonstandard, a link will usually be provided).

## Organization

Here is the current directory layout:

    .
    ├── cpp
    │   ├── 00-contest             # Contest templates and timer.
    │   ├── 01-inputoutput         # File I/O and stream overloads.
    │   ├── 02-datastructures      # e.g. indexed sets, line containers, segment trees
    │   ├── 03-numbertheory        # e.g. ModInt, primality
    │   ├── 04-combinatorics   
    │   ├── 05-polynomial   
    │   ├── 06-graph               # e.g. DSU, topsort, SCC, LCA, flows
    │   ├── 07-geometry   
    │   ├── 08-strings   
    │   ├── 09-dynamicprogramming  
    │   └── 10-bits                # e.g. Gosper's hack, custom bitset, subset iteration
    │
    ├── snippet_compiler.py        # Compiles the snippets into json
    ├── out.json
    ├── .gitignore
    ├── LICENSE
    └── README.md

The main file is `snippet_compiler.py`, which collects snippets from the various folders in `cpp/` and formats them into the `out.json` file. This file can be directly copied into Visual Studio Code's user snippets configuration for C++ files and used.

Within `cpp/`, the individual snippets are divided into several folders. Each individual snippet must be placed in a subfolder. Files are added in lexicographical order, hence the prefixes for ordering.

## Snippet Format

Snippets must be in files with naming format `xy-NAME.cpp`. In the parsed JSON, the snippet will be named `CP-NAME` and can be used by typing `NAME` into the text editor. The `xy-` prefix is for ordering purposes. For convenience, `cpp/00-contest/00-SNIPPET.cpp` contains a meta-snippet which can be used to easily generate more.

The first five lines of the file should be a comment, e.g.

```
/*
    ERASTOSTHENES.cpp

    Sieve for generating primes up to `MAX_PR`.
*/
```

In particular, the fourth line must contain the description of the snippet. This should be relatively short, and must fit within one line to be parsed correctly.

The actual snippet should be placed between two lines which are exactly `////////// SNIPPET BEGIN //////////` and `////////// SNIPPET END //////////`, with no indents, e.g.

```
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
```

Everything outside of the first snippet begin line and the final snippet end line is ignored. To facilitate Visual Studio Code cursor placement in snippets, you will often see a line `#define $0 ;` which allows the insertion of `$0` into the snippet without C++ complaints. This places the cursor after snippet insertion.

The rest of the snippet file may be used for tests.

## Design Choices

* Strive for clear, modifiable code, rather than terse or highly optimized code.
* Despite the inclusion of `using namespace std;` in all my templates, in general snippets should function without this restriction. Snippets generally may use type aliases such as `ll`.
* When possible, follow C++ best practices. (Eventually, I plan on refactoring many pieces of code.)
* Eventually, write tests and stress tests wherever applicable.
