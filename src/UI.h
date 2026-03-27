#pragma once
#include "data_processing.h"
#include <string>
#include <cstddef>

// Default and fixed width for the terminal UI layout
const size_t WIDTH = 50;

// Clears the terminal screen
void clearScreen();

// Prints a horizontal divider of a specified (or a default '=') char across the UI width
void printHeaderBorder(char c = '=');

// Centers a string within the UI width
void printCentered(const std::string& text);

// Outputs a numbered list of airport codes from the data vector up to num elements
void printRanking(const std::vector<AirportData>& list, size_t num);

// Prompts the user for a list size and validates that it is a positive number within range 1-334
size_t getValidListSize();

// Asks the user if they want to continue with another selection
bool shouldContinue();

// Displays the main program menu and validates the integer choice to be within 1-5
int getMenuChoice();