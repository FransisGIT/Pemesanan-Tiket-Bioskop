#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << "==== Biodata Mahasiswa ====" << endl;
    cout << "===========================" << endl;

    string nama, nim, fakultas, jurusan, kota_asal, alamat;
    bool lanjut = true;

    while (lanjut)
    {
        cout << "Nama Mahasiswa: ";
        getline(cin, nama);

        cout << "NIM: ";
        getline(cin, nim);

        cout << "Fakultas: ";
        getline(cin, fakultas);

        cout << "Jurusan: ";
        getline(cin, jurusan);

        cout << "Kota_asal: ";
        getline(cin, kota_asal);

        cout << "Alamat: ";
        getline(cin, alamat);

        cout << "===== data Mahasiswa =====" << endl;
        cout << "Nama Mahasiswa: " << nama << endl;
        cout << "Nim: " << nim << endl;
        cout << "Fakultas: " << fakultas << endl;
        cout << "Jurusan: " << jurusan << endl;
        cout << "Kota_asal: " << kota_asal << endl;
        cout << "Alamat: " << alamat << endl;

        cout << "Apakah ingin input data lagi? (y/n) ";
        char input;
        cin >> input;

        if (input != 'y' || 'Y')
        {
            lanjut = false;
        }
    }

    return 0;
}
