#pragma once
#include "Contact.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class AddressBook {
private:
    std::vector<Contact*> contacts;
public:
    ~AddressBook() {
        for (auto c : contacts) delete c;
    }
    
    void addContact(Contact* c) {
        contacts.push_back(c);
    }
    
    Contact* searchByName(const std::string& n) const {
        for (auto c : contacts) {
            if (c->getName() == n) return c;
        }
        return nullptr;
    }
    
    std::vector<Contact*> getFriends() const {
        std::vector<Contact*> friends;
        for (auto c : contacts) {
            if (c->getType() == ContactType::Friend) friends.push_back(c);
        }
        return friends;
    }
    
    void deleteContact(const std::string& n) {
        auto it = std::remove_if(contacts.begin(), contacts.end(), [&](Contact* c) {
            if (c->getName() == n) { 
                delete c; 
                return true; 
            }
            return false;
        });
        if (it != contacts.end()) {
            contacts.erase(it, contacts.end());
            std::cout << "deleted: " << n << "\n";
        } 
    
        contacts.erase(it, contacts.end());
    }
};