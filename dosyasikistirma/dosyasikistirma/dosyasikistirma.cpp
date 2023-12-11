


/*                                   Bu program çok basit bir prototiptir gelistirilebilir sadece bosluksuz ve ard ardına tekrar eden harf verileri sikistirir.
                                                                                  Mustafa Meriç Demiray 210401036
                              (kodun calismasi icin kodları compile edip programin dosya konumuna dosya.txt adinda bir dosya koyup içine verilerinizi yazin örn -> aaaaaaaaafggggbsssssbhnjjj )
*/
#include <string>              // bu kutuphane string degiskenlere uygalayabilecegimiz fonksiyonlar saglar
#include <iostream>            // bu kutuphane kullancının veri giris ve cıkısını yapmasini saglar
#include <fstream>             // bu kutuphane bize dosya islemleri yapmamızı saglar
using namespace std;             // standart namespace'in kullanilmasi
int main()
{
    string veri, cikti;           // kullanicidan alinan veriler icin veri degiskeni kullanicidan alinan veriyi islenip degistirilmis verinin tutulmasi icin cikti degiskeni
    int sayac = 0;                // tekrar eden verilerin tutulmasi icin sayac adında degisken olusturulup bu degiskenin 0'a esitlenmesi. 
    int secim;                    // kullanicinin veriyi sikistiricaginin ya da sikistirilmis veriyi acacagini belirtmesi icin secim degiskeninin olusturulmasi.
    long dosyaBoyutu;
    ofstream dosyaYaz;            //  fstream kütüphanesindeki classların nesnelerini tanimlamak 
    ifstream dosyaOku;
    cout << "veri sikistirmak icin (1)  sikistirilan veriyi acmak icin (2)";   /* ekrana veri sikistirmak icin (1)  sikistirilan veriyi acmak icin (2) yazisinin çıktısının yazilmasi. */
    cin >> secim;            /* kullanicinin dosyayı sikistiracagini mi sikistirilmis dosyayı acacagini karar verilmesi icin kullaniciden giris beklenmesi */
    if (secim == 1) {           /* veri sikistirilmek isteniyorsa */
        dosyaOku.open("dosya.txt");         /* ilgili dosyanın acilmasi. */
        dosyaOku >> veri;                  /* ilgili dosyadaki verilerin bir degiskene tanımlanmasi. */
        for (int i = 0; i < size(veri); i++) {                     // ilgli verinin her elemanini tarayip sikistirabilecegi verileri bulmasi icin verideki her elemani dolasan for dongusu.
            if (veri[i] == veri[i + 1]) {                          // eger dongudeki veri bir sonraki veri ile esitse   
                sayac++;                                           // sayac degiskenini arttir
            }
            else {                                                      // eger ilgili veri bir sonraki veriye esit degilse
                if (sayac == 0) {                                       // ve eger sayac degiskeni 0'a esit ise
                    cikti = cikti + veri[i];                             // cikti degiskenini (cikti + for dongusundeki o anda donen veri ) ile degistir.
                    sayac = 0;                                          // sayaci 0'a esitle.
                }
                else {                                                    // sayac 0 degil ise
                    string strsayac = to_string(sayac + 1);               // strsayac isimli bir degisken olustur ve (sayac+1) degerini integer dan stringe donustur.   
                    cikti = cikti + strsayac + veri[i];                     // cikti verisini (cikti+strsayac + ilgili veri) olarak degistir.
                    sayac = 0;                                            // sayac degiskenini 0'a esitle
                }
            }
        }
        dosyaOku.close();                                     // ilgili dosyanin kapanmasi.
        cout << cikti;                                        // sikistirilan verinin ekrana yazilmasi
        dosyaYaz.open("sikistirilmisDosya.txt");              // sikistirilmisDosya.txt adinda bir doysa yok ise olustur ve icini ac.
        dosyaYaz << cikti;                                    // cikti degiskenindeki veriyi sikistirilmisDosya.txt dosyasinin icine yaz. 
        dosyaYaz.close();                                     // sikistirilmisDosya.txt yi kapat.
    }else if(secim==2){                                       // sikistirilmis dosyanin acilmasinin secilmesi.
        string sayitut ;                                      // sayitutu adinda bir string degisken olustur.
        dosyaOku.open("sikistirilmisDosya.txt");              // sikistirilmisDosya.txt dosyasini ac 
        dosyaOku >> veri;                                     // sikistirilmisDosya.txt dosyasinin icindeki veriyi veri degiskenine tanımla.
        for (int i = 0; i < size(veri); i++) {                // sikistirilmis verideki her birimi dolasmasi icin for dongusu.
            if (i == 0 && isalpha(veri[i])) {                 // dongunun ilk elemani ise ve ilk eleman harf ise
                cikti = cikti + veri[i];                      // cikti degiskenini (cikti + ilk veri olarak degistir)
            }
            else                                              // dongunun ilk elemaninda degilsen ve
            {
                if (isdigit(veri[i])) {                       // dongudeki veri rakam ise.
                    sayitut = sayitut + veri[i];              // sayitut degiskenini (sayitut + ilgili veri) olarak degistir.
                }
                else if (isalpha(veri[i])) {                  // eger dongudeki veri harf ise   
                    if (isalpha(veri[i]) == isalpha(veri[i - 1])) {        // ve eger ilgili veri harf ve bir onceki veri harf ise 
                        cikti = cikti + veri[i];                            // cikti degiskenini (cikti + ilgili veri) olarak degistir.
                    }
                    else if (isalpha(veri[i]) != isalpha(veri[i - 1])) {      // ama eger dongudeki veri ve bi ondeki veri harf degil ise 
                        int kactane = stoi(sayitut);                         //   kactane adli bir degisken olustur ve bu degiskene sayitut string verisini string verisine donusturerek yaz.
                        for (int j = 0; j < kactane; j++) {                  //  acilacak sayi verisi kadar cikti degiskene sayiyi yazmak icin dongu.
                            cikti = cikti + veri[i];                         //  cikti degiskenini (cikti + ilgili veri) 
                        }
                    }
                    sayitut.clear();                                       //sayitut degiskenini temizle
                }
        }
        }
        cout <<"verinin acilmis hali --->" << cikti;                 // cikti degiskenindeki verinin ekrana yazilmasi.
        dosyaOku.close();                                           // sikistirilmisDosya.txt'nin kapatilmasi.
        dosyaYaz.open("acilmisVeri.txt");                           // acilmisVeri.txt adinda bir dosya yoksa olusturulmasi ve acilmasi
        dosyaYaz << cikti;                                          // acilmisVeri.txt adindaki dosyaya cikti degiskenindeki verilerin yazilmasi
        dosyaYaz.close();                                            // acilmisVeri.txt'nin kapatilmasi.
    }
    else { cout << "yanlis tuslama";                                 // kullanici eger (1) veya (2) den farklı bir deger girerse ekrana yanlis tuslama yazilmasi.
    }
}

