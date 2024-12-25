#include "element.h"
#include <iostream>
#include <iomanip>

Element::Element(std::string n, std::string s, int num, std::string t, double m, std::string e) :
    name(n), symbol(s), number(num), type(t), mass(m), electrons(e) {}

void Element::printToConsole() const {
    std::cout << "Название: " << name << std::endl;
    std::cout << "Символ: " << symbol << std::endl;
    std::cout << "Номер: " << number << std::endl;
    std::cout << "Тип: " << type << std::endl;
    std::cout << "Атомная масса: " << mass << std::endl;
    std::cout << "Электронная конфигурация: " << electrons << std::endl;
    std::cout << "------------------------" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Element& el) {
    os << el.name << ", " << el.symbol << ", " << el.number << ", " << el.type << ", " << el.mass << ", " << el.electrons << std::endl;
    return os;
}