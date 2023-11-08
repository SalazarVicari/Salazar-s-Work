
#include <string>
#include <iostream>
using namespace std;
int main()
{
    string veri, cikti;
    int sayac = 0;
    int secim;
    cout << "veri sikistirmak icin (1)  sikistirilan veriyi acmak icin (2)";
    cin >> secim;
    if (secim == 1) {
        cout << "sikistiracaginiz veriyi giriniz";
        cin >> veri;
        for (int i = 0; i < size(veri); i++) {
            if (veri[i] == veri[i + 1]) {
                sayac++;
            }
            else {
                if (sayac == 0) {
                    cout << veri[i];
                    sayac = 0;
                }
                else {
                    string strsayac = to_string(sayac + 1);
                    cikti = strsayac + veri[i];
                    cout << cikti;
                    sayac = 0;
                }
            }
        }
    }else if(secim==2){
        string sayitut ;
        cout << "acacaginiz veriyi girin";
        cin >> veri;
        for (int i = 0; i < size(veri); i++) {
            if (isdigit(veri[i])) {
                sayitut = sayitut + veri[i];
            }
            else if (isalpha(veri[i])) {
                if (isalpha(veri[i]) == isalpha(veri[i-1])) {
                    cikti = cikti + veri[i];
                }
                else if(isalpha(veri[i]) != isalpha(veri[i-1])) {
                    int kactane = stoi(sayitut);
                    for (int j = 0; j < kactane; j++) {
                        cikti = cikti + veri[i];
                    }}
                sayitut.clear();
            }
        }
        cout <<"verinin acilmis hali --->" << cikti;
    }
    else { cout << "yanlis tuslama";
    }
}

