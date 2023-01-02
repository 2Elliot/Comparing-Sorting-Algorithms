cmake_minimum_required(VERSION 3.16.0)
project(SORTS CXX)

include(FetchContent)
FetchContent_Declare(fmt
  GIT_REPOSITORY     https://github.com/fmtlib/fmt.git
  GIT_TAG            9.1.0)
FetchContent_MakeAvailable(fmt)

include(FindPkgConfig)
find_package(PkgConfig QUIET)
pkg_search_module(PAPI REQUIRED QUIET IMPORTED_TARGET papi)

add_executable(Sort main.cpp QuickSort.cpp RadixSort.cpp SelectionSort.cpp BubbleSort.cpp InsertionSort.cpp)

target_link_libraries(Sort PRIVATE fmt::fmt PkgConfig::PAPI)
