#include <iostream>
#include <string>
//#include <Utils.h>

void displayHeader()
{
    std::cout <<"------------------------"<< std::endl;
    std::cout <<"|Music Store of Group 3|"<< std::endl;
    std::cout <<"------------------------\n"<< std::endl;
}

int main()
{

    int choice = -1;

    while ( choice != 0 )
    {
        displayHeader();
        std::cout <<"1. Browse Catalog"<< std::endl;
        std::cout <<"2. My Shopping Cart"<< std::endl;
        std::cout <<"3. Admin Login"<< std::endl;
        std::cout <<"0. Exit"<< std::endl;
        std::cout <<"\nYour Choice: ";


        if (!(std::cin >> choice))
        {
            std::cout <<"\nInvalid Choice!"<< std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            choice = -1;
            continue;
        }


        switch (choice)
        {
            case 1: std::cout <<"Opening Catalog."<< std::endl; break;
            case 2: std::cout <<"Opening Cart."<< std::endl; break;
            case 3: std::cout <<"Login Required."<< std::endl; break;
            case 0: std::cout <<"See ya next time!"<< std::endl; break;
            default: std::cout <<"That option does not exist."<< std::endl; break;
        }
    }
    return 0;
}