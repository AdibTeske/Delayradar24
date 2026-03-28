#include "data_processing.h"
#include "UI.h"
#include "comparators.h"
#include "heap_sort.h"
#include "quick_sort.h"
#include <iostream>
#include <vector>


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

        // Determine sorting choice based on user input
        switch (choice) {
            case 1: // Highest First (VECTOR is sorted descending)
                heapSort(data, DescendingDelay{});
                quickSort(data, DescendingDelay{});
                break;

            case 2: // Lowest First (VECTOR is sorted ascending)
                heapSort(data, AscendingDelay{});
                quickSort(data, AscendingDelay{});
                break;

            case 3: // A First (VECTOR is sorted ascending lexicographically)
                heapSort(data, AscendingLexi{});
                quickSort(data, AscendingLexi{});
                break;

            case 4: // Z First (VECTOR is sorted descending lexicographically)
                heapSort(data, DescendingLexi{});
                quickSort(data, DescendingLexi{});
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
        
        // Determine if program should exit or loop back to menu
        std::cout << "Would you like to go again? (Y/N)" << std::endl;
        if (!shouldContinue()) {
            return 0;
        }
    }
    return 0;
}