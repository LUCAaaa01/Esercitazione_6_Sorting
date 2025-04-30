#include "SortingAlgorithm.hpp"
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include <numeric>

using namespace std;
using namespace SortLibrary;

vector<int> generate_random(size_t n) {
    vector<int> v(n);
    mt19937_64 eng{random_device{}()};
    uniform_int_distribution<int> dist(0, static_cast<int>(n));
    for (auto& x : v) x = dist(eng);
    return v;
}

vector<int> generate_sorted(size_t n) {
    vector<int> v(n);
    iota(v.begin(), v.end(), 0);
    return v;
}

vector<int> generate_reverse(size_t n) {
    auto v = generate_sorted(n);
    reverse(v.begin(), v.end());
    return v;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <vector_size>\n";
        return 1;
    }
    size_t n = stoul(argv[1]);

    // preparazione dei casi di test
    vector<pair<string, vector<int>>> tests;
    tests.emplace_back("Random",   generate_random(n));
    tests.emplace_back("Sorted",   generate_sorted(n));
    tests.emplace_back("Reverse",  generate_reverse(n));

    cout << "n = " << n << "\n";
    for (auto& [name, base] : tests) {
        cout << name << " vector:\n";

        // BubbleSort
        {
            auto v = base;
            auto t0 = chrono::high_resolution_clock::now();
            BubbleSort(v);
            auto t1 = chrono::high_resolution_clock::now();
            auto dt = chrono::duration_cast<chrono::microseconds>(t1 - t0).count();
            cout << "  BubbleSort: " << dt << " µs\n";
        }

        // HeapSort
        {
            auto v = base;
            auto t0 = chrono::high_resolution_clock::now();
            HeapSort(v);
            auto t1 = chrono::high_resolution_clock::now();
            auto dt = chrono::duration_cast<chrono::microseconds>(t1 - t0).count();
            cout << "  HeapSort:   " << dt << " µs\n";
        }
    }

    return 0;
}
