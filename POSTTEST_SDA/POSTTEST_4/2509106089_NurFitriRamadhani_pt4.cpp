#include <iostream>
#include <string>

#define MAX 100

using namespace std;

struct Hewan {
    int id;
    string nama;
    int harga;
    Hewan* next;
};

Hewan* topRiwayat = nullptr;
Hewan* frontAntrian = nullptr;
Hewan* rearAntrian = nullptr;

void swap(Hewan* a, Hewan* b) {
    int tempId = a->id;
    string tempNama = a->nama;
    int tempHarga = a->harga;

    a->id = b->id;
    a->nama = b->nama;
    a->harga = b->harga;

    b->id = tempId;
    b->nama = tempNama;
    b->harga = tempHarga;
    
}

void tampilkanData(Hewan* arr, int n) {
    cout << "\n=== DATA MASTER HEWAN PAWCARE ===\n";
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
    cout << "\n--- Tambah Data Master Hewan ---\n";
    cout << "Masukkan ID Hewan : ";
    cin >> (arr + *n)->id;
    cin.ignore();
    cout << "Masukkan Nama     : ";
    getline(cin, (arr + *n)->nama);
    cout << "Masukkan Harga    : ";
    cin >> (arr + *n)->harga;
    (arr + *n)->next = nullptr; 
    
    (*n)++;
    cout << "Data master hewan berhasil ditambahkan!\n";
}

void linearSearch(Hewan* arr, int n, string target) {
    bool ketemu = false;
    cout << "\n--- Hasil Pencarian Linear ---\n";
    for (int i = 0; i < n; i++) {
        if ((arr + i)->nama == target) {
            cout << "Ditemukan pada urutan ke-" << i + 1 << ": ID " << (arr + i)->id << " | Rp" << (arr + i)->harga << "\n";
            ketemu = true;
        }
    }
    if (!ketemu) cout << "Hewan dengan nama '" << target << "' tidak ditemukan.\n";
}

int fibonacciSearch(Hewan* arr, int n, int target) {
    int fib2 = 0, fib1 = 1, fib = fib2 + fib1;
    while (fib < n) {
        fib2 = fib1; fib1 = fib; fib = fib2 + fib1;
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
        if ((arr + i)->id == target) return i;
        else if ((arr + i)->id < target) {
            fib = fib1; fib1 = fib2; fib2 = fib - fib1;
        } else {
            fib = fib2; fib1 = fib1 - fib2; fib2 = fib - fib1;
            offset = i;
        }
    }
    if (fib1 == 1 && (arr + offset + 1)->id == target) return offset + 1;
    return -1;
}

void bubbleSort(Hewan* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((arr + j)->nama > (arr + j + 1)->nama) swap((arr + j), (arr + j + 1));
        }
    }
    cout << "Data diurutkan berdasarkan Nama (A-Z).\n";
}

void selectionSort(Hewan* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if ((arr + j)->harga < (arr + min_idx)->harga) min_idx = j;
        }
        if (min_idx != i) swap((arr + i), (arr + min_idx));
    }
    cout << "Data diurutkan berdasarkan Harga (Termurah).\n";
}

void enqueue() {
    Hewan* nodeBaru = new Hewan;
    cout << "\n--- Mendaftar Antrian Pemeriksaan ---\n";
    cout << "Masukkan ID Pasien   : "; cin >> nodeBaru->id;
    cin.ignore();
    cout << "Masukkan Nama Pasien : "; getline(cin, nodeBaru->nama);
    cout << "Biaya Pemeriksaan    : "; cin >> nodeBaru->harga;
    nodeBaru->next = nullptr;

    if (frontAntrian == nullptr) {
        frontAntrian = rearAntrian = nodeBaru;
    } else {
        rearAntrian->next = nodeBaru;
        rearAntrian = nodeBaru;
    }
    cout << ">>> Pasien " << nodeBaru->nama << " berhasil masuk antrian.\n";
}

Hewan dequeue() {
    Hewan kosong; kosong.id = -1;
    if (frontAntrian == nullptr) {
        cout << "Queue underflow! Tidak ada pasien di antrian saat ini.\n";
        return kosong;
    }
    
    Hewan* hapus = frontAntrian;
    Hewan dipanggil = *hapus;
    dipanggil.next = nullptr;

    frontAntrian = frontAntrian->next;
    if (frontAntrian == nullptr) {
        rearAntrian = nullptr;
    }
    
    delete hapus;
    return dipanggil;
}

void tampilkanAntrian(Hewan* front) {
    cout << "\n=== DAFTAR ANTRIAN PASIEN ===\n";
    if (front == nullptr) {
        cout << "Antrian kosong.\n";
        return;
    }
    Hewan* temp = front;
    int i = 1;
    while (temp != nullptr) {
        cout << "Antrian [" << i++ << "] -> ID: " << temp->id << " | Nama: " << temp->nama << "\n";
        temp = temp->next;
    }
}

