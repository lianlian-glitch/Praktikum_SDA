#include <iostream>
#include <string>

using namespace std;

struct Hewan {
    int id;
    string nama;
    int harga;
};

void swap(Hewan* a, Hewan* b) {
    Hewan temp = *a;
    *a = *b;
    *b = temp;
}

void tampilkanData(Hewan* arr, int n) {
    cout << "\n=== DATA HEWAN PAWCARE ===\n";
    if (n == 0) {
        cout << "Belum ada data hewan.\n";
        return;
    }
    cout << "ID\tNama\t\tHarga\n";
    cout << "-----------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << (arr + i)->id << "\t" << (arr + i)->nama << "\t\tRp" << (arr + i)->harga << "\n";
    }
}

void tambahData(Hewan* arr, int* n) {
    cout << "\n--- Tambah Data Hewan ---\n";
    cout << "Masukkan ID Hewan : ";
    cin >> (arr + *n)->id;
    cin.ignore();
    cout << "Masukkan Nama     : ";
    getline(cin, (arr + *n)->nama);
    cout << "Masukkan Harga    : ";
    cin >> (arr + *n)->harga;
    
    (*n)++;
    cout << "Data hewan berhasil ditambahkan!\n";
}

void linearSearch(Hewan* arr, int n, string target) {
    bool ketemu = false;
    cout << "\n--- Hasil Pencarian Linear ---\n";
    for (int i = 0; i < n; i++) {
        if ((arr + i)->nama == target) {
            cout << "Hewan ditemukan pada urutan ke-" << i + 1 << ": ID " << (arr + i)->id << " | Harga Rp" << (arr + i)->harga << "\n";
            ketemu = true;
        }
    }
    if (!ketemu) cout << "Hewan dengan nama '" << target << "' tidak ditemukan.\n";
}

int fibonacciSearch(Hewan* arr, int n, int target) {
    int fib2 = 0; 
    int fib1 = 1; 
    int fib = fib2 + fib1;

    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib2 + fib1;
    }

    int offset = -1;
    
    /* PENJELASAN PROSES ITERASI FIBONACCI SEARCH:
    Proses iterasi berjalan selama nilai Fibonacci saat ini (fib) > 1.
    Pada setiap iterasinya, algoritma melakukan:
    1. Menentukan indeks 'i' yang dicek dari penjumlahan (offset + fib2).
    2. Membandingkan ID target dengan ID pada array indeks ke-i:
       - Jika cocok (==): Iterasi langsung berhenti, data ditemukan.
       - Jika lebih kecil (<): Target ada di sebelah kiri. Rentang pencarian 
         dipersempit ke kiri dengan menurunkan nilai Fibonacci 2 tingkat.
       - Jika lebih besar (>): Target ada di sebelah kanan. Batas 'offset' 
         digeser menjadi 'i', dan nilai Fibonacci diturunkan 1 tingkat.
    */
    while (fib > 1) {
        int i = (offset + fib2 < n - 1) ? (offset + fib2) : (n - 1);
        
        if ((arr + i)->id == target) {
            return i;
        } else if ((arr + i)->id < target) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
        } else {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
            offset = i;
        }
    }

    if (fib1 == 1 && (arr + offset + 1)->id == target) {
        return offset + 1;
    }

    return -1;
}

void bubbleSort(Hewan* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((arr + j)->nama > (arr + j + 1)->nama) {
                swap((arr + j), (arr + j + 1));
            }
        }
    }
    cout << "Data berhasil diurutkan berdasarkan Nama (A-Z).\n";
}

void selectionSort(Hewan* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if ((arr + j)->harga < (arr + min_idx)->harga) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap((arr + i), (arr + min_idx));
        }
    }
    cout << "Data berhasil diurutkan berdasarkan Harga (Termurah).\n";
}

int main() {
    Hewan daftarHewan[100];
    int jumlahHewan = 0;
    int pilihan;

    do {
        cout << "\n=====================================\n";
        cout << "   SISTEM MANAJEMEN PAWCARE PETSHOP  \n";
        cout << "=====================================\n";
        cout << "1. Tampilkan Semua Data Hewan\n";
        cout << "2. Tambah Data Hewan Baru\n";
        cout << "3. Cari Hewan berdasarkan Nama\n";
        cout << "4. Cari Hewan berdasarkan ID\n";
        cout << "5. Urutkan Nama Hewan A-Z\n";
        cout << "6. Urutkan Harga Termurah\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanData(daftarHewan, jumlahHewan);
                break;
            case 2:
                tambahData(daftarHewan, &jumlahHewan); 
                break;
            case 3: {
                string cariNama;
                cout << "Masukkan nama hewan yang dicari: ";
                cin.ignore();
                getline(cin, cariNama);
                linearSearch(daftarHewan, jumlahHewan, cariNama);
                break;
            }
            case 4: {
                int cariID;
                cout << "Masukkan ID hewan yang dicari: ";
                cin >> cariID;
                for (int i = 0; i < jumlahHewan - 1; i++) {
                    int min_idx = i;
                    for (int j = i + 1; j < jumlahHewan; j++) {
                        if ((daftarHewan + j)->id < (daftarHewan + min_idx)->id) min_idx = j;
                    }
                    if (min_idx != i) swap((daftarHewan + i), (daftarHewan + min_idx));
                }
                cout << "(Sistem otomatis mengurutkan ID sebelum Fibonacci Search berjalan)\n";
                
                int hasil = fibonacciSearch(daftarHewan, jumlahHewan, cariID);
                if (hasil != -1) {
                    cout << "\n>>> Ditemukan! Nama: " << (daftarHewan + hasil)->nama 
                        << " | Harga: Rp" << (daftarHewan + hasil)->harga << " <<<\n";
                } else {
                    cout << "\n>>> ID Hewan tidak ditemukan! <<<\n";
                }
                break;
            }
            case 5:
                bubbleSort(daftarHewan, jumlahHewan);
                tampilkanData(daftarHewan, jumlahHewan);
                break;
            case 6:
                selectionSort(daftarHewan, jumlahHewan);
                tampilkanData(daftarHewan, jumlahHewan);
                break;
            case 0:
                cout << "Terima kasih telah menggunakan sistem Pawcare!\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 0);

    return 0;
}