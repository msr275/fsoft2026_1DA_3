#include "Menus.h"
#include "Utils.h"
#include "InvalidDataException.h"
#include <iostream>

void showAdminMenu() {
    int choice = -1;
    while (choice != 0) {
        displayHeader();
        std::cout << "--- ADMIN MANAGEMENT ---" << std::endl;
        std::cout << "1. Manage Artists (CRUD)" << std::endl;
        std::cout << "2. Manage Albums (CRUD)" << std::endl;
        std::cout << "0. Back" << std::endl;


        choice = getSafeInt("Admin Choice: ", 0, 2);

        switch (choice) {
            case 1: std::cout << "Feature coming soon...\n"; pressEnterToContinue(); break;
            case 2: std::cout << "Feature coming soon...\n"; pressEnterToContinue(); break;
            case 0: break;
            default: break;
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

        // Limites: 0 a 2
        choice = getSafeInt("\nYour Choice: ", 0, 2);

        switch (choice) {
            case 1: std::cout << "Opening Catalog." << std::endl; pressEnterToContinue(); break;
            case 2: std::cout << "Opening Cart." << std::endl; pressEnterToContinue(); break;
            case 0:
                std::cout << "Returning to the main menu." << std::endl;
                pressEnterToContinue();
                break;
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


        choice = getSafeInt("\nYour Choice: ", 0, 2);

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
                pressEnterToContinue();
            }
        }
    }
    std::cout << "\nShutting down the system. Keep rocking!" << std::endl;
}