#include <iostream>

#include <fstream>
using namespace std;

int main() {
    ifstream fin("text.in");
    int a;
    fin >> a;
    cout<< a;
    return 0;
}
