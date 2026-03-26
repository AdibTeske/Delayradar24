#include <iostream>
#include <vector>
#include "data_processing.h"

int main() {
    std::cout << "Delayradar24: Processing Flights..." << std::endl;

    // Initiates data processing
    std::vector<AirportData> data = loadAndAggregateData("flight_data_2024.csv");

    // Check if data loaded
    if (data.empty()) {
        std::cout << "Error loading data." << std::endl;
        return 1;
    }

    // Total num of airports processed
    std::cout << "Processed " << data.size() << " airports." << std::endl;

    // Print the airport at  index 0 in the vector for testing
    std::cout << "Sample: " << data[0].airportCode << " average delay is " << data[0].averageDelay << " mins." << std::endl;

    // Print the airport at the given index in the vector for testing
    std::cout << "Sample: " << data[320].airportCode << " average delay is " << data[320].averageDelay << " mins." << std::endl;

    return 0;
}