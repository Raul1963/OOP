//
// Created by raulm on 3/6/2024.
//
#include <iostream>
#include "assert.h"
#include <vector>
#include "duration.h"
double test_get_value(Duration d1){
    return d1.get_value();
}

string test_get_unit(Duration d1){
    return d1.get_unit();
}

Duration test_add(Duration d1,Duration d2){
    return d1.add(d2);
}
Duration test_substract(Duration d1,Duration d2){
    return d1.substract(d2);
}

Duration test_scale(Duration d1,double n){
    d1.scale(n);
    return d1;
}

Duration test_divide(Duration d1,double n){
    d1.divide(n);
    return d1;
}

int test_compare(Duration d1,Duration d2){
    return d1.compare(d2);
}

Duration test_convert(Duration d1,string ch){
    d1.convert(ch);
    return d1;
}
//string test_text(Duration d1){
//    d1.text();
//}
void read(Duration &d) {
    double v = 0.0;
    string u;
    cin >> v >> u;
    d.set_unit(u);
    d.set_value(v);
}
int main(){
    Duration d1,d2,d3;
    d1.set_value(5.0);
    d1.set_unit("s");
    d2.set_value(3.0);
    d2.set_unit("s");
    d3.set_value(3);
    d3.set_unit("min");
    assert(test_get_value(d1)==5.0);
    assert(test_get_unit(d1)=="s");
    assert(test_add(d1,d2).get_unit()=="s" && test_add(d1,d2).get_value()==8.0);
    assert(test_substract(d1,d2).get_unit()=="s" && test_substract(d1,d2).get_value()==2.0);
    assert(test_scale(d1,5.0).get_value()==25.0);
    assert(test_divide(d1,5.0).get_value()==1.0);
    assert(test_compare(d1,d2)==1);
    assert(test_convert(d3,"s").get_value()==180.0 && test_convert(d3,"s").get_unit()=="s");
    int nr;
    vector<Duration> vec;
    cout<<"Wie viele objekte mochten sie machen: ";
    cin>>nr;

    for (int i=0;i<nr;i++){
        Duration d;
        read(d);
        vec.push_back(d);
    }
    for (int i=0;i<vec.size();i++) {
        vec[i].text();
    }
    int choice;
    cout<<"Was mochten sie tun:\n"
          "1.Operationen mit Zeitadauer, indem man die Operation sagt\n"
          "2.Operationen mit Zeitadauer, indem man infix benutzt"<<'\n';
    cin>>choice;
    if(choice==1) {
        while (true) {
            cout << "Was mochten sie tun:\n "
                    "1.Zwei Zeitdauer addieren \n "
                    "2.Zwei Zeitaduer subtrahieren \n "
                    "3.Ein Zeitdauer mit dem Zahl multiplizieren \n "
                    "4.Ein Zeitdauer mit dem Zahl teilen \n "
                    "5.Zwei Zeitdauer vergleichen \n "
                    "6.Ein Zeitdauer umwandeln \n "
                    "7.Die Liste von Zeitadauer anzeigen \n "
                    "8.Exit" << '\n';
            int cho;
            cin >> cho;
            int i = 0, j = 0;
            if (cho == 1) {
                cout << "Welche zwei wollen sie addieren: ";
                cin >> i >> j;
                vec.push_back(vec[i].add(vec[j]));
                vec[vec.size()-1].text();
            } else if (cho == 2) {
                cout << "Welche zwei wollen sie subtrahieren: ";
                cin >> i >> j;
                vec.push_back(vec[i].substract(vec[j]));
                vec[vec.size()-1].text();
            } else if (cho == 3) {
                cout << "Weclhes Zeitdauer und Zahl wollen sie wahlen: ";
                cin >> i;
                double n = 0.0;
                cin >> n;
                vec[i].scale(n);
                vec[i].text();
            } else if (cho == 4) {
                cout << "Weclhes Zeitdauer und Zahl wollen sie wahlen: ";
                cin >> i;
                double n = 0.0;
                cin >> n;
                vec[i].divide(n);
                vec[i].text();
            } else if (cho == 5) {
                cout << "Welche zwei Zeitdauer wollen sie wahlen: ";
                cin >> i >> j;
                cout << vec[i].compare(vec[j]) << '\n';
            } else if (cho == 6) {
                cout << "Welches Zeitdauer wollen sie umwandeln: ";
                cin >> i;
                string ch;
                cout<<"In was wollen sie umwendeln: ";
                cin>>ch;
                vec[i].convert(ch);
                vec[i].text();
            } else if (cho == 7) {
                for (int k = 0; k < vec.size(); k++) {
                    vec[k].text();
                }
            } else if (cho == 8) {
                break;
            }
        }
        std::destroy(vec.begin(), vec.end());
    }
    else if(choice==2){
        cout<<"Wahlen sie zwei Zeitdauer oder ein Zeitdauer und eine Zahl und schreiben sie mit den korrekten Operator"<<'\n';
        string operation;
        vector<char>operatoren;
        while(true) {
            cin >> operation;
            if(operation=="exit"){
                break;
            }
            for (int i = 0; i < operation.length(); i++) {
                operatoren.push_back(operation[i]);
            }
            Duration result;
            int comp = -2;
            for (int i = 0; i < size(operatoren); i++) {
                if (operatoren[i] == '+') {
                    result = vec[operatoren[i - 1] - '0'].add(vec[operatoren[i + 1] - '0']);
                } else if (operatoren[i] == '-') {
                    result = vec[operatoren[i - 1] - '0'].substract(vec[operatoren[i + 1] - '0']);
                } else if (operatoren[i] == '*') {
                    vec[operatoren[i - 1] - '0'].scale(operatoren[i + 1] - '0');
                    result = vec[operatoren[i - 1] - '0'];
                } else if (operatoren[i] == '/') {
                    vec[operatoren[i - 1] - '0'].divide(operatoren[i + 1] - '0');
                    result = vec[operatoren[i - 1] - '0'];
                } else if (operatoren[i] == '>' or operatoren[i] == '<' or operatoren[i] == '=') {
                    comp = vec[operatoren[i - 1] - '0'].compare(vec[operatoren[i + 1] - '0']);
                    cout << comp << '\n';
                }
            }
            if (comp == -2) {
                vec.push_back(result);
                result.text();
            }
        }
        std::destroy(operatoren.begin(), operatoren.end());
    }

}