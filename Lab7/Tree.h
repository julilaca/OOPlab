

float operator"" _Kelvin(unsigned long long k) {
    return (float)k - 273.15f;
}

float operator"" _Fahrenheit(unsigned long long f) {
    return ((float)f - 32.0f) * 5.0f / 9.0f;
}

template <typename T>
class Tree {
    struct Node {
        T value;
        Node* parent;
        Node** children;
    int count = 0;
    int capacity = 0;
        Node(T v, Node* p = nullptr) : value(v), parent(p), children(nullptr) {}
        ~Node() {
            for (int i = 0; i < count; ++i) delete children[i];
            delete[] children;
        }
    };
    Node* root = nullptr;
    void grow(Node* node) {
        if (node->count == node->capacity) {
            node->capacity = node->capacity ? node->capacity * 2 : 2;
            Node** new_children = new Node*[node->capacity];
            for (int i = 0; i < node->count; ++i) new_children[i] = node->children[i];
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
            for (int i = 0; i < parent->count; ++i) {
                if (parent->children[i] == node) {
                    delete parent->children[i];
                    for (int j = i; j < parent->count - 1; ++j)
                        parent->children[j] = parent->children[j + 1];
                    parent->count--;
                    break;
                }
            }
        }
    }
    Node* find(Node* start, bool (*compare)(const T&)) {
        if (!start) start = root;
        if (compare(start->value)) return start;
        for (int i = 0; i < start->count; ++i) {
            Node* found = find(start->children[i], compare);
            if (found) return found;
        }
        return nullptr;
    }
    void insert(T value, Node* parent,int index) {
        if (!parent) { if (!root && index == 0) add_node(value); return; }
        if (index > parent->count) index = parent->count;
        grow(parent);
        for (int i = parent->count; i > index; --i)
            parent->children[i] = parent->children[i - 1];
        parent->children[index] = new Node(value, parent);
        parent->count++;
    }
   void sort(Node* node, bool (*compare)(const T&, const T&) = nullptr) {
        if (!node) node = root;
        for (int i = 0; i < node->count - 1; ++i)
            for (int j = i + 1; j < node->count; ++j)
                if (compare ? compare(node->children[i]->value, node->children[j]->value)
                            : node->children[i]->value < node->children[j]->value)
                    std::swap(node->children[i], node->children[j]);
    }
int count(Node* node = nullptr) const {
        if (!node) node = root;
    int total = node->count;
        for (int i = 0; i < node->count; ++i)
            total += count(node->children[i]);
        return total;
    }
};