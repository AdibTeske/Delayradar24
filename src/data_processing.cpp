#include "data_processing.h"
#include <iostream>
#include <fstream>
#include <unordered_map>

// This function reads a row of the CSV and splits it by commas, but ignores  commas inside quotation marks
std::vector<std::string> parseCSVLine(const std::string& line) {
    std::vector<std::string> result;
    std::string cell;
    bool inQuotes = false;
    
    for (char c : line) {
        if (c == '"') {
            inQuotes = !inQuotes; 
        } else if (c == ',' && !inQuotes) {
            result.push_back(cell);
            cell = "";
        } else {
            cell += c;
        }
    }
    result.push_back(cell); 
    
    return result;
}

// Function implementation (input of filename and outputs the list with AirportData objects)
std::vector<AirportData> loadAndAggregateData(const std::string& filename) {
    
    // Hash table implementation:
    // Key: airport code
    // Value: pair containing: (total delay in minutes, total num of flights)
    std::unordered_map<std::string, std::pair<double, int>> aggregationMap;
    
    // Open the CSV file
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open " << filename << std::endl;
        return {};
    }

    std::string line;
    // Discard the first row because it contains the column headers
    std::getline(file, line); 

    // Index 5 is airport code
    // Index 17 is the delay
    const int ORIGIN_INDEX = 5;
    const int DELAY_INDEX = 17;

    // Loop through every row in the dataset skipping blank lines
    while (std::getline(file, line)) {
        if (line.empty()) continue; 

        // Run the CSV string through parser function
        std::vector<std::string> columns = parseCSVLine(line);

        // Check if the row has enough columns
        if (columns.size() > DELAY_INDEX) {
            std::string airportCode = columns[ORIGIN_INDEX];
            std::string delayStr = columns[DELAY_INDEX];

            if (!airportCode.empty() && !delayStr.empty()) {
                try {
                    double delay = std::stod(delayStr);
                    aggregationMap[airportCode].first += delay;  
                    aggregationMap[airportCode].second += 1;     
                } catch (...) { 
                    // If the delay input is bad skip row
                }
            }
        }
    }
    
    file.close();

    // Move from hash table to list
    std::vector<AirportData> resultVector;
    
    // Loop through every airport in hash table
    for (auto const& [code, stats] : aggregationMap) {
        if (stats.second > 0) { 
            // Calculate average
            double average = stats.first / stats.second;
            
            // Convert result into struct and add it to the final list
            resultVector.push_back({code, average});
        }
    }

    // Return the final list to be sorted
    return resultVector;
}