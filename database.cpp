#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa
{
    string nama;
    string jurusan;
    string NRP;
    int angkatan;
    string nomorTelepon;
    string tempatTinggal;
    string asal;
    string kelas;
    string dosenWali;
    string organisasi;
};

void tampilkanData(const Mahasiswa &mahasiswa)
{
    cout << "Nama: " << mahasiswa.nama << endl;
    cout << "Jurusan: " << mahasiswa.jurusan << endl;
    cout << "NRP: " << mahasiswa.NRP << endl;
    cout << "Angkatan: " << mahasiswa.angkatan << endl;
    cout << "Nomor Telepon: " << mahasiswa.nomorTelepon << endl;
    cout << "Tempat Tinggal: " << mahasiswa.tempatTinggal << endl;
    cout << "Asal: " << mahasiswa.asal << endl;
    cout << "Kelas: " << mahasiswa.kelas << endl;
    cout << "Dosen Wali: " << mahasiswa.dosenWali << endl;
    cout << "Organisasi: " << mahasiswa.organisasi << endl;
}

int main()
{
    const int maxMahasiswa = 100;
    Mahasiswa daftarMahasiswa[maxMahasiswa];
    int jumlahMahasiswa = 0;

    while (true)
    {
        cout << "Menu:" << endl;
        cout << "1. Tampilkan Data" << endl;
        cout << "2. Tambah Data" << endl;
        cout << "3. Ubah Data" << endl;
        cout << "4. Hapus Data" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";

        int pilihan;
        cin >> pilihan;
        cin.ignore(); // Membersihkan newline ('\n') dari buffer

        if (pilihan == 1)
        {
            cout << "Daftar Mahasiswa:" << endl;
            for (int i = 0; i < jumlahMahasiswa; i++)
            {
                cout << "Mahasiswa ke-" << (i + 1) << endl;
                tampilkanData(daftarMahasiswa[i]);
            }
        }
        else if (pilihan == 2)
        {
            if (jumlahMahasiswa < maxMahasiswa)
            {
                cout << "Masukkan data mahasiswa baru:" << endl;
                cout << "Nama: ";
                getline(cin, daftarMahasiswa[jumlahMahasiswa].nama);
                cout << "Jurusan: ";
                getline(cin, daftarMahasiswa[jumlahMahasiswa].jurusan);
                cout << "NRP: ";
                getline(cin, daftarMahasiswa[jumlahMahasiswa].NRP);
                cout << "Angkatan: ";
                cin >> daftarMahasiswa[jumlahMahasiswa].angkatan;
                cin.ignore(); // Membersihkan newline ('\n') dari buffer

                cout << "Nomor Telepon: ";
                getline(cin, daftarMahasiswa[jumlahMahasiswa].nomorTelepon);
                cout << "Tempat Tinggal: ";
                getline(cin, daftarMahasiswa[jumlahMahasiswa].tempatTinggal);
                cout << "Asal: ";
                getline(cin, daftarMahasiswa[jumlahMahasiswa].asal);
                cout << "Kelas: ";
                getline(cin, daftarMahasiswa[jumlahMahasiswa].kelas);
                cout << "Dosen Wali: ";
                getline(cin, daftarMahasiswa[jumlahMahasiswa].dosenWali);
                cout << "Organisasi: ";
                getline(cin, daftarMahasiswa[jumlahMahasiswa].organisasi);

                jumlahMahasiswa++;
                cout << "Data mahasiswa telah ditambahkan." << endl;
            }
            else
            {
                cout << "Batas maksimum jumlah mahasiswa telah tercapai." << endl;
            }
        }
        else if (pilihan == 3)
        {
            cout << "Masukkan nama mahasiswa yang akan diubah: ";
            string namaTarget;
            getline(cin, namaTarget);

            bool ditemukan = false;
            for (int i = 0; i < jumlahMahasiswa; i++)
            {
                if (daftarMahasiswa[i].nama == namaTarget)
                {
                    cout << "Data mahasiswa yang akan diubah:" << endl;
                    tampilkanData(daftarMahasiswa[i]);

                    cout << "Masukkan data mahasiswa yang baru:" << endl;
                    cout << "Nama: ";
                    getline(cin, daftarMahasiswa[i].nama);
                    cout << "Jurusan: ";
                    getline(cin, daftarMahasiswa[i].jurusan);
                    cout << "NRP: ";
                    getline(cin, daftarMahasiswa[i].NRP);
                    cout << "Angkatan: ";
                    cin >> daftarMahasiswa[i].angkatan;
                    cin.ignore(); // Membersihkan newline ('\n') dari buffer

                    cout << "Nomor Telepon: ";
                    getline(cin, daftarMahasiswa[i].nomorTelepon);
                    cout << "Tempat Tinggal: ";
                    getline(cin, daftarMahasiswa[i].tempatTinggal);
                    cout << "Asal: ";
                    getline(cin, daftarMahasiswa[i].asal);
                    cout << "Kelas: ";
                    getline(cin, daftarMahasiswa[i].kelas);
                    cout << "Dosen Wali: ";
                    getline(cin, daftarMahasiswa[i].dosenWali);
                    cout << "Organisasi: ";
                    getline(cin, daftarMahasiswa[i].organisasi);

                    cout << "Data mahasiswa telah diubah." << endl;
                    ditemukan = true;
                    break;
                }
            }

            if (!ditemukan)
            {
                cout << "Mahasiswa dengan nama " << namaTarget << " tidak ditemukan." << endl;
            }
        }
        else if (pilihan == 4)
        {
            cout << "Masukkan nama mahasiswa yang akan dihapus: ";
            string namaTarget;
            getline(cin, namaTarget);

            bool ditemukan = false;
            for (int i = 0; i < jumlahMahasiswa; i++)
            {
                if (daftarMahasiswa[i].nama == namaTarget)
                {
                    for (int j = i; j < jumlahMahasiswa - 1; j++)
                    {
                        daftarMahasiswa[j] = daftarMahasiswa[j + 1];
                    }
                    jumlahMahasiswa--;
                    cout << "Data mahasiswa telah dihapus." << endl;
                    ditemukan = true;
                    break;
                }
            }

            if (!ditemukan)
            {
                cout << "Mahasiswa dengan nama " << namaTarget << " tidak ditemukan." << endl;
            }
        }
        else if (pilihan == 5)
        {
            break;
        }
        else
        {
            cout << "Pilihan tidak valid. Silakan pilih menu yang sesuai." << endl;
        }
    }

    return 0;
}
