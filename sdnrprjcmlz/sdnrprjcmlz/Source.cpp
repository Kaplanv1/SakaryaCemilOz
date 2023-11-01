#include <iostream>
#include <vector>
#include <random>
#include <map>
#include <string>
#include <cmath>
#include <locale>

using namespace std;

// Harf notu aralýklarýný tanýmlayan yapý
struct NotAraligi {
    string harfNotu;
    int altSinir;
    int ustSinir;
    double puan;
};

// Öðrenci bilgilerini tutan yapý
struct Ogrenci {
    string isim;
    string Soyisim;
    double vizeNotu;
    double kisaSinavNotu1;
    double kisaSinavNotu2;
    double odevNotu1;
    double odevNotu2;
    double genelNot;
    string harfNotu;
};

// Rastgele isim üreten fonksiyon
string randomIsimUret() {
    static string isimler[] = { "Cemil", "Emirhan", "Sude", "Fatma", "Mustafa", "Emre", "Ebru", "Elif", "Burak", "Selin" };
    return isimler[std::rand() % 10];
    
}
// Rastgele Soyisim üreten fonksiyon
string randomSoyIsimUret() {
    static string Soyisimler[] = { "Kaplan", "Omurca", "Öz", "Þahin", "Danýþ", "Gaya", "Demir", "Bayram", "Karakaþ", "Çakar" };
    return Soyisimler[std::rand() % 10];
}

