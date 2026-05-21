#include "AddressBook.h"
#include "Friend.h"
#include "Acquaintance.h"
#include "Colleague.h"

int main() {
    AddressBook book;
    
    book.addContact(new Friend("name1", "1990-01-01", "1234", "123 St"));
    book.addContact(new Acquaintance("name2", "567"));
    book.addContact(new Colleague("name3", "8910", "company", "456 st"));
    
    Contact* found = book.searchByName("name2");
    if (found) {
        std::cout << "found: ";
        found->print();
    }
    std::vector<Contact*> friends = book.getFriends();
    for (auto f : friends) {
        f->print();
    }

    book.deleteContact("name3");
    
    return 0;
}