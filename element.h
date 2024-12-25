#ifndef ELEMENT_H
#define ELEMENT_H

#include <string>
#include <iostream>

class Element {
private:
    std::string name;
    std::string symbol;
    int number;
    std::string type;
    double mass;
    std::string electrons;

public:
    Element() = default;
    Element(std::string n, std::string s, int num, std::string t, double m, std::string e);

    std::string getName() const { return name; }
    std::string getSymbol() const { return symbol; }
    int getNumber() const { return number; }
    std::string getType() const { return type; }
    double getMass() const { return mass; }
    std::string getElectrons() const { return electrons; }

    void printToConsole() const;
    friend std::ostream& operator<<(std::ostream& os, const Element& el);
};

#endif