int main() {

    setlocale(LC_ALL, "Turkish"); //Türkçe çýktý alabilmek için

    int ogrenciSayisi;
    cout << "Öðrenci sayýsýný girin: ";
    cin >> ogrenciSayisi;


    double Vize_Agirligi;
    cout << "lütfen Vizenin aðýrlýðýný giriniz (örnek:0.5): "; cin >> Vize_Agirligi;

    double KisaSinav_Agirligi;
    cout << "lütfen Kýsa sýnavýn aðýrlýðýný giriniz (örnek:0.3): "; cin >> KisaSinav_Agirligi;

    double Odev_Agirligi;
    cout << "lütfen Ödevin aðýrlýðýný giriniz (örnek:0.2): "; cin >> Odev_Agirligi;
    
    

    vector<Ogrenci> ogrenciler;
    map<string, int> harfNotuSiralama;

    default_random_engine generator;
    uniform_real_distribution<double> distribution(0.0, 1.0);

    vector<NotAraligi> notAraliklari = {
        {"AA", 90, 100, 4.00},
        {"BA", 85, 89, 3.50},
        {"BB", 80, 84, 3.00},
        {"CB", 75, 79, 2.50},
        {"CC", 65, 74, 2.00},
        {"DC", 58, 64, 1.50},
        {"DD", 50, 57, 1.00},
        {"FD", 40, 49, 0.50},
        {"FF", 0, 39, 0.00}
    };

    for (const NotAraligi& notAraligi : notAraliklari) {
        harfNotuSiralama[notAraligi.harfNotu] = 0;
    }

    for (int ogrenciNo = 1; ogrenciNo <= ogrenciSayisi; ogrenciNo++) {
        double vizeNotu = 0, kisaSinavNotu1 = 0, kisaSinavNotu2 = 0, odevNotu1 = 0, odevNotu2 = 0;;

        double rastgele = distribution(generator);

        if (rastgele <= 0.2) {
            vizeNotu = std::rand() % 21 + 80;
        }
        else if (rastgele <= 0.7) {
            vizeNotu = std::rand() % 31 + 50;
        }
        else {
            vizeNotu = std::rand() % 51;
        }

        rastgele = distribution(generator);

        if (rastgele <= 0.2) {
            kisaSinavNotu1 = std::rand() % 21 + 80;
        }
        else if (rastgele <= 0.7) {
            kisaSinavNotu1 = std::rand() % 31 + 50;
        }
        else {
            kisaSinavNotu1 = std::rand() % 51;
        }

        rastgele = distribution(generator);

        if (rastgele <= 0.2) {
            kisaSinavNotu2 = std::rand() % 21 + 80;
        }
        else if (rastgele <= 0.7) {
            kisaSinavNotu2 = std::rand() % 31 + 50;
        }
        else {
            kisaSinavNotu2 = std::rand() % 51;
        }

        rastgele = distribution(generator);

        if (rastgele <= 0.2) {
            odevNotu1 = std::rand() % 21 + 80;
        }
        else if (rastgele <= 0.7) {
            odevNotu1 = std::rand() % 31 + 50;
        }
        else {
            odevNotu1 = std::rand() % 51;
        }

        rastgele = distribution(generator);

        if (rastgele <= 0.2) {
            odevNotu2 = std::rand() % 21 + 80;
        }
        else if (rastgele <= 0.7) {
            odevNotu2 = std::rand() % 31 + 50;
        }
        else {
            odevNotu2 = std::rand() % 51;
        }

        Ogrenci ogrenci;
        ogrenci.isim = randomIsimUret();
        ogrenci.Soyisim = randomSoyIsimUret();
        ogrenci.vizeNotu = vizeNotu;
        ogrenci.kisaSinavNotu1 = kisaSinavNotu1;
        ogrenci.kisaSinavNotu2 = kisaSinavNotu2;
        ogrenci.odevNotu1 = odevNotu1;
        ogrenci.odevNotu2 = odevNotu2;
        ogrenci.genelNot = vizeNotu * Vize_Agirligi + (kisaSinavNotu1+ kisaSinavNotu2) * KisaSinav_Agirligi+ (odevNotu1+ odevNotu2)* Odev_Agirligi;

        for (const NotAraligi& notAraligi : notAraliklari) {
            if (ogrenci.genelNot >= notAraligi.altSinir && ogrenci.genelNot <= notAraligi.ustSinir) {
                ogrenci.harfNotu = notAraligi.harfNotu;
                harfNotuSiralama[notAraligi.harfNotu]++;
                break;
            }
        }

        ogrenciler.push_back(ogrenci);

        cout << "Öðrenci " << ogrenci.isim<< " " <<ogrenci.Soyisim << " - Vize: " << vizeNotu << ", 1. Kýsa Sýnav: " << kisaSinavNotu1 << ", 2. Kýsa Sýnav: " << kisaSinavNotu2 << ", 1.Ödev: " << odevNotu1 << ", 2.Ödev: " << odevNotu2 << ", Genel Not: " << ogrenci.genelNot << ", Harf Notu: " << ogrenci.harfNotu << endl;
    }

    // Harf notlarýnýn sayýsýný yazdýrýn
    for (const auto& pair : harfNotuSiralama) {
        cout << "Toplam " << pair.first << " notu: " << pair.second << " öðrenci" << endl;
    }

    // Ortalama, standart sapma ve en yüksek-düþük notlarý hesaplayýn ve yazdýrýn
    vector<double> vizeNotlari, kisaSinav1, kisaSinav2, odev1, odev2, genelNotlar;
    for (const Ogrenci& ogrenci : ogrenciler) {
        vizeNotlari.push_back(ogrenci.vizeNotu);
        kisaSinav1.push_back(ogrenci.kisaSinavNotu1);
        kisaSinav2.push_back(ogrenci.kisaSinavNotu2);
        odev1.push_back(ogrenci.odevNotu1);
        odev2.push_back(ogrenci.odevNotu2);
        genelNotlar.push_back(ogrenci.genelNot);
    }

    double vizeOrtalama = 0, kisaSinavOrtalama = 0, odevOrtalama = 0, genelOrtalama = 0;
    for (int i = 0; i < ogrenciSayisi; i++) {
        vizeOrtalama += vizeNotlari[i];
        kisaSinavOrtalama += (kisaSinav1[i]+ kisaSinav2[i])/2;
        odevOrtalama += (odev1[i]+ odev2[i])/2;
        genelOrtalama += genelNotlar[i];
    }

    vizeOrtalama /= ogrenciSayisi;
    kisaSinavOrtalama /= ogrenciSayisi;
    odevOrtalama /= ogrenciSayisi;
    genelOrtalama /= ogrenciSayisi;

    double vizeStandartSapma = 0, kisaSinavStandartSapma = 0, odevStandartSapma = 0, genelStandartSapma = 0;
    for (int i = 0; i < ogrenciSayisi; i++) {
        vizeStandartSapma += (vizeNotlari[i] - vizeOrtalama) * (vizeNotlari[i] - vizeOrtalama);
        kisaSinavStandartSapma += (kisaSinav1[i]+ kisaSinav2[i] - kisaSinavOrtalama) * (kisaSinav1[i]+ kisaSinav2[i] - kisaSinavOrtalama);
        odevStandartSapma += (odev1[i]+ odev2[i] - odevOrtalama) * (odev1[i]+ odev2[i] - odevOrtalama);
        genelStandartSapma += (genelNotlar[i] - genelOrtalama) * (genelNotlar[i] - genelOrtalama);
    }

    vizeStandartSapma = sqrt(vizeStandartSapma / ogrenciSayisi);
    kisaSinavStandartSapma = sqrt(kisaSinavStandartSapma / ogrenciSayisi);
    odevStandartSapma = sqrt(odevStandartSapma / ogrenciSayisi);
    genelStandartSapma = sqrt(genelStandartSapma / ogrenciSayisi);

    double vizeEnYuksekNot = *max_element(vizeNotlari.begin(), vizeNotlari.end());
    double kisaSinav1EnYuksekNot = *max_element(kisaSinav1.begin(), kisaSinav1.end());
    double kisaSinav2EnYuksekNot = *max_element(kisaSinav2.begin(), kisaSinav2.end());
    double odev1EnYuksekNot = *max_element(odev1.begin(), odev1.end());
    double odev2EnYuksekNot = *max_element(odev2.begin(), odev2.end());
    double genelEnYuksekNot = *max_element(genelNotlar.begin(), genelNotlar.end());

    double vizeEnDusukNot = *min_element(vizeNotlari.begin(), vizeNotlari.end());
    double kisaSinav1EnDusukNot = *min_element(kisaSinav1.begin(), kisaSinav1.end());
    double kisaSinav2EnDusukNot = *min_element(kisaSinav2.begin(), kisaSinav2.end());
    double odev1EnDusukNot = *min_element(odev1.begin(), odev1.end());
    double odev2EnDusukNot = *min_element(odev2.begin(), odev2.end());
    double genelEnDusukNot = *min_element(genelNotlar.begin(), genelNotlar.end());

    cout << "Vize Ortalama: " << vizeOrtalama << ", Standart Sapma: " << vizeStandartSapma << ", En Yüksek Not: " << vizeEnYuksekNot << ", En Düþük Not: " << vizeEnDusukNot << endl;
    cout << "Kýsa Sýnav Ortalama: " << kisaSinavOrtalama << ", Standart Sapma: " << kisaSinavStandartSapma << ",1.Sýnavýn En Yüksek Notu: " << kisaSinav1EnYuksekNot << ", 1. Sýnavýn En Düþük Notu: " << kisaSinav1EnDusukNot << ", 2.Sýnavýn En Yüksek Notu: " << kisaSinav2EnYuksekNot << ", 2.Sýnavýn En Düþük Notu: " << kisaSinav2EnDusukNot<< endl;
    cout << "Ödev Ortalama: " << odevOrtalama << ", Standart Sapma: " << odevStandartSapma << ",1.Ödevin En Yüksek Not: " << odev1EnYuksekNot << ", 1.Ödevin En Düþük Not: " << odev1EnDusukNot << ", 2.Ödevin En Yüksek Notu: " << odev2EnYuksekNot << ", 2.Ödevin En Düþük Notu: " << odev2EnDusukNot << endl;
    cout << "Genel Ortalama: " << genelOrtalama << ", Standart Sapma: " << genelStandartSapma << ", En Yüksek Not: " << genelEnYuksekNot << ", En Düþük Not: " << genelEnDusukNot << endl;

    return 0;
}
