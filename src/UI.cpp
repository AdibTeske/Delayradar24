#include "UI.h"
#include <iostream>
#include <iomanip>
#include <limits>

// Define and initialize the Control Sequence Introducer
const std::string CSI = "\x1b[";

// 2J clears visible screen, 3J clears scrollback screen, 1H print from top left
void clearScreen() {
    std::cout << CSI << "2J" << CSI << "3J" << CSI << "1H" << std::flush;
}

// Print string that is char c repeated WIDTH times
void printHeaderBorder(char c) {
    std::cout << std::string(WIDTH, c) << std::endl;
}

void printCentered(const std::string& text) {
    size_t len = text.length();

    // If text is wider than the UI width, print without gap
    if (len >= WIDTH) {
        std::cout << text << std::endl;
        return;
    }

    // Calculate that gap needed to center and use that to set width and then print
    size_t space = (len + WIDTH) / 2;
    std::cout << std::setw(space) << text << std::endl;
}

void printRanking(const std::vector<AirportData>& data, size_t num) {
    std::cout << "Ranking (Airport Code: average delay per flight in minutes)" << std::endl;

    // Set precision to 2 decimal places
    std::cout << std::fixed << std::setprecision(2);

    // Iterate through the first 'num' elements of the presumed sorted vector
    for (size_t i = 0; i < num; i++) {
        std::cout << (i + 1) << ". " << data[i].airportCode << ": " << data[i].averageDelay << std::endl;
    }
}

size_t getValidListSize() {
    long long input;

    while (true) {
        std::cout << "Selection > ";
        std::cin >> input;

        // Ensure input is a number
        if (std::cin.fail()) {
            std::cout << "Invalid! Thats not a number. Try again." << std::endl;
            // Reset error flags to bring back into a valid state
            std::cin.clear();

            // Discard all the remaining characters in the buffer until new line is found
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            // Ensure input is within the range of the number of airports
            if (input < 0) {
                std::cout << "Invalid! Negative numbers are not within 1-334. Try again." << std::endl;
                continue;
            }
            if (input == 0) {
                std::cout << "Invalid! Zero is not within 1-334. Try again." << std::endl;
                continue;
            }
            if (input > 334) {
                std::cout << "Invalid! There are not that many airports. Try again." << std::endl;
                continue;
            }
            return static_cast<size_t>(input);
        }
    }
}

bool shouldContinue() {
    std::string again;
    while (true) {
        std::cout << "Selection > ";
        std::cin >> again;
        
        // Determine whether user enters a valid choice and handles exit condition
        if (again == "n" || again == "N") {
            std::cout << "Have a good flight!" << std::endl;
            return false;
        }
        if (again == "y" || again == "Y") {
            return true;
        }

        // The input was neither Y or N
        std::cout << "Invalid choice. Would you like to go again (Y/N)?" << std::endl;

        // Reset error flags to bring back into a valid state
        std::cin.clear();

        // Discard all the remaining characters in the buffer until new line is found
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int getMenuChoice() {
    int choice;

    // Refresh UI for every menu return
    clearScreen();

    printHeaderBorder('=');
    printCentered("Delayradar24!");
    printHeaderBorder('=');

    while (true) {
        std::cout << "Tracking 334 airports..." << std::endl;
        std::cout << "\n1. Sort by Most Delayed Airports"
                << "\n2. Sort by Least Delayed Airports"
                << "\n3. Sort by Airport Code (A-Z)"
                << "\n4. Sort by Airport Code (Z-A)"
                << "\n5. Exit"
                << "\n\nSelection > ";

        std::cin >> choice;

        // Ensure input is a number
        if (std::cin.fail()) {
            // Reset error flags to bring back into a valid state
            std::cin.clear();

            // Discard all the remaining characters in the buffer until new line is found
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Invalid! There are no letters in our choices. Read again and try again." << std::endl;
            continue;
        }

        // Ensure input is within the possible choice range
        if (choice < 1 || choice > 5) {
            std::cout << "Invalid! Your choice is not within 1-5. Read again and try again." << std::endl;
            continue;
        }

        return choice;
    }
}