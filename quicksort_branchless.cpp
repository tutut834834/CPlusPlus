#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

// Improved branchless swap_if function
inline bool swap_if(bool condition, int& a, int& b) {
    if (condition) {
        std::swap(a, b);
    }
    return condition;
}

// Branchless quicksort using swap_if
void quicksort_branchless(std::vector<int>& data, int left, int right) {
    if (left < right) {
        int pivot = data[right];
        int i = left - 1;

        for (int j = left; j < right; ++j) {
            bool condition = data[j] <= pivot;
            i += condition;
            swap_if(condition, data[i], data[j]);
        }
        std::swap(data[i + 1], data[right]);

        quicksort_branchless(data, left, i);
        quicksort_branchless(data, i + 2, right);
    }
}

int main() {
    int size = 100000;
    std::vector<int> data(size);

    // Generate random data
    std::generate(data.begin(), data.end(), []() { return rand() % 1000000; });

    // Measure time for branchless quicksort
    std::vector<int> data_copy = data;
    clock_t start = clock();
    quicksort_branchless(data_copy, 0, data_copy.size() - 1);
    clock_t end = clock();
    std::cout << "Time for branchless quicksort: " << double(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;

    return 0;
}

