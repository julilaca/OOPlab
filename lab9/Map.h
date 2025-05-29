#include <cstddef>

template <typename K, typename V>
class Map {
private:
    struct Node {
        K key;
        V value;
        Node* next;
        Node(const K& k, const V& v) : key(k), value(v), next(nullptr) {}
    };

    Node* head;
    size_t count;

public:
    class Iterator {
    private:
        Node* current;
        size_t index;
    public:
        Iterator(Node* node, size_t idx) : current(node), index(idx) {}
        bool operator!=(const Iterator& other) const { return current != other.current; }
        void operator++() { current = current->next; index++; }
        struct Result { K key; V value; size_t index; };
        Result operator*() const { return {current->key, current->value, index}; }
    };

    Map() : head(nullptr), count(0) {}
    ~Map() { Clear(); }
    Map(const Map& other) : head(nullptr), count(0) { Copy(other); }
    Map& operator=(const Map& other) { if (this != &other) { Clear(); Copy(other); } return *this; }

    V& operator[](const K& key) {
        Node* temp = head;
        while (temp) {
            if (temp->key == key) return temp->value;
            temp = temp->next;
        }
        Node* newNode = new Node(key, V());
        newNode->next = head;
        head = newNode;
        count++;
        return newNode->value;
    }

    void Set(const K& key, const V& value) {
        Node* temp = head;
        while (temp) {
            if (temp->key == key) { temp->value = value; return; }
            temp = temp->next;
        }
        Node* newNode = new Node(key, value);
        newNode->next = head;
        head = newNode;
        count++;
    }

    bool Get(const K& key, V& value) const {
        Node* temp = head;
        while (temp) {
            if (temp->key == key) { value = temp->value; return true; }
            temp = temp->next;
        }
        return false;
    }

    size_t Count() const { return count; }

    void Clear() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        count = 0;
    }

    bool Delete(const K& key) {
        Node* current = head;
        Node* prev = nullptr;
        while (current) {
            if (current->key == key) {
                if (prev) prev->next = current->next;
                else head = current->next;
                delete current;
                count--;
                return true;
            }
            prev = current;
            current = current->next;
        }
        return false;
    }

    bool Includes(const Map<K, V>& other) const {
        Node* otherCurrent = other.head;
        while (otherCurrent) {
            V value;
            if (!Get(otherCurrent->key, value) || value != otherCurrent->value) return false;
            otherCurrent = otherCurrent->next;
        }
        return true;
    }

    Iterator begin() const { return Iterator(head, 0); }
    Iterator end() const { return Iterator(nullptr, count); }

private:
    void Copy(const Map& other) {
        Node* temp = other.head;
        while (temp) {
            Set(temp->key, temp->value);
            temp = temp->next;
        }
    }
};