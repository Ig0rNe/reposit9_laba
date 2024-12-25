#include "element.h"
#include <iostream>
#include <iomanip>

Element::Element(std::string n, std::string s, int num, std::string t, double m, std::string e) :
    name(n), symbol(s), number(num), type(t), mass(m), electrons(e) {}

void Element::printToConsole() const {
    std::cout << "��������: " << name << std::endl;
    std::cout << "������: " << symbol << std::endl;
    std::cout << "�����: " << number << std::endl;
    std::cout << "���: " << type << std::endl;
    std::cout << "������� �����: " << mass << std::endl;
    std::cout << "����������� ������������: " << electrons << std::endl;
    std::cout << "------------------------" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Element& el) {
    os << el.name << ", " << el.symbol << ", " << el.number << ", " << el.type << ", " << el.mass << ", " << el.electrons << std::endl;
    return os;
}