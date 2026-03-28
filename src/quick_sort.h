#pragma once
#include "data_processing.h"
#include <vector>
#include <cstddef>

// Partitions the subarray around a pivot element using the Lomuto scheme.
// Elements that belong before the pivot (per the comparator) are moved to the left partition
template <typename Comparison>
size_t partition(std::vector<AirportData>& data, size_t low, size_t high, Comparison comparator) {
    // Use the last element as the pivot
    AirportData pivot = data[high];
    size_t i = low;

    // Walk through the subarray and move elements that belong before the pivot to the left
    for (size_t j = low; j < high; j++) {
        if (comparator(pivot, data[j])) {
            AirportData temp = data[i];
            data[i] = data[j];
            data[j] = temp;
            i++;
        }
    }

    // Place the pivot in its correct sorted position between the two partitions
    AirportData temp = data[i];
    data[i] = data[high];
    data[high] = temp;

    return i;
}

// Recursively sorts partitions on either side of the pivot
template <typename Comparison>
void quickSortHelper(std::vector<AirportData>& data, size_t low, size_t high, Comparison comparator) {
    if (low < high) {
        // Partition the subarray and get the final position of the pivot
        size_t pivotIndex = partition(data, low, high, comparator);

        // Sort the left partition (only if the pivot is not at the leftmost position)
        if (pivotIndex > low) {
            quickSortHelper(data, low, pivotIndex - 1, comparator);
        }

        // Sort the right partition (only if the pivot is not at the rightmost position)
        if (pivotIndex < high) {
            quickSortHelper(data, pivotIndex + 1, high, comparator);
        }
    }
}

// Main Quick Sort implementation using a custom comparator
template <typename Comparison>
void quickSort(std::vector<AirportData>& data, Comparison comparator) {
    if (data.size() <= 1) {
        return;
    }
    quickSortHelper(data, 0, data.size() - 1, comparator);
}