#include "Utils.h"
#include <iostream>
#include <limits>

void displayHeader() {
    std::cout << "------------------------" << std::endl;
    std::cout << "|Music Store of Group 3|" << std::endl;
    std::cout << "------------------------\n" << std::endl;
}

int getSafeInt(std::string prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            return value;
        } else {

            std::cout << "Invalid input! Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void pressEnterToContinue() {
    std::cout << "\nPress ENTER to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}


int getSafeInt(std::string prompt, int min, int max) {
    int value;
    while (true) {
        value = getSafeInt(prompt);
        if (value >= min && value <= max) {
            return value;
        }
        std::cout << "[ERROR] Invalid choice. Range: " << min << " - " << max << std::endl;
    }
}