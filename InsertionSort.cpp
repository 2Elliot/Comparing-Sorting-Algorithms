#include "Sorting.hpp"
#include <utility>

void InsertionSort(std::vector<int> randomArray, int events, long long *counts) {
    PAPI_reset(events);
    PAPI_start(events);

    for (int i = 0; i < randomArray.size(); i++) {
        int temp = i;
        while (temp >= 1 && randomArray[temp] < randomArray[temp - 1]) {
            std::swap(randomArray[temp], randomArray[temp - 1]);
            temp--;
        }
    }

    PAPI_stop(events, counts);
}
