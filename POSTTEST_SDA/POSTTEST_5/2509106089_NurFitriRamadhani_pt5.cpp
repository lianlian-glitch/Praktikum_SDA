#include <iostream>
#include <string>
using namespace std;

struct BukuNode {
    string judulBuku;
    BukuNode* next;

    BukuNode(string judul) {
        judulBuku = judul;
        next = nullptr;
    }
};

BukuNode* tambahBuku(BukuNode* head, string judul) {
    BukuNode* newNode = new BukuNode(judul);
    if (head == nullptr) {
        newNode->next = newNode;
        return newNode;
    }
    
    BukuNode* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return head;
}

bool cariBuku(BukuNode* head, string judulDicari) {
    // --- LENGKAPI KODE DI SINI ---
    
    // Pengecekan awal: Jika list kosong, langsung kembalikan false
    if (head == nullptr) {
        return false;
    }

    // Menyiapkan pointer temp mulai dari head untuk menelusuri list
    BukuNode* temp = head;

    // Menggunakan do-while agar node pertama (head) ikut dieksekusi dan dicek
    do {
        // Jika judul buku pada node saat ini cocok dengan yang dicari
        if (temp->judulBuku == judulDicari) {
            return true; 
        }
        
        // Pindah ke node selanjutnya
        temp = temp->next;
        
    // Perulangan berhenti jika pointer temp kembali ke head (selesai 1 putaran)
    } while (temp != head); 

    // Jika seluruh list sudah ditelusuri dan tidak ada yang cocok
    return false;

}

int main() {
    BukuNode* head = nullptr;
    
    head = tambahBuku(head, "Struktur Data dengan C++");
    head = tambahBuku(head, "Pengantar Algoritma");
    head = tambahBuku(head, "Pemrograman Berorientasi Objek");
    head = tambahBuku(head, "Sistem Basis Data");

    string buku1 = "Pengantar Algoritma";
    string buku2 = "Kalkulus Lanjut";

    cout << "Mencari buku '" << buku1 << "': " 
        << (cariBuku(head, buku1) ? "Ditemukan" : "Tidak Ditemukan") << endl; 

    cout << "Mencari buku '" << buku2 << "': " 
        << (cariBuku(head, buku2) ? "Ditemukan" : "Tidak Ditemukan") << endl; 

    return 0;
}