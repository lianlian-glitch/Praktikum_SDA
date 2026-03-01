#include <iostream>
using namespace std;

void tukarNilai(int* a, int* b) {
    int temp = *a; 
    *a = *b;       
    *b = temp;     
}

int main() {
    int angka1, angka2;

    cout << "=== PROGRAM TUKAR NILAI (POINTER) ===\n";
    
    cout << "Masukkan nilai angka pertama: ";
    cin >> angka1;
    cout << "Masukkan nilai angka kedua  : ";
    cin >> angka2;

    cout << "\n=== SEBELUM PERTUKARAN ===\n";
    cout << "Angka 1 = " << angka1 << endl;
    cout << "Angka 2 = " << angka2 << endl;

    tukarNilai(&angka1, &angka2);

    cout << "\n=== SESUDAH PERTUKARAN ===\n";
    cout << "Angka 1 = " << angka1 << endl;
    cout << "Angka 2 = " << angka2 << endl;

    return 0;
}