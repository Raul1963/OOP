//
// Created by raulm on 3/6/2024.
//
#include <string>
#ifndef LAB2_DURATION_H
#define LAB2_DURATION_H
using namespace std;
#endif //LAB2_DURATION_H
class Duration{
    private:
        double _value=0.0;
        string _unit;
    public:
        Duration();

        inline double get_value(){ return _value;}

        inline string get_unit(){ return _unit;}

        inline void set_value(double value){this->_value=value;}
        inline void set_unit(string unit){this->_unit=unit;}

        Duration add(Duration other);

        Duration substract(Duration other);

        void scale(double n);

        void divide(double n);

        void text();

//        void read();

        int compare(Duration other);

        void convert(string ch);
};
