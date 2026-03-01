#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {
    
    Mahasiswa mhs[5];
    int n = 5;

    cout << "=== INPUT DATA 5 MAHASISWA ===\n";
    for (int i = 0; i < n; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "Nama : ";
        cin >> ws;
        getline(cin, mhs[i].nama);
        cout << "NIM  : ";
        cin >> mhs[i].nim;
        cout << "IPK  : ";
        cin >> mhs[i].ipk;
    }

    int indeksIpkTertinggi = 0; 
    float ipkMaksimal = mhs[0].ipk;

    for (int i = 1; i < n; i++) {
        if (mhs[i].ipk > ipkMaksimal) {
            ipkMaksimal = mhs[i].ipk;
            indeksIpkTertinggi = i;
        }
    }

    cout << "\n=========================================\n";
    cout << "  MAHASISWA DENGAN IPK TERTINGGI \n";
    cout << "=========================================\n";
    cout << "Nama : " << mhs[indeksIpkTertinggi].nama << endl;
    cout << "NIM  : " << mhs[indeksIpkTertinggi].nim << endl;
    cout << "IPK  : " << mhs[indeksIpkTertinggi].ipk << endl;

    return 0;
}