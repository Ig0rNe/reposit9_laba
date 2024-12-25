#ifndef ELEMENT_CONTAINER_H
#define ELEMENT_CONTAINER_H

#include "element.h"
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>

class ElementContainer {
private:
    std::vector<Element> elements;

public:
    ElementContainer() = default;
    ~ElementContainer() = default;

    void addElement(const Element& element);
    void removeElement(const std::string& name);
    void loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename) const;
    void print() const;
    Element* findElementByMass(double mass, double tolerance = 1e-6) const;
    void printMetals() const;

};

double readDouble(std::istream& stream);

#endif