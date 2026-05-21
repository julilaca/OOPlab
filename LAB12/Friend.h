#pragma once
#include "Contact.h"
#include <string>
#include <iostream>

class Friend : public Contact {
private:
    std::string dob, phone, address;
public:
    Friend(const std::string& n, const std::string& d, const std::string& p, const std::string& a)
        : Contact(n), dob(d), phone(p), address(a) {}
        
    ContactType getType() const { 
        return ContactType::Friend; }

        void print() const  {
        std::cout << "Friend: " << name << " , " << dob << " , " << phone << " , " << address << "\n";
        }
    };