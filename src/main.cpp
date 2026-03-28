#include "data_processing.h"
#include "UI.h"
#include "comparators.h"
#include "heap_sort.h"
#include "quick_sort.h"
#include <iostream>
#include <vector>
#include <chrono>


int main() {    
    std::cout << "Delayradar24: Processing Flights..." << std::endl;
    
    // Initiates data processing
    std::vector<AirportData> data = loadAndAggregateData("flight_data_2024.csv");

    // Check if data loaded
    if (data.empty()) {
        std::cout << "Error loading data." << std::endl;
        return 1;
    }

    // Main program loop
    while (true) {
        int choice = getMenuChoice();
        std::chrono::high_resolution_clock::time_point t1Heap, t2Heap, t3Quick, t4Quick;

        // Deep copy for controlled comparison
        std::vector<AirportData> data2 = data;

        // Determine sorting choice based on user input
        switch (choice) {
            case 1: // Highest First (VECTOR is sorted descending)
                // Execute Heap Sort and measure elapsed time
                t1Heap = std::chrono::high_resolution_clock::now();
                heapSort(data, DescendingDelay{});
                t2Heap = std::chrono::high_resolution_clock::now();

                // Execute Quick Sort and measure elapsed time
                t3Quick = std::chrono::high_resolution_clock::now();
                quickSort(data2, DescendingDelay{});
                t4Quick = std::chrono::high_resolution_clock::now();

                break;

            case 2: // Lowest First (VECTOR is sorted ascending)
                // Execute Heap Sort and measure elapsed time
                t1Heap = std::chrono::high_resolution_clock::now();
                heapSort(data, AscendingDelay{});
                t2Heap = std::chrono::high_resolution_clock::now();

                // Execute Quick Sort and measure elapsed time
                t3Quick = std::chrono::high_resolution_clock::now();
                quickSort(data2, AscendingDelay{});
                t4Quick = std::chrono::high_resolution_clock::now();

                break;

            case 3: // A First (VECTOR is sorted ascending lexicographically)
                // Execute Heap Sort and measure elapsed time
                t1Heap = std::chrono::high_resolution_clock::now();
                heapSort(data, AscendingLexi{});
                t2Heap = std::chrono::high_resolution_clock::now();

                // Execute Quick Sort and measure elapsed time
                t3Quick = std::chrono::high_resolution_clock::now();
                quickSort(data2, AscendingLexi{});
                t4Quick = std::chrono::high_resolution_clock::now();

                break;

            case 4: // Z First (VECTOR is sorted descending lexicographically)
                // Execute Heap Sort and measure elapsed time
                t1Heap = std::chrono::high_resolution_clock::now();
                heapSort(data, DescendingLexi{});
                t2Heap = std::chrono::high_resolution_clock::now();

                // Execute Quick Sort and measure elapsed time
                t3Quick = std::chrono::high_resolution_clock::now();
                quickSort(data2, DescendingLexi{});
                t4Quick = std::chrono::high_resolution_clock::now();
                break;

            case 5: // Exit
                std::cout << "Have a good flight!!" << std::endl;
                return 0;
        }

        // Prompt user for how long their ranked list should be
        std::cout << "How many Airports do you want to view in the ranking? (1-334)" << std::endl;
        
        // Retrieves valid user input and prints the sorted data accordingly
        size_t num = getValidListSize();
        printRanking(data, num);

        // Calculate elapsed time of both Heap Sort and Quick Sort
        auto elapsedTimeHeap = std::chrono::duration_cast<std::chrono::microseconds>(t2Heap - t1Heap);
        auto elapsedTimeQuick = std::chrono::duration_cast<std::chrono::microseconds>(t4Quick - t3Quick);
        
        // Print results to compare
        std::cout << "Time taken by Heap Sort: " << elapsedTimeHeap.count() << " microseconds" << std::endl;
        std::cout << "Time taken by Quick Sort: " << elapsedTimeQuick.count() << " microseconds" << std::endl;
        
        // Determine if program should exit or loop back to menu
        std::cout << "Would you like to go again? (Y/N)" << std::endl;
        if (!shouldContinue()) {
            return 0;
        }
    }
    return 0;
}