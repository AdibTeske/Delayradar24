#ifndef DATA_PROCESSING_H
#define DATA_PROCESSING_H

#include <string>
#include <vector>

// Struct with the final averaged results to be sorted
struct AirportData {
    std::string airportCode;
    double averageDelay;
};

// Function declaration (input of filename and outputs the list with AirportData objects)
std::vector<AirportData> loadAndAggregateData(const std::string& filename);

#endif