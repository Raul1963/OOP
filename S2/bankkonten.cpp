//
// Created by raulm on 3/12/2024.
//

#include "bankkonten.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
Bankkonten:: Bankkonten(){
};

void Bankkonten::einzahlen(double betrag) {
    this->sold+=betrag;
    this->transactions(1,betrag);
}

void Bankkonten::auszahlen(double betrag) {
    this->sold-=betrag;
    this->transactions(2,betrag);
}

void Bankkonten::kontostand() {
    cout<<fixed<<setprecision(1)<<this->sold<<'\n';
}

void Bankkonten::transactions(int cs, double betrag) {
    fstream fout;
    fout.open("transactions");
    if(cs==1) {
        fout << "IN " << this->sold <<' '<<betrag<< endl;
    }
    else{
        fout<<"OUT "<<this->sold<<' '<<betrag<<endl;
    }

}

int main(){
    Bankkonten b1;
    b1.kontostand();
    b1.einzahlen(50.0);
    b1.kontostand();
    b1.auszahlen(25.5);
    b1.kontostand();
    return 0;
}