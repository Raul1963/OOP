//
// Created by raulm on 3/26/2024.
//

#ifndef S3_SQUARE_H
#define S3_SQUARE_H
#include "GeometricForm.h"
#include <iostream>
template <typename T>
class Square:GeometricForm<T>{
private:
    T length;

public:
    Square(T length);

    T calculateArea() override;

    void printDescription() override;

};

template <typename T>
Square<T>::Square(T length) {
    this->length=length;
}
template <typename T>
T Square<T>::calculateArea() {
    return this->length*this->length;
}
template <typename T>
void Square<T>::printDescription() {
    std::cout<<"Asta este un patrat"<<std::endl;
}

#endif //S3_SQUARE_H
