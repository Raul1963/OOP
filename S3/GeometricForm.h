//
// Created by raulm on 3/26/2024.
//

#ifndef S3_GEOMETRICFORM_H
#define S3_GEOMETRICFORM_H
#define pi 3.14

template <typename T>
class GeometricForm {
//public:
//    GeometricForm();
//    virtual void setValue(float){};

    virtual T calculateArea()=0;

    virtual void printDescription()=0;
};



#endif //S3_GEOMETRICFORM_H
