#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

// Basic quicksort with branching
void quicksort_branching(std::vector<int>& data, int left, int right) {
    if (left < right) {
        int pivot = data[right];
        int i = left - 1;

        for (int j = left; j < right; ++j) {
            if (data[j] <= pivot) {
                std::swap(data[++i], data[j]);
            }
        }
        std::swap(data[i + 1], data[right]);

        quicksort_branching(data, left, i);
        quicksort_branching(data, i + 2, right);
    }
}

int main() {
    int size = 100000;
    std::vector<int> data(size);

    // Generate random data
    std::generate(data.begin(), data.end(), []() { return rand() % 1000000; });

    // Measure time for basic quicksort with branching
    std::vector<int> data_copy = data;
    clock_t start = clock();
    quicksort_branching(data_copy, 0, data_copy.size() - 1);
    clock_t end = clock();
    std::cout << "Time for quicksort with branching: " << double(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;

    return 0;
}