void pushRiwayat(Hewan pasien) {
    Hewan* nodeBaru = new Hewan;
    nodeBaru->id = pasien.id;
    nodeBaru->nama = pasien.nama;
    nodeBaru->harga = pasien.harga;
    
    nodeBaru->next = topRiwayat;
    topRiwayat = nodeBaru;
}

Hewan popRiwayat() {
    Hewan kosong; kosong.id = -1;
    if (topRiwayat == nullptr) {
        cout << "Stack underflow! Tidak ada riwayat tindakan yang bisa dibatalkan.\n";
        return kosong;
    }
    
    Hewan* hapus = topRiwayat;
    Hewan batal = *hapus;
    batal.next = nullptr;

    topRiwayat = topRiwayat->next;
    delete hapus;
    return batal;
}

void tampilkanRiwayat(Hewan* top) {
    cout << "\n=== RIWAYAT TINDAKAN MEDIS ===\n";
    if (top == nullptr) {
        cout << "Belum ada riwayat tindakan.\n";
        return;
    }
    Hewan* temp = top;
    int i = 1;
    while (temp != nullptr) {
        cout << "Riwayat Ke-" << i++ << " -> ID: " << temp->id << " | Nama: " << temp->nama << "\n";
        temp = temp->next;
    }
}

void peekData(Hewan* frontQ, Hewan* topS) {
    cout << "\n=== PEEK (MONITORING DATA) ===\n";
    
    if (frontQ == nullptr) cout << ">> Pasien Terdepan Antrian : (Kosong)\n";
    else cout << ">> Pasien Terdepan Antrian : " << frontQ->nama << " (ID: " << frontQ->id << ")\n";

    if (topS == nullptr) cout << ">> Tindakan Medis Terakhir : (Kosong)\n";
    else cout << ">> Tindakan Medis Terakhir : " << topS->nama << " (ID: " << topS->id << ")\n";
}

int main() {
    Hewan daftarHewan[MAX] = {
        {105, "Luna", 55000, nullptr},
        {102, "Milo", 70000, nullptr},
        {108, "Oreo", 45000, nullptr},
        {101, "Simba", 80000, nullptr},
        {104, "Boba", 60000, nullptr}
    };
    
    int jumlahHewan = 5;
    int pilihan;

    do {
        cout << "\n=====================================\n";
        cout << "   SISTEM KLINIK PAWCARE PETSHOP  \n";
        cout << "=====================================\n";
        cout << "1. Tampilkan Master Data Hewan\n";
        cout << "2. Tambah Master Data Hewan Baru\n";
        cout << "3. Cari Hewan (Nama) & Urutkan\n";
        cout << "4. Daftar Antrian Pemeriksaan\n";
        cout << "5. Panggil Pasien Selesai\n";
        cout << "6. Batalkan Tindakan Terakhir\n";
        cout << "7. Monitor Pasien & Riwayat\n";
        cout << "8. Tampilkan Seluruh Antrian Pasien\n";
        cout << "9. Tampilkan Seluruh Riwayat Medis\n";
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
                int opsiCari;
                cout << "\n1. Cari Berdasarkan Nama (Linear)\n2. Urutkan Nama (Bubble Sort)\n3. Urutkan Harga (Selection Sort)\nPilih: ";
                cin >> opsiCari;
                if (opsiCari == 1) {
                    string cariNama;
                    cout << "Masukkan nama hewan: "; cin.ignore(); getline(cin, cariNama);
                    linearSearch(daftarHewan, jumlahHewan, cariNama);
                } else if (opsiCari == 2) {
                    bubbleSort(daftarHewan, jumlahHewan);
                } else if (opsiCari == 3) {
                    selectionSort(daftarHewan, jumlahHewan);
                }
                break;
            }
            case 4:
                enqueue();
                break;
            case 5: {
                Hewan pasien = dequeue();
                if (pasien.id != -1) {
                    cout << "\n>>> DOKTER MEMANGGIL PASIEN: " << pasien.nama << " (ID: " << pasien.id << ") <<<\n";
                    pushRiwayat(pasien);
                    cout << "Pemeriksaan selesai. Data berhasil dicatat ke Riwayat Tindakan (Stack).\n";
                }
                break;
            }
            case 6: {
                Hewan batal = popRiwayat();
                if (batal.id != -1) {
                    cout << "\n>>> TINDAKAN DIBATALKAN UNTUK: " << batal.nama << " (ID: " << batal.id << ") <<<\n";
                }
                break;
            }
            case 7:
                peekData(frontAntrian, topRiwayat);
                break;
            case 8:
                tampilkanAntrian(frontAntrian);
                break;
            case 9:
                tampilkanRiwayat(topRiwayat);
                break;
            case 0:
                cout << "Terima kasih telah menggunakan sistem klinik Pawcare!\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 0);

    return 0;
}