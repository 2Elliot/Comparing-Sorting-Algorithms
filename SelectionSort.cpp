#include "Sorting.hpp"
#include <utility>

void SelectionSort(std::vector<int> randomArray, int events, long long *counts) {
    PAPI_reset(events);
    PAPI_start(events);

    for (int i = 0; i < randomArray.size() - 1; i++) {
        int localLow = i;
        for (int j = i + 1; j < randomArray.size(); j++) {
            if (randomArray[j] < randomArray[localLow]) {
                localLow = j;
            }
        }
        std::swap(randomArray[i], randomArray[localLow]);
    }

    PAPI_stop(events, counts);
}
