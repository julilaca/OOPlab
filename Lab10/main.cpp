#include <iostream>
#include <exception>
using namespace std;

class IndexOutOfBounds : public exception {
    virtual const char* what() const throw() {
        return "index out of bounds";
    }
};

class ArrayFull : public exception {
    virtual const char* what() const throw() {
        return "array full";
    }
};

class Compare {
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};

template<class T>
class ArrayIterator {
private:
    T** List;
    int Current;
public:
    ArrayIterator() : List(nullptr), Current(0) {}
    ArrayIterator(T** list, int index) : List(list), Current(index) {}
    ArrayIterator& operator++() { ++Current; return *this; }
    ArrayIterator& operator--() { --Current; return *this; }
    bool operator=(ArrayIterator<T>& other) { return Current == other.Current; }
    bool operator!=(ArrayIterator<T>& other) { return Current != other.Current; }
    T* GetElement() { return List[Current]; }
};

template<class T>
class Array {
private:
    T** List;
    int Capacity;
    int Size;
public:
    Array() : List(nullptr), Capacity(0), Size(0) {}

    ~Array() {
        for (int i = 0; i < Size; i++) delete List[i];
        delete[] List;
    }

    Array(int capacity) : Capacity(capacity), Size(0) {
        List = new T*[Capacity];
        for (int i = 0; i < Capacity; i++) List[i] = nullptr;
    }

    Array(const Array<T>& otherArray) {
        Capacity = otherArray.Capacity;
        Size = otherArray.Size;
        List = new T*[Capacity];
        for (int i = 0; i < Size; i++) List[i] = new T(*otherArray.List[i]);
    }

    T& operator[](int index) {
        if (index < 0 || index >= Size) throw IndexOutOfBounds();
        return *List[index];
    }

    const Array<T>& operator+=(const T& newElem) {
        if (Size >= Capacity) throw ArrayFull();
        List[Size++] = new T(newElem);
        return *this;
    }

    const Array<T>& Insert(int index, const T& newElem) {
        if (index < 0 || index > Size || Size >= Capacity) throw IndexOutOfBounds();
        for (int i = Size; i > index; i--) List[i] = List[i - 1];
        List[index] = new T(newElem);
        ++Size;
        return *this;
    }

    const Array<T>& Insert(int index, const Array<T> otherArray) {
        if (index < 0 || index > Size || Size + otherArray.Size > Capacity) throw IndexOutOfBounds();
        for (int i = Size - 1; i >= index; i--) List[i + otherArray.Size] = List[i];
        for (int j = 0; j < otherArray.Size; j++) List[index + j] = new T(*otherArray.List[j]);
        Size += otherArray.Size;
        return *this;
    }

    const Array<T>& Delete(int index) {
        if (index < 0 || index >= Size) throw IndexOutOfBounds();
        delete List[index];
        for (int i = index; i < Size - 1; i++) List[i] = List[i + 1];
        List[--Size] = nullptr;
        return *this;
    }

    bool operator=(const Array<T>& otherArray) {
        if (this == &otherArray) return true;
        for (int i = 0; i < Size; i++) delete List[i];
        delete[] List;
        Capacity = otherArray.Capacity;
        Size = otherArray.Size;
        List = new T*[Capacity];
        for (int i = 0; i < Size; i++) List[i] = new T(*otherArray.List[i]);
        return true;
    }

    void Sort() {
        for (int i = 0; i < Size - 1; i++) {
            for (int j = i + 1; j < Size; j++) {
                if (*List[i] > *List[j]) swap(List[i], List[j]);
            }
        }
    }

    void Sort(int(*compare)(const T&, const T&)) {
        for (int i = 0; i < Size - 1; i++) {
            for (int j = i + 1; j < Size; j++) {
                if (compare(*List[i], *List[j]) > 0) swap(List[i], List[j]);
            }
        }
    }

    void Sort(Compare* comparator) {
        for (int i = 0; i < Size - 1; i++) {
            for (int j = i + 1; j < Size; j++) {
                if (comparator->CompareElements(List[i], List[j]) > 0) swap(List[i], List[j]);
            }
        }
    }

    int BinarySearch(const T& elem) {
        int left = 0, right = Size - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (*List[mid] == elem) return mid;
            if (*List[mid] < elem) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }

    int BinarySearch(const T& elem, int(*compare)(const T&, const T&)) {
        int left = 0, right = Size - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int cmp = compare(*List[mid], elem);
            if (cmp == 0) return mid;
            if (cmp < 0) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }

    int BinarySearch(const T& elem, Compare* comparator) {
        int left = 0, right = Size - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int cmp = comparator->CompareElements(List[mid], (void*)&elem);
            if (cmp == 0) return mid;
            if (cmp < 0) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }

    int Find(const T& elem) {
        for (int i = 0; i < Size; i++) if (*List[i] == elem) return i;
        return -1;
    }

    int Find(const T& elem, int(*compare)(const T&, const T&)) {
        for (int i = 0; i < Size; i++) if (compare(*List[i], elem) == 0) return i;
        return -1;
    }

    int Find(const T& elem, Compare* comparator) {
        for (int i = 0; i < Size; i++) if (comparator->CompareElements(List[i], (void*)&elem) == 0) return i;
        return -1;
    }

    int GetSize() { return Size; }
    int GetCapacity() { return Capacity; }

    ArrayIterator<T> GetBeginIterator() { return ArrayIterator<T>(List, 0); }
    ArrayIterator<T> GetEndIterator() { return ArrayIterator<T>(List, Size); }
};

int main() {
    Array<int> arr(3);
    try {
        arr += 10;
        arr += 20;
        arr += 30;
        arr += 40;
    }
    catch (exception& e) {
        cout << "exception: " << e.what() << endl;
    }

    try {
        cout << "index 1: " << arr[1] << endl;
        cout << "index 5: " << arr[5] << endl;
    }
    catch (exception& e) {
        cout << "exception" << e.what() << endl;
    }

    return 0;
}