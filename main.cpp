#include <fmt/core.h>
#include <fmt/ranges.h>
#include <papi.h>

#include <algorithm>
#include <cstdlib>
#include <vector>

#include "Sorting.hpp"

auto make_sorted_array(std::vector<int>& data) {
    for (int i = 0; i < data.size(); i++) {
        data[i] = i;
    }
}

int main(int, char**) {
    // initialize PAPI library
    PAPI_library_init(PAPI_VER_CURRENT);

    // create three counters
    int events = PAPI_NULL;
    PAPI_create_eventset(&events);
    PAPI_add_event(events, PAPI_TOT_INS);
    PAPI_add_event(events, PAPI_TOT_CYC);
    PAPI_add_event(events, PAPI_L1_DCM);

    std::vector<int> data;
    data.resize(1);

    long long counts[3]{};
    QuickSort(data, events, counts);

    fmt::print("Algorithm n Count\n");

    for (int n = 1; n <= (1 << 20); n *= 2) {
        data.resize(n);
        // Randomized Array Testing
        std::generate(data.begin(), data.end(), rand);
        QuickSort(data, events, counts);
        fmt::print("QuickSort {} {}\n", n, counts[0]);
        RadixSort(data, events, counts);
        fmt::print("RadixSort {} {}\n", n, counts[0]);
        SelectionSort(data, events, counts);
        fmt::print("SelectionSort {} {}\n", n, counts[0]);
        InsertionSort(data, events, counts);
        fmt::print("InsertionSort {} {}\n", n, counts[0]);
        BubbleSort(data, events, counts);
        fmt::print("BubbleSort {} {}\n", n, counts[0]);

        // Sorted Array Testing
        make_sorted_array(data);
        QuickSort(data, events, counts);
        fmt::print("SortedQuickSort {} {}\n", n, counts[0]);
        RadixSort(data, events, counts);
        fmt::print("SortedRadixSort {} {}\n", n, counts[0]);
        SelectionSort(data, events, counts);
        fmt::print("SortedSelectionSort {} {}\n", n, counts[0]);
        InsertionSort(data, events, counts);
        fmt::print("SortedInsertionSort {} {}\n", n, counts[0]);
        BubbleSort(data, events, counts);
        fmt::print("SortedBubbleSort {} {}\n", n, counts[0]);
    }

    for (int j = 0; j < 10; j++) {
        fmt::print("------------------\n");
    }

    fmt::print("Algorithm n Count\n");
    for (int n = 1; n <= (1 << 30); n *= 2) {
        data.resize(n);
        // Randomized Array Testing
        std::generate(data.begin(), data.end(), rand);
        QuickSort(data, events, counts);
        fmt::print("QuickSort {} {}\n", n, counts[0]);
        RadixSort(data, events, counts);
        fmt::print("RadixSort {} {}\n", n, counts[0]);

        // Sorted Array Testing
        make_sorted_array(data);
        QuickSort(data, events, counts);
        fmt::print("SortedQuickSort {} {}\n", n, counts[0]);
        RadixSort(data, events, counts);
        fmt::print("SortedRadixSort {} {}\n", n, counts[0]);
        SelectionSort(data, events, counts);
    }

    // clear and restart counters
    PAPI_reset(events);
    PAPI_start(events);

    // destroy the event set
    PAPI_cleanup_eventset(events);
    PAPI_destroy_eventset(&events);
}
