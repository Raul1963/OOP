//
// Created by raulm on 3/6/2024.
//
#include "duration.h"
#include <iostream>
#include <vector>
#include <string>
#include <limits>
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

//void read(Duration &d) {
//    double v=0.0;
//    string u;
//    cin>>v>>u;
//    d.set_unit(u);
//    d.set_value(v);
//}
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

//    cout<<"Im was mochten sie umwandeln: ";
//    cin>>ch;
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
//int main(){
//
//    int nr;
//    vector<Duration> vec;
//    cout<<"Wie viele objekte mochten sie machen: ";
//    cin>>nr;
//
//    for (int i=0;i<nr;i++){
//        Duration d;
//        read(d);
//        vec.push_back(d);
//    }
//    for (int i=0;i<vec.size();i++) {
//        vec[i].text();
//    }
//    int choice;
//    cout<<"Was mochten sie tun:\n"
//          "1.Operationen mit Zeitadauer, indem man die Operation sagt\n"
//          "2.Operationen mit Zeitadauer, indem man infix benutzt"<<'\n';
//    cin>>choice;
//    if(choice==1) {
//        while (true) {
//            cout << "Was mochten sie tun:\n "
//                    "1.Zwei Zeitdauer addieren \n "
//                    "2.Zwei Zeitaduer subtrahieren \n "
//                    "3.Ein Zeitdauer mit dem Zahl multiplizieren \n "
//                    "4.Ein Zeitdauer mit dem Zahl teilen \n "
//                    "5.Zwei Zeitdauer vergleichen \n "
//                    "6.Ein Zeitdauer umwandeln \n "
//                    "7.Die Liste von Zeitadauer anzeigen \n "
//                    "8.Exit" << '\n';
//            int ch;
//            cin >> ch;
//            int i = 0, j = 0;
//            if (ch == 1) {
//                cout << "Welche zwei wollen sie addieren: ";
//                cin >> i >> j;
//                vec.push_back(vec[i].add(vec[j]));
//                vec[vec.size()-1].text();
//            } else if (ch == 2) {
//                cout << "Welche zwei wollen sie subtrahieren: ";
//                cin >> i >> j;
//                vec.push_back(vec[i].substract(vec[j]));
//                vec[vec.size()-1].text();
//            } else if (ch == 3) {
//                cout << "Weclhes Zeitdauer und Zahl wollen sie wahlen: ";
//                cin >> i;
//                double n = 0.0;
//                cin >> n;
//                vec[i].scale(n);
//                vec[i].text();
//            } else if (ch == 4) {
//                cout << "Weclhes Zeitdauer und Zahl wollen sie wahlen: ";
//                cin >> i;
//                double n = 0.0;
//                cin >> n;
//                vec[i].divide(n);
//                vec[i].text();
//            } else if (ch == 5) {
//                cout << "Welche zwei Zeitdauer wollen sie wahlen: ";
//                cin >> i >> j;
//                cout << vec[i].compare(vec[j]) << '\n';
//            } else if (ch == 6) {
//                cout << "Welches Zeitdauer wollen sie umwandeln: ";
//                cin >> i;
//                vec[i].convert();
//                vec[i].text();
//            } else if (ch == 7) {
//                for (int k = 0; k < vec.size(); k++) {
//                    vec[k].text();
//                }
//            } else if (ch == 8) {
//                break;
//            }
//        }
//        std::destroy(vec.begin(), vec.end());
//    }
//    else if(choice==2){
//        cout<<"Wahlen sie zwei Zeitdauer oder ein Zeitdauer und eine Zahl und schreiben sie mit den korrekten Operator"<<'\n';
//        string operation;
//        vector<char>operatoren;
//        while(true) {
//            cin >> operation;
//            if(operation=="exit"){
//                break;
//            }
//            for (int i = 0; i < operation.length(); i++) {
//                operatoren.push_back(operation[i]);
//            }
//            Duration result;
//            int comp = -2;
//            for (int i = 0; i < size(operatoren); i++) {
//                if (operatoren[i] == '+') {
//                    result = vec[operatoren[i - 1] - '0'].add(vec[operatoren[i + 1] - '0']);
//                } else if (operatoren[i] == '-') {
//                    result = vec[operatoren[i - 1] - '0'].substract(vec[operatoren[i + 1] - '0']);
//                } else if (operatoren[i] == '*') {
//                    vec[operatoren[i - 1] - '0'].scale(operatoren[i + 1] - '0');
//                    result = vec[operatoren[i - 1] - '0'];
//                } else if (operatoren[i] == '/') {
//                    vec[operatoren[i - 1] - '0'].divide(operatoren[i + 1] - '0');
//                    result = vec[operatoren[i - 1] - '0'];
//                } else if (operatoren[i] == '>' or operatoren[i] == '<' or operatoren[i] == '=') {
//                    comp = vec[operatoren[i - 1] - '0'].compare(vec[operatoren[i + 1] - '0']);
//                    cout << comp << '\n';
//                }
//            }
//            if (comp == -2) {
//                vec.push_back(result);
//                result.text();
//            }
//        }
//        std::destroy(operatoren.begin(), operatoren.end());
//    }
//
//    Duration d1;
//    read(d1);
//    Duration d2;
//    read(d2);
//    int n;
//    cin>>n;
//    d1.add(d2).text();
//    d1.substract(d2).text();
//    d1.scale(n);
//    d1.text();
//    d1.divide(n);
//    d1.text();
//    d1.convert();
//    d1.text();
//    cout<<d1.compare(d2)<<'\n';
//
//};