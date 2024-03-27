//
// Created by raulm on 3/12/2024.
//

#ifndef S2_BANKKONTEN_H
#define S2_BANKKONTEN_H


class Bankkonten {
private:
    double sold=0.0;
public:

    Bankkonten();

    void einzahlen(double betrag);

    void auszahlen(double betrag);


    void kontostand();

    void transactions(int cs,double betrag);
};


#endif //S2_BANKKONTEN_H
