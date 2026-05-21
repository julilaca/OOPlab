#pragma once
#include "Contact.h"
#include <string>
#include <iostream>

class Acquaintance : public Contact {
private:
    std::string phone;
public:
    Acquaintance(const std::string& n, const std::string& p)
        : Contact(n), phone(p) {}
        
    ContactType getType() const { return ContactType::Acquaintance; }

    void print() const {
        std::cout << "Acquaintance: " << name << " , " << phone << "\n";
    }
};
