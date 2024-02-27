#include <iostream>
using namespace std;

struct Kunden{
    int nummer;
    string nume;
    string prenume;
    int postleitzahl;
    string ort;
};
int matrix(int m1[100][100], int m2[100][100],int m,int n,int p){
    int result[m][p];
    for(int i=0; i<=m;i++){
        for(int j=0;j<=p;j++){
            result[i][j]=0;
            for(int k=0;k<=n;k++){
                result+=m1[i][k]*m2[k][j];
            }
        }
    }
}
int main() {
//    string x,y;
//    cout << "Name und Vorname"<< endl;
//    cin>>x;
//    cin>>y;
//    cout << "Hallo "<<x<<' '<<y<<'\n';
//    cout<<size(x+y);
//    Kunden v[100];
//    Kunden k;
//    cout<<"Nummer\n";
//    cin>>k.nummer;
//    cout<<"Namne und Vorname\n";
//    cin>>k.nume;
//    cin>>k.prenume;
//    cout<<"Postleitzahl\n";
//    cin>>k.postleitzahl;
//    cout<<"Ort\n";
//    cin>>k.ort;
//    v[0]=k;
//    cout<<k.nummer<<'\n';
//    cout<<k.nume<<'\n';
//    cout<<k.prenume<<'\n';
//    cout<<k.postleitzahl<<'\n';
//    cout<<k.ort<<'\n';

    return 0;
}


