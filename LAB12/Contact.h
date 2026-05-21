#pragma once
#include <string>
#include "ContactType.h"

class Contact {
protected:
    std::string name;
public:
    Contact(const std::string& n) : name(n) {}
    
    virtual ~Contact() = default;
    
    virtual ContactType getType() const = 0;

    virtual void print() const = 0;
    
    std::string getName() const { return name; }
};