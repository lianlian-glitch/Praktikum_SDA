#include <iostream>
using namespace std;


void FindMin(int A[], int n, int &minValue, int &minIndex) {
    minValue = A[0];
    minIndex = 0;

    for (int i = 1; i < n; i++) {
        if (A[i] < minValue) {
            minValue = A[i];
            minIndex = i;
        }
    }
}

int main() {
    int A[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    int n = 8;

    int minValue, minIndex;

    FindMin(A, n, minValue, minIndex);

    cout << "Array Fibonacci: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }

    cout << "\n\nHasil Pencarian:\n";
    cout << "Nilai minimum = " << minValue;
    cout << "\nIndeks minimum = " << minIndex << "\n";

    return 0;
}

//===============================================
//     ANALISIS KOMPLEKSITAS WAKTU (Big-O)
//===============================================

//1. BEST CASE  : O(n)
//   - Kondisi  : Terjadi ketika array sudah terurut menaik (ascending).
//   - Alasan   : Karena nilai A[0] sudah yang paling kecil, kondisi 
//   (A[i] < minValue) akan selalu bernilai SALAH.
//   Sehingga baris eksekusi di dalam 'if' tidak pernah 
//   dijalankan sama sekali.

//2. WORST CASE : O(n)
//   - Kondisi  : Terjadi ketika array terurut menurun (descending).
//   - Alasan   : Karena nilai selalu mengecil, kondisi (A[i] < minValue)
//   akan selalu bernilai BENAR. Sehingga baris eksekusi 
//   di dalam 'if' akan selalu dijalankan pada tiap iterasi.

// KESIMPULAN:
// Algoritma ini merupakan Linear Search. Berapapun ukuran datanya (n),
// program wajib mengecek elemen array satu per satu dari awal sampai 
// akhir menggunakan perulangan 'for'. Oleh karena itu, kompleksitas 
// waktunya akan selalu berjalan linier, yaitu O(n).
