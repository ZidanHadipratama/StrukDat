#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Titik
{
public:
    int id;
    string nama;
    int x;
    int y;

    Titik(int id, const string &nama, int x, int y)
        : id(id), nama(nama), x(x), y(y) {}
};

class Peta
{
public:
    vector<Titik> titikList;
    vector<vector<int>> adjacencyList;

    void tambahTitik(const Titik &titik)
    {
        titikList.push_back(titik);
        adjacencyList.push_back({});
    }

    void tambahEdge(int from, int to)
    {
        adjacencyList[from].push_back(to);
    }

    void tampilkanAdjacencyList()
    {
        for (size_t i = 0; i < adjacencyList.size(); ++i)
        {
            cout << "Tempat " << titikList[i].nama << " terhubung ke: ";
            for (size_t j = 0; j < adjacencyList[i].size(); ++j)
            {
                cout << titikList[adjacencyList[i][j]].nama << " ";
            }
            cout << endl;
        }
    }

    void hapusTitik(int id)
    {
        if (id >= 0 && id < static_cast<int>(titikList.size()))
        {
            // Hapus titik dari adjacency list
            adjacencyList.erase(adjacencyList.begin() + id);
            for (size_t i = 0; i < adjacencyList.size(); ++i)
            {
                for (size_t j = 0; j < adjacencyList[i].size(); ++j)
                {
                    if (adjacencyList[i][j] == id)
                    {
                        adjacencyList[i].erase(adjacencyList[i].begin() + j);
                    }
                }
            }

            // Hapus titik dari daftar titik
            titikList.erase(titikList.begin() + id);
        }
    }

    void editTitik(int id, const Titik &titik)
    {
        if (id >= 0 && id < static_cast<int>(titikList.size()))
        {
            // Edit informasi titik
            titikList[id] = titik;
        }
    }
};

int main()
{
    Peta peta;

    while (true)
    {
        cout << "Menu:\n";
        cout << "1. Tambah Titik\n";
        cout << "2. Hapus Titik\n";
        cout << "3. Edit Titik\n";
        cout << "4. Tambah Edge\n";
        cout << "5. Tampilkan Adjacency List\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu (1/2/3/4/5/6): ";

        int pilihan;
        cin >> pilihan;

        if (pilihan == 1)
        {
            // Tambah titik
            int id, x, y;
            string nama;
            cout << "ID Titik: ";
            cin >> id;
            cout << "Nama Tempat: ";
            cin.ignore();
            getline(cin, nama);
            cout << "Koordinat X: ";
            cin >> x;
            cout << "Koordinat Y: ";
            cin >> y;
            peta.tambahTitik(Titik(id, nama, x, y));
        }
        else if (pilihan == 2)
        {
            // Hapus titik
            int id;
            cout << "ID Titik yang akan dihapus: ";
            cin >> id;
            peta.hapusTitik(id);
        }
        else if (pilihan == 3)
        {
            // Edit titik
            int id, x, y;
            string nama;
            cout << "ID Titik yang akan diedit: ";
            cin >> id;
            cout << "Nama Tempat baru: ";
            cin.ignore();
            getline(cin, nama);
            cout << "Koordinat X baru: ";
            cin >> x;
            cout << "Koordinat Y baru: ";
            cin >> y;
            peta.editTitik(id, Titik(id, nama, x, y));
        }
        else if (pilihan == 4)
        {
            // Tambah edge
            int from, to;
            cout << "ID Titik Asal: ";
            cin >> from;
            cout << "ID Titik Tujuan: ";
            cin >> to;
            peta.tambahEdge(from, to);
        }
        else if (pilihan == 5)
        {
            // Tampilkan adjacency list
            cout << "Adjacency List:" << endl;
            peta.tampilkanAdjacencyList();
        }
        else if (pilihan == 6)
        {
            // Keluar dari program
            break;
        }
        else
        {
            cout << "Pilihan tidak valid. Silakan pilih kembali.\n";
        }
    }

    return 0;
}
