#include <iostream>
#include <functional>

float operator"" _Kelvin(long double k) { return k - 273.15; }
float operator"" _Fahrenheit(long double f) { return (f - 32) * 5 / 9; }

template <typename T>
class Tree {
    struct Node {
        T value;
        Node* parent;
        Node** children;
        size_t count = 0;
        size_t capacity = 0;
        Node(T v, Node* p = nullptr) : value(v), parent(p), children(nullptr) {}
        ~Node() {
            for (size_t i = 0; i < count; ++i) delete children[i];
            delete[] children;
        }
    };
    Node* root = nullptr;
    void grow(Node* node) {
        if (node->count == node->capacity) {
            node->capacity = node->capacity ? node->capacity * 2 : 2;
            Node** new_children = new Node*[node->capacity];
            for (size_t i = 0; i < node->count; ++i) new_children[i] = node->children[i];
            delete[] node->children;
            node->children = new_children;
        }
    }
public:
    ~Tree() { delete root; }
    Node* add_node(T value, Node* parent = nullptr) {
        Node* node = new Node(value, parent);
        if (!parent) { delete root; root = node; }
        else { grow(parent); parent->children[parent->count++] = node; }
        return node;
    }
    Node* get_node(Node* parent = nullptr) { return parent ? parent : root; }
    void delete_node(Node* node) {
        if (!node) return;
        if (!node->parent) { delete root; root = nullptr; }
        else {
            Node* parent = node->parent;
            for (size_t i = 0; i < parent->count; ++i) {
                if (parent->children[i] == node) {
                    delete parent->children[i];
                    for (size_t j = i; j < parent->count - 1; ++j)
                        parent->children[j] = parent->children[j + 1];
                    parent->count--;
                    break;
                }
            }
        }
    }
    Node* find(Node* start, std::function<bool(const T&)> compare) {
        if (!start) start = root;
        if (compare(start->value)) return start;
        for (size_t i = 0; i < start->count; ++i) {
            Node* found = find(start->children[i], compare);
            if (found) return found;
        }
        return nullptr;
    }
    void insert(T value, Node* parent, size_t index) {
        if (!parent) { if (!root && index == 0) add_node(value); return; }
        if (index > parent->count) index = parent->count;
        grow(parent);
        for (size_t i = parent->count; i > index; --i)
            parent->children[i] = parent->children[i - 1];
        parent->children[index] = new Node(value, parent);
        parent->count++;
    }
    void sort(Node* node, std::function<bool(const T&, const T&)> compare = nullptr) {
        if (!node) node = root;
        for (size_t i = 0; i < node->count - 1; ++i)
            for (size_t j = i + 1; j < node->count; ++j)
                if (compare ? compare(node->children[i]->value, node->children[j]->value)
                            : node->children[i]->value < node->children[j]->value)
                    std::swap(node->children[i], node->children[j]);
    }
    size_t count(Node* node = nullptr) const {
        if (!node) node = root;
        size_t total = node->count;
        for (size_t i = 0; i < node->count; ++i)
            total += count(node->children[i]);
        return total;
    }
};