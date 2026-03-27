#pragma once
#include "data_processing.h"

// Comparator to sort airports by their average delay from lowest to highest
struct AscendingDelay {
    bool operator()(const AirportData& a, const AirportData& b) const {
        return a.averageDelay < b.averageDelay;
    }
};

// Comparator to sort airports by their average delay from highest to lowest
struct DescendingDelay {
    bool operator()(const AirportData& a, const AirportData& b) const {
        return a.averageDelay > b.averageDelay;
    }
};

// Comparator to sort airports by their 3-letter code in alphabetical order (A-Z)
struct AscendingLexi {
    bool operator()(const AirportData& a, const AirportData& b) const {
        return a.airportCode < b.airportCode;
    }
};

// Comparator to sort airports by their 3-letter code in reverse alphabetical order (Z-A)
struct DescendingLexi {
    bool operator()(const AirportData& a, const AirportData& b) const {
        return a.airportCode > b.airportCode;
    }
};