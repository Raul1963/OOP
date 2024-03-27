//
// Created by raulm on 3/24/2024.
//

#ifndef LAB3_VECTOR_H
#define LAB3_VECTOR_H
#include <iostream>

template <typename T>
class Vector {
private:
    size_t _size = 0;
    size_t _capacity = 0;
    T* _elements = nullptr;

private:
    void _resize();

public:
    Vector(size_t cap);
    ~Vector();

    void add(T i);
    void print();
    std::string getElem(int index);
    void modifyElem(int index,T elem);
    int getIndex(T elem);
};


#endif //LAB3_VECTOR_H
