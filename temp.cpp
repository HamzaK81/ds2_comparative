#include <iostream>
#include <chrono>
#include <vector>
#include "lib/gnuplot-iostream.h" // Gnuplot library


// Sorting algorithm to measure runtime
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}


int main() {
    Gnuplot gp;

    // Initialize vectors for storing runtime data
    std::vector<int> inputSizes = {100, 500, 1000, 2000}; // Input sizes (n)
    std::vector<double> runtimes;

    // Measure runtime for each input size
    for (int n : inputSizes) {
        // Generate random input data
        std::vector<int> data(n);
        for (int& x : data) {
            x = rand() % 1000; // Random values between 0 and 999
        }

        // Measure runtime of the algorithm
        auto start = std::chrono::steady_clock::now();
        bubbleSort(data);
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> duration = end - start;
        runtimes.push_back(duration.count());
    }

    // Plot the runtime data
    gp << "set title 'Runtime vs Input Size'\n";
    gp << "set xlabel 'Input Size (n)'\n";
    gp << "set ylabel 'Runtime (seconds)'\n";
    gp << "plot '-' with lines title 'Bubble Sort'\n";
    for (size_t i = 0; i < inputSizes.size(); ++i) {
        gp << inputSizes[i] << " " << runtimes[i] << "\n";
    }
    gp << "e\n";

    return 0;
}
