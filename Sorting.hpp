#include <vector>
#include <papi.h>

void QuickSort(std::vector<int>, int events, long long *counts);
void RadixSort(std::vector<int>, int events, long long *counts);
void SelectionSort(std::vector<int>, int events, long long *counts);
void BubbleSort(std::vector<int>, int events, long long *counts);
void InsertionSort(std::vector<int>, int events, long long *counts);
