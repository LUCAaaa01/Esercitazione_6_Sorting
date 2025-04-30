#pragma once

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

namespace SortLibrary {


template<typename T>
void SelectionSort(std::vector<T>& v) {
    size_t n = v.size();
    for (size_t i = 0; i + 1 < n; ++i) {
        size_t minIdx = i;
        for (size_t j = i + 1; j < n; ++j)
            if (v[j] < v[minIdx]) minIdx = j;
        std::swap(v[i], v[minIdx]);
    }
}


template<typename T>
void InsertionSort(std::vector<T>& v) {
    size_t n = v.size();
    for (size_t i = 1; i < n; ++i) {
        T key = v[i];
        size_t j = i;
        while (j > 0 && v[j - 1] > key) {
            v[j] = v[j - 1];
            --j;
        }
        v[j] = key;
    }
}




template<typename T>
void BubbleSort(std::vector<T>& v)
{
    size_t n = v.size();
    bool swapped;
    for(size_t i=0;i<n;++i){
    	swapped = false;
    	for(size_t j=1;j<(n-i);++j){
    		if (v[j-1]>v[j]){
    			swap(v[j-1],v[j]);
    			swapped = true;
    		}

        }
        if (!swapped) {
        	break; //già ordinato
        }
    }
}


template<typename T>
static void siftDown(std::vector<T>& v, size_t start, size_t end)
{
    size_t root = start;
    while (true) {
        size_t child = 2 * root + 1; 
        if (child > end) break;
       
        if (child + 1 <= end && v[child] < v[child + 1]) {
            ++child;
        }
        
        if (v[root] >= v[child]) break;
       
        swap(v[root], v[child]);
        root = child;
    }
}


template<typename T>
void HeapSort(std::vector<T>& v)
{
	size_t n = v.size();
    if (n < 2) return;

    for (size_t i = (n - 2) / 2 + 1; i > 0; --i) {
        siftDown(v, i - 1, n - 1);
    }

    for (size_t end = n - 1; end > 0; --end) {
        swap(v[0], v[end]);
        siftDown(v, 0, end - 1);
    }

}


}


