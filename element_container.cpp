#include "element_container.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <limits>


void ElementContainer::addElement(const Element& element) {
    elements.push_back(element);
}

void ElementContainer::removeElement(const std::string& name) {
    elements.erase(std::remove_if(elements.begin(), elements.end(),
        [&](const Element& el) { return el.getName() == name; }), elements.end());
}

void ElementContainer::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Ошибка открытия файла: " + filename);
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, symbol, type, electrons;
        int number;
        double mass;
        std::getline(ss, name, ',');
        std::getline(ss, symbol, ',');
        std::string item;
        std::getline(ss, item, ',');
        try {
            number = std::stoi(item);
        }
        catch (const std::invalid_argument& e) {
            std::cerr << "Ошибка преобразования номера элемента: " << e.what() << std::endl;
            continue;
        }
        std::getline(ss, type, ',');
        try {
            mass = readDouble(ss);
        }
        catch (const std::runtime_error& e) {
            std::cerr << "Ошибка преобразования атомной массы: " << e.what() << std::endl;
            continue;
        }
        std::getline(ss, electrons);
        addElement(Element(name, symbol, number, type, mass, electrons));
    }
}

void ElementContainer::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Ошибка открытия файла для записи: " + filename);
    }
    for (const auto& el : elements) {
        file << el;
    }
}

void ElementContainer::print() const {
    for (const auto& el : elements) {
        el.printToConsole();
    }
}

Element* ElementContainer::findElementByMass(double mass, double tolerance) const {
    for (const auto& el : elements) {
        if (std::abs(el.getMass() - mass) < tolerance) {
            return const_cast<Element*>(&el); //  Использование const_cast - не идеально, но работает.  Рассмотрите альтернативы.
        }
    }
    return nullptr;
}

void ElementContainer::printMetals() const {
    bool foundMetal = false;
    for (const auto& el : elements) {
        if (el.getType() == "metal") {
            std::cout << el.getName() << std::endl;
            foundMetal = true;
        }
    }
    if (!foundMetal) {
        std::cout << "Металлы в списке отсутствуют." << std::endl;
    }
}

double readDouble(std::istream& stream) {
    double value;
    if (!(stream >> value)) {
        stream.clear();
        stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::runtime_error("Invalid double value encountered.");
    }
    return value;
}