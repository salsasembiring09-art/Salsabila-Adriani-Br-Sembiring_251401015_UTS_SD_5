#include <iostream>
using namespace std;

struct Node {
    int nilai;
    Node* next;
};

Node* head = nullptr;

Node* buatNode(int nilai) {
    Node* baru = new Node;
    baru->nilai = nilai;
    baru->next = nullptr;
    return baru;
}

void tampil() {
    cout << "\nIsi linked list: ";
    if (head == nullptr) {
        cout << "(kosong)\n";
        return;
    }
    cout << "HEAD -> ";
    for (Node* p = head; p != nullptr; p = p->next)
        cout << p->nilai << " -> ";
    cout << "NULL\n";
}

void tambahAwal(int nilai) {
    Node* baru = buatNode(nilai);
    baru->next = head;
    head = baru;
    cout << "Nilai " << nilai << " ditambahkan di awal.\n";
}

void tambahAkhir(int nilai) {
    Node* baru = buatNode(nilai);
    if (head == nullptr) {
        head = baru;
    } else {
        Node* p = head;
        while (p->next != nullptr) p = p->next;
        p->next = baru;
    }
    cout << "Nilai " << nilai << " ditambahkan di akhir.\n";
}

void tambahSetelah(int target, int nilai) {
    Node* p = head;
    while (p != nullptr && p->nilai != target) p = p->next;
    if (p == nullptr) {
        cout << "Node dengan nilai " << target << " tidak ditemukan.\n";
        return;
    }
    Node* baru = buatNode(nilai);
    baru->next = p->next;
    p->next = baru;
    cout << "Nilai " << nilai << " ditambahkan setelah " << target << ".\n";
}

void hapus(int nilai) {
    if (head == nullptr) {
        cout << "List kosong, tidak ada yang dihapus.\n";
        return;
    }
    
    if (head->nilai == nilai) {
        Node* hapusNode = head;
        head = head->next;
        delete hapusNode;
        cout << "Nilai " << nilai << " dihapus.\n";
        return;
    }
    
    Node* prev = head;
    while (prev->next != nullptr && prev->next->nilai != nilai)
        prev = prev->next;
    if (prev->next == nullptr) {
        cout << "Nilai " << nilai << " tidak ditemukan.\n";
        return;
    }
    Node* hapusNode = prev->next;
    prev->next = hapusNode->next;
    delete hapusNode;
    cout << "Nilai " << nilai << " dihapus.\n";
}

void bebaskanMemori() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    int pilihan, nilai, target;
    do {
        cout << "\n DATA NILAI MAHASISWA (Single Linked List) \n"
             << "1. Tambah di awal\n"
             << "2. Tambah di akhir\n"
             << "3. Tambah setelah nilai tertentu\n"
             << "4. Hapus berdasarkan nilai\n"
             << "0. Keluar\n"
             << "Pilih menu: ";
        if (!(cin >> pilihan)) break;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: "; cin >> nilai;
                tambahAwal(nilai); tampil();
                break;
            case 2:
                cout << "Masukkan nilai: "; cin >> nilai;
                tambahAkhir(nilai); tampil();
                break;
            case 3:
                cout << "Tambah setelah nilai: "; cin >> target;
                cout << "Masukkan nilai baru: "; cin >> nilai;
                tambahSetelah(target, nilai); tampil();
                break;
            case 4:
                cout << "Masukkan nilai yang dihapus: "; cin >> nilai;
                hapus(nilai); tampil();
                break;
            case 0:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Menu tidak valid.\n";
        }
    } while (pilihan != 0);

    bebaskanMemori();
    return 0;
}