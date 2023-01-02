#include "Sorting.hpp"
#include <utility>

void BubbleSort(std::vector<int> randomArray, int events, long long *counts) {
    PAPI_reset(events);
    PAPI_start(events);

    for (int i = 0; i < randomArray.size() - 1; i++) {
        for (int j = 0; j < randomArray.size() - 1; j++) {
            if (randomArray[j] > randomArray[j + 1]) {
                std::swap(randomArray[j], randomArray[j + 1]);
            }
        }
    }

    PAPI_stop(events, counts);
}
