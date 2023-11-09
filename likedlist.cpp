#include <iostream>
#include <string>
using namespace std;

struct mahasiswa
{
    string nrp;
    string nama;
    string jurusan;
};

struct Node
{
    struct mahasiswa data;
    struct Node *next;
};

void tampil(struct Node *head)
{
    struct Node *current = head;

    cout << "Data Mahasiswa:" << endl;
    int i = 1;
    while (current)
    {
        cout << "Mahasiswa ke -" << i << endl;
        cout << "NRP : " << current->data.nrp << endl;
        cout << "Nama: " << current->data.nama << endl;
        cout << "No Jurusan: " << current->data.jurusan << endl;
        cout << endl;
        current = current->next;
        i++;
    }
}

void tambah(struct Node *&head, int &jumlah_mhs)
{
    struct Node *newNode = new Node;
    cin.ignore();
    cout << "NRP: ";
    getline(cin, newNode->data.nrp);
    cout << "Nama: ";
    getline(cin, newNode->data.nama);
    cout << "No Jurusan: ";
    getline(cin, newNode->data.jurusan);

    newNode->next = nullptr;
    if (!head)
    {
        head = newNode;
    }
    else
    {
        struct Node *current = head;
        while (current->next)
        {
            current = current->next;
        }
        current->next = newNode;
    }
    jumlah_mhs++;
}

void ganti(struct Node *head, int jumlah_data)
{
    int menu;
    int i;
    cout << "1. NRP" << endl;
    cout << "2. Nama" << endl;
    cout << "3. No Jurusan" << endl;
    cout << "4. Semua" << endl;
    cout << endl;

    cout << "Pilih menu : ";
    cin >> menu;
    cout << "\nMasukkan Data ke berapa yang ingin diubah : ";
    cin >> i;

    struct Node *current = head;
    int j = i - 1;
    int count = 0;

    while (count < j && current)
    {
        current = current->next;
        count++;
    }

    if (current)
    {
        switch (menu)
        {
        case 1:
            cin.ignore();
            cout << "NRP: ";
            getline(cin, current->data.nrp);
            break;
        case 2:
            cin.ignore();
            cout << "Nama: ";
            getline(cin, current->data.nama);
            break;
        case 3:
            cin.ignore();
            cout << "Jurusan: ";
            getline(cin, current->data.jurusan);
            break;
        case 4:
            cin.ignore();
            cout << "NRP: ";
            getline(cin, current->data.nrp);
            cout << "Nama: ";
            getline(cin, current->data.nama);
            cout << "No HP: ";
            getline(cin, current->data.jurusan);
            break;
        }
    }
    else
    {
        cout << "Data tidak ditemukan." << endl;
    }
}

void hapus(struct Node *&head, int &jumlah_mhs)
{
    int i;
    cout << "Masukkan data ke berapa yang ingin dihapus : ";
    cin >> i;

    if (i <= jumlah_mhs)
    {
        if (i == 1)
        {
            struct Node *temp = head;
            head = head->next;
            delete temp;
        }
        else
        {
            struct Node *current = head;
            struct Node *previous = nullptr;
            int count = 1;
            while (count < i)
            {
                previous = current;
                current = current->next;
                count++;
            }
            previous->next = current->next;
            delete current;
        }
        jumlah_mhs--;
        cout << "Data telah terhapus" << endl;
    }

    if (jumlah_mhs == 0)
    {
        head = nullptr;
    }
}

void search(struct Node *head)
{
    int i;
    cout << "Masukkan data ke berapa yang ingin dilihat : ";
    cin >> i;

    struct Node *current = head;
    int count = 1;
    while (count < i && current)
    {
        current = current->next;
        count++;
    }

    if (current)
    {
        cout << "\n==========Data ke-" << i << "==========" << endl;
        cout << "NRP : " << current->data.nrp << endl;
        cout << "Nama: " << current->data.nama << endl;
        cout << "Jurusan: " << current->data.jurusan << endl;
        cout << endl;
    }
    else
    {
        cout << "Data tidak ditemukan." << endl;
    }
}

int main()
{
    struct Node *head = nullptr;
    int menu;
    int jumlah_data = 0;
    do
    {
        cout << "\nPilih menu :\n";
        cout << "1. Tampilkan Data\n";
        cout << "2. Tambah Data Baru\n";
        cout << "3. Ubah Data\n";
        cout << "4. Hapus Data\n";
        cout << "5. Cari Data\n";
        cout << "6. Keluar\n";
        cout << "Masukkan pilihan (angka): ";
        cin >> menu;

        switch (menu)
        {
        case 1:
            tampil(head);
            break;
        case 2:
            tambah(head, jumlah_data);
            break;
        case 3:
            if (jumlah_data > 0)
            {
                ganti(head, jumlah_data);
            }
            else
            {
                cout << "\nTidak ada data yang dapat diubah. Inputkan data terlebih dahulu." << endl;
            }
            break;
        case 4:
            if (jumlah_data > 0)
            {
                hapus(head, jumlah_data);
            }
            else
            {
                cout << "\nJumlah Mahasiswa : 0" << endl;
            }
            break;
        case 5:
            if (jumlah_data > 0)
            {
                search(head);
            }
            else
            {
                cout << "\nData tidak tersedia" << endl;
            }
            break;
        case 6:
            break;
        default:
            cout << "\nGagal, pilihan salah. Coba lagi\n";
            break;
        };
    } while (menu != 6);

    return 0;
}