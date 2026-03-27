#pragma once
#include "data_processing.h"

// Comparator to sort airport VECTOR by their average delay in descending order
struct DescendingDelay {
    bool operator()(const AirportData& a, const AirportData& b) const {
        return a.averageDelay < b.averageDelay;
    }
};

// Comparator to sort airport VECTOR by their average delay in ascending order
struct AscendingDelay {
    bool operator()(const AirportData& a, const AirportData& b) const {
        return a.averageDelay > b.averageDelay;
    }
};

// Comparator to sort airport VECTOR by their 3-letter code in alphabetical order (A-Z)
struct AscendingLexi {
    bool operator()(const AirportData& a, const AirportData& b) const {
        return a.airportCode > b.airportCode;
    }
};

// Comparator to sort airport VECTOR by their 3-letter code in reverse alphabetical order (Z-A)
struct DescendingLexi {
    bool operator()(const AirportData& a, const AirportData& b) const {
        return a.airportCode < b.airportCode;
    }
};