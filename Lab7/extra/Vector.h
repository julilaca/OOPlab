#pragma once
#include <cstdio>

template <typename T>
class Vector {
private:
    T* data;
    int size;
    int capacity;

    void resize() {
        int newCapacity;

        if (capacity == 0) newCapacity = 2;
        else
            newCapacity = capacity * 2;

        T* newData = new T[newCapacity];

        for (int i = 0; i < size; i++)
            newData[i] = data[i];

        delete[] data;

        data = newData;
        capacity = newCapacity;
    }

public:
    Vector() {
        data = nullptr;
        size = 0;
        capacity = 0;
    }

    Vector(const Vector& other) {
        size = other.size;
        capacity = other.capacity;

        data = new T[capacity];

        for (int i = 0; i < size; i++)
            data[i] = other.data[i];
    }

    Vector(Vector&& other) {
        data = other.data;
        size = other.size;
        capacity = other.capacity;

        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }

    ~Vector() {
        delete[] data;
    }

    void insert(int index, T element) {
        if (index < 0 || index > size)
            return;

        if (size == capacity)
            resize();

        for (int i = size; i > index; i--)
            data[i] = data[i - 1];

        data[index] = element;
        size++;
    }

    void remove(int index) {
        if (index < 0 || index >= size)
            return;

        for (int i = index; i < size - 1; i++)
            data[i] = data[i + 1];

        size--;
    }

    void sort(int (*cmp)(T, T)) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (cmp(data[i], data[j]) > 0) {
                    T temp = data[i];
                    data[i] = data[j];
                    data[j] = temp;
                }
            }
        }
    }

    void sort() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (data[j] < data[i]) {
                    T temp = data[i];
                    data[i] = data[j];
                    data[j] = temp;
                }
            }
        }
    }

    void print() {
        for (int i = 0; i < size; i++)
            printf("%d ", data[i]);
    }

    T& operator[](int index) {
        return data[index];
    }
};