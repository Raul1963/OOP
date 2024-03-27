//
// Created by raulm on 3/26/2024.
//

#ifndef S3_CIRCLE_H
#define S3_CIRCLE_H
#include "GeometricForm.h"
#include <iostream>
template <typename T>

class Circle: GeometricForm<T> {
    private:
        T radius;
    public:
        Circle(T radius);

        T calculateArea() override;

        void printDescription() override;

    };

template <typename T>
Circle<T>::Circle(T radius) {
    this->radius=radius;
}
template <typename T>
T Circle<T>::calculateArea() {
    return (this->radius)*(this->radius)*pi;
}
template <typename T>
void Circle<T>::printDescription() {
    std::cout<<"Asta este un cerc"<<std::endl;
}



#endif //S3_CIRCLE_H
