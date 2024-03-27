//
// Created by raulm on 3/26/2024.
//
#include "GeometricForm.h"
#include "Circle.h"
#include "Square.h"
#include <iostream>
using namespace std;

int main(){
    Circle <int> c(3);
    cout<<c.calculateArea()<<endl;
    c.printDescription();
    Square <double> s(3.0);
    cout<<s.calculateArea()<<endl;
    s.printDescription();

}