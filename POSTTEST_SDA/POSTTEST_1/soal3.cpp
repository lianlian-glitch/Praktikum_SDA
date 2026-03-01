#include <iostream>
using namespace std;

void reverseArray(int* arr, int n) {
    int* pointerAwal = arr;
    int* pointerAkhir = arr + n - 1;

    while (pointerAwal < pointerAkhir) {
        int temp = *pointerAwal;
        *pointerAwal = *pointerAkhir;
        *pointerAkhir = temp;

        pointerAwal++; 
        pointerAkhir--;
    }
}

int main() {
    int n = 7;
    int primes[] = {2, 3, 5, 7, 11, 13, 17};

    cout << "=== ARRAY SEBELUM DIBALIK ===\n";
    
    int* ptrCetak = primes; 
    for (int i = 0; i < n; i++) {
        cout << "Nilai: " << *ptrCetak << "\t | Alamat Memori: " << ptrCetak << endl;
        ptrCetak++;
    }

    reverseArray(primes, n);

    cout << "\n=== ARRAY SESUDAH DIBALIK ===\n";
    ptrCetak = primes;
    for (int i = 0; i < n; i++) {
        cout << "Nilai: " << *ptrCetak << "\t | Alamat Memori: " << ptrCetak << endl;
        ptrCetak++;
    }

    return 0;
}