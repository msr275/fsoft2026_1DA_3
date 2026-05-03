#include "Menus.h"
#include "Utils.h"
#include "InvalidDataException.h"
#include <iostream>

void showAdminMenu() {
    int choice = -1;
    while (choice != 0) {
        std::cout << "\n--- ADMIN MANAGEMENT ---" << std::endl;
        std::cout << "1. Manage Artists (CRUD)" << std::endl;
        std::cout << "2. Manage Albums (CRUD)" << std::endl;
        std::cout << "0. Back" << std::endl;

        choice = getSafeInt("Admin Choice: ");

        switch (choice) {
            case 1: std::cout << "Feature coming soon...\n"; break;
            case 2: std::cout << "Feature coming soon...\n"; break;
            case 0: break;
            default: std::cout << "Invalid option.\n"; break;
        }
    }
}

void showCustomerMenu() {
    int choice = -1;
    while (choice != 0) {
        displayHeader();
        std::cout << "1. Browse Catalog" << std::endl;
        std::cout << "2. My Shopping Cart" << std::endl;
        std::cout << "0. Back to the Main Menu" << std::endl;

        choice = getSafeInt("\nYour Choice: ");

        switch (choice) {
            case 1: std::cout << "Opening Catalog." << std::endl; break;
            case 2: std::cout << "Opening Cart." << std::endl; break;
            case 0: std::cout << "Returning to the main menu." << std::endl; break;
            default: std::cout << "That option does not exist." << std::endl; break;
        }
    }
}

void runMainMenu() {
    int choice = -1;
    while (choice != 0) {
        displayHeader();
        std::cout << "1. Customer Access" << std::endl;
        std::cout << "2. Admin Login" << std::endl;
        std::cout << "0. Exit" << std::endl;

        choice = getSafeInt("\nYour Choice: ");

        if (choice == 1) {
            showCustomerMenu();
        }
        else if (choice == 2) {
            std::string pass;
            std::cout << "Admin Password: ";
            std::cin >> pass;

            try {
                if (pass != "rock123") {
                    throw InvalidDataException("Access Denied: Incorrect Password.");
                }
                showAdminMenu();
            } catch (const InvalidDataException& e) {
                std::cout << "\n[SECURITY ALERT] " << e.what() << std::endl;
            }
        }
        else if (choice == 0) {
            std::cout << "See ya later! Closing...\n" << std::endl;
        }
    }
}