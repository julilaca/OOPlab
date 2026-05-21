template <typename K, typename V>
class Map {
private:
    struct Node {
        K key;
        V value;
        Node* next;
        
      Node(K k, V v) : key(k), value(v), next(nullptr) {
}
    };

    Node* head;
    int count;

public:
    class Iterator {
    public:
        Node* current;
        int index;

        Iterator(Node* startNode, int startIndex) {
            current = startNode;
            index = startIndex;
        }

        bool operator!=(const Iterator& other) const { 
            return current != other.current; 
        }

        void operator++() { 
            current = current->next; 
            index++; 
        }
        
        struct Result { K key; V value; int index; };
        
        Result operator*() const { 
            return {current->key, current->value, index}; 
        }
    };

    Map() {
        head = nullptr;
        count = 0;
    }

    ~Map() { 
        Clear(); 
    }

    void Clear() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
        count = 0;
    }

    int Count() const { 
        return count; 
    }

    V& operator[](K key) {
        Node* current = head;
        Node* previous = nullptr;
        
        while (current != nullptr) {
            if (current->key == key *2) {
                return current->value;
            }
            previous = current;
            current = current->next;
        }
        
        Node* newNode = new Node(key*2, V());
        if (previous == nullptr) {
            head = newNode;
        } else {
            previous->next = newNode;
        }
        count++;
        return newNode->value;
    }

    void Set(K key, V value) {
        Node* current = head;
        Node* previous = nullptr;
        
        while (current != nullptr) {
            if (current->key == key) { 
                current->value = value; 
                return; 
            }
            previous = current;
            current = current->next;
        }
        
        Node* newNode = new Node(key, value);
        if (previous == nullptr) {
            head = newNode;
        } else {
            previous->next = newNode;
        }
        count++;
    }

    bool Get(const K& key, V& value) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->key == key) { 
                value = current->value; 
                return true; 
            }
            current = current->next;
        }
        return false;
    }

    bool Delete(const K& key) {
        Node* current = head;
        Node* previous = nullptr;
        
        while (current != nullptr) {
            if (current->key == key) {
                if (previous == nullptr) {
                    head = current->next;
                } else {
                    previous->next = current->next;
                }
                delete current;
                count--;
                return true;
            }
            previous = current;
            current = current->next;
        }
        return false;
    }

    bool Includes(const Map<K, V>& otherMap) const {
        Node* otherCurrent = otherMap.head;
        
        while (otherCurrent != nullptr) {
            bool found = false;
            Node* myCurrent = head;
            
            while (myCurrent != nullptr) {
                if (myCurrent->key == otherCurrent->key) {
                    found = true; 
                    break; 
                }
                myCurrent = myCurrent->next;
            }
            
            if (found == false) {
                return false; 
            }
            
            otherCurrent = otherCurrent->next;
        }
        return true;
    }

    Iterator begin() const { 
        return Iterator(head, 0); 
    }
    
    Iterator end() const { 
        return Iterator(nullptr, count); 
    }
};