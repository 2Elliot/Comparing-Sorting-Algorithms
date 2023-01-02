#include "Sorting.hpp"
#include <utility>

int GetCorrectSwapValue(std::vector<int>& array, int tempHigh, int pivot) {
    if (array[tempHigh] <= pivot) {
        return tempHigh + 1;
    }
    return tempHigh;

}

void Partition(std::vector<int>& array, int low, int high) {
    if (high == low) {
        return;
    }
    int tempHigh = high - 1;
    int pivot = array[(low + high) / 2];
    std::swap(array[(low + high) / 2], array[high]);
    for (int i = low; i < tempHigh;) {
        if (array[i] >= pivot) {
            std::swap(array[i], array[tempHigh]);
            tempHigh--;
        } else {
            i++;
        }
    }
    std::swap(array[high], array[GetCorrectSwapValue(array, tempHigh, pivot)]);
    Partition(array, low, tempHigh);
    Partition(array, tempHigh + 1, high);
    return;
}

void QuickSort(std::vector<int> randomArray, int events, long long *counts) {
    PAPI_reset(events);
    PAPI_start(events);

    Partition(randomArray, 0, randomArray.size() - 1);

    PAPI_stop(events, counts);
}
