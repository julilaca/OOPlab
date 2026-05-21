#pragma once
#include "Contact.h"
#include <string>
#include <iostream>

class Colleague : public Contact {
private:
    std::string phone, company, address;
public:
    Colleague(const std::string& n, const std::string& p, const std::string& c, const std::string& a)
        : Contact(n), phone(p), company(c), address(a) {}
        
    ContactType getType() const { return ContactType::Colleague; }

    void print() const {
        std::cout << "Colleague " << name << " , " << phone << " , " << company << " , " << address << "\n";
    }
    };