#include "Sorting.hpp"
#include <utility>

void Radix(std::vector<int>& randomArray, int low, int high, int currBit) {
    if (currBit == -1) {
        return;
    }
    int localLow = low;
    int localHigh = high;
    for (int i = low; i < high;) {
        if (((randomArray[i] >> currBit) % 2) == 0) {
            i++;
        } else {
            std::swap(randomArray[high - 1], randomArray[i]);
            high--;
        }
    }

    currBit--;
    if (localLow != high) {
        Radix(randomArray, localLow, high, currBit);
    }
    if (high != localHigh) {
        Radix(randomArray, high, localHigh, currBit);
    }

}

void RadixSort(std::vector<int> randomArray, int events, long long *counts) {
    PAPI_reset(events);
    PAPI_start(events);

    Radix(randomArray, 0, randomArray.size(), 31);

    PAPI_stop(events, counts);
}