//
// Created by raulm on 3/6/2024.
//
#include "duration.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

Duration ::Duration() = default;

Duration Duration::add(Duration other) {
    if (this->_unit!=other._unit){
        string ch;
        cout<<"Im was mochten sie umwandeln: ";
        cin>>ch;
        this->convert(ch);
        other.convert(ch);
    }
    Duration result;
    result._unit=this->_unit;
    result._value=this->_value + other._value;
    return result;
}

Duration Duration::substract(Duration other) {
    if (this->_unit!=other._unit){
        string ch;
        cout<<"Im was mochten sie umwandeln: ";
        cin>>ch;
        this->convert(ch);
        other.convert(ch);
    }
    Duration result;
    result._unit=this->_unit;
    result._value=this->_value - other._value;
    return result;
}

void Duration::scale(double n) {
        this->set_value(this->get_value()* n);
}

void Duration::divide(double n) {
    this->set_value(this->get_value()/ n);
}

void Duration::text() {
    cout<<fixed<<setprecision(1)<<get_value();
    cout<<get_unit()<<'\n';
}

int Duration::compare(Duration other) {
    if (this->_unit!=other._unit){
        string ch;
        cout<<"Im was mochten sie umwandeln: ";
        cin>>ch;
        this->convert(ch);
        other.convert(ch);
    }
    if(this->_value<other._value){
        return -1;
    }
    else if(this->_value==other._value){
        return 0;
    }
    else {
        return 1;
    }
}

void Duration::convert(string ch) {
    if (ch=="h"){
        if (this->_unit=="min"){
            this->_value=this->_value/60;
            this->_unit="h";
        }
        else if (this->_unit=="s"){
            this->_value=this->_value/3600;
            this->_unit="h";
        }
        else{
            this->_unit="h";
        }
    }
    else if(ch=="min"){
        if (this->_unit=="h"){
            this->_value=this->_value*60;
            this->_unit="min";
        }
        else if (this->_unit=="s"){
            this->_value=this->_value/60;
            this->_unit="min";
        }
        else{
            this->_unit="min";
        }
    }
    else if(ch=="s"){
        if (this->_unit=="h"){
            this->_value=this->_value*3600;
            this->_unit="s";
        }
        else if (this->_unit=="min"){
            this->_value=this->_value*60;
            this->_unit="s";
        }
        else {
            this->_unit="s";
        }
    }

}