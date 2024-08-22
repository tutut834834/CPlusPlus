# CPlusPlus


# Quicksort Optimization in C++

This repository contains two implementations of the Quicksort algorithm in C++:

1. **Basic Quicksort with Branching:** This is a standard implementation that includes conditional branches during the sorting process.
2. **Branchless Quicksort Using `swap_if`:** This implementation removes conditional branches by using a `swap_if` function, which aims to optimize performance by reducing the number of branch mispredictions.

## Compilation

To compile both versions, use the following commands:

```bash
g++ -O3 -march=native quicksort_branching.cpp -o quicksort_branching
g++ -O3 -march=native quicksort_branchless.cpp -o quicksort_branchless

Running the Programs

You can run each program to see the time it takes to sort 100,000 random integers:

bash

./quicksort_branching

This will output something like:

bash

Time for quicksort with branching: 0.009887 seconds

Then, run the branchless version:

bash

./quicksort_branchless

This will output something like:

bash

Time for branchless quicksort: 0.008538 seconds

Results

    Quicksort with branching: ~0.009887 seconds
    Branchless quicksort: ~0.008538 seconds

The branchless quicksort implementation is slightly faster in this test case. This demonstrates how low-level optimizations, such as removing conditional branches, can lead to performance improvements.
Conclusion

The results show that the branchless version of quicksort can offer better performance, particularly in environments where branch prediction is a significant factor. This repository serves as an example of how small, low-level changes can make a difference in algorithm efficiency.

Feel free to explore the code and experiment with different optimizations!
