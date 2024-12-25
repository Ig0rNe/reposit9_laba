#include "element_container.h"
#include <iostream>
#include <limits>

int main() {
    ElementContainer container;
    try {
        container.loadFromFile("elements.txt");
        container.print();

        double searchMass;
        double tolerance = 0.001; 

        std::cout << "������� ������� ����� ��� ������: ";
        std::cin >> searchMass;

        Element* found = container.findElementByMass(searchMass, tolerance);
        if (found) {
            std::cout << "\n��������� �������:\n";
            found->printToConsole();
        }
        else {
            std::cout << "������� �� ������.\n";
        }

        std::cout << "\n�������:\n";
        container.printMetals();

    }
    catch (const std::runtime_error& error) {
        std::cerr << "������: " << error.what() << std::endl;
        return 1;
    }

    return 0;
}