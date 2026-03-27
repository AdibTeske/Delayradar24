#pragma once
#include "data_processing.h"
#include <vector>

// Re-orders subtrees iteratively to maintain the heap property.
// This function moves an Airport instance down the tree until it is in the correct relative position
template <typename Comparison>
void heapifyDown(std::vector<AirportData>& data, int size, int index, Comparison comparator) {
    while (true) {
        // Calculates the positions of the children in a 0-indexed array
        int leftIndex = 2 * index + 1;
        int rightIndex = 2 * index + 2;
        int extremaIndex = index;

        // Check if left child exists and if it should be higher in the heap than the current parent
        if (leftIndex < size && comparator(data[leftIndex], data[extremaIndex])) {
            extremaIndex = leftIndex;
        }

        // Check if right child exists and if it is more significant than the current extrema candidate
        if (rightIndex < size && comparator(data[rightIndex], data[extremaIndex])) {
            extremaIndex = rightIndex;
        }

        // If the current index is already the extrema, the heap property is satisfied
        if (index == extremaIndex) {
            return;
        }

        // Swap the parent with the larger/smaller child to satisfy the heap property
        AirportData temp = data[extremaIndex];
        data[extremaIndex] = data[index];
        data[index] = temp;
        
        // Move the index down to the child's old position and continue checking
        index = extremaIndex;
    }
}

// Main Heap Sort implementation using a custom comparator
template <typename Comparison>
void heapSort(std::vector<AirportData>& data, Comparison comparator) {
    // Build the initial heap by heapifying downwards on the upper half ot the heap
    for (int i = data.size() / 2; i >= 0; i--) {
        heapifyDown(data, data.size(), i, comparator);
    }

    // Extract elements from the heap one by one to sort
    for (int i = data.size() - 1; i >= 0; i--) {
        // Build a "sorted" section of the vector by swapping with the root of the heap (Max/Min)
        AirportData temp = data[0];
        data[0] = data[i];
        data[i] = temp;

        // Heapify down the root such that the root is the Max/Min of the "unsorted" section
        heapifyDown(data, i, 0, comparator);
    }
}