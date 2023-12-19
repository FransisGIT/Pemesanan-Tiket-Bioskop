// untuk menggunakan fungsi input dan output
#include <iostream>
// untuk menyimpan input yang telah dibuat
#include <fstream>
// ini digunakan untuk menampilkan message box
#include <windows.h>
// using namespace std berguna untuk supaya kita tidak perlu lagi mengetik seperti std::cout/cin
using namespace std;

int main()
{
    const int max(50);
    bool lanjut = true;
    string film[max], nama_pemesan[max], tmpt_duduk[max];
    int harga[max], nomor_tiket(0);
    long jumlah_tiket;
    long totalHarga(0);
    // ini digunakan untuk membaca setiap baris dari file satu persatu di dalam file pemesanan_tiket.txt
    ifstream nomorUrutan("data/pemesanan_tiket.txt");
    string line;

    // untuk melanjutkan nomor urut pesanan yang sudah terdata pada file pemesanan_tiket.txt agar tidak duplikat urutannya
    while (getline(nomorUrutan, line))
    {
        nomor_tiket++;
    }

    // fungsi untuk membuat file pemesanan tiket
    ofstream outputFile("data/pemesanan_tiket.txt", ios::app);

    while (lanjut)
    {
        cout << "===========================================================================" << endl;
        cout << "========================= Pemesanan Tiket Bioskop =========================" << endl;
        cout << "===========================================================================" << endl;
        cout << endl;
        // jika jumlah pesanan tiket valid maka program akan lanjut ke tahap pemasukkan data pemesan
        //  jika jumlah pesanan tiket tidak valid maka program akan menyuruh untuk memasukkan jumlah yang valid
        do
        {
            // menampilkan output untuk input memasukkan jumlah tiket
            cout << "Masukkan jumlah tiket yang ingin dipesan: ";
            cin >> jumlah_tiket;

            // jika jumlah tiket sama dengan 0 atau kurang dari 0 maka program akan melakukan tahap dibawah ini
            if (jumlah_tiket <= 0)
            {
                // menampilkan output untuk pemberitahuan tidak valid saat jumlah tiket tidak valid
                cout << "Masukkan jumlah tiket yang valid!" << endl;
            }
        } while (jumlah_tiket <= 0);

        totalHarga = 0;

        // memasukkan data pemesan tiket
        for (int i = 0; i < jumlah_tiket; i++)
        {
            cout << endl;
            cout << "Tiket ke-" << nomor_tiket + 1 << endl;
            // menampilkan output untuk input Nama pemesan
            cout << "Nama pemesan: ";
            cin.ignore();

            // menampilkan input untuk nama pemesanan tiket
            getline(cin, nama_pemesan[i]);

            // menampilkan output untuk input Film yang dipesan
            cout << "Film yang dipesan: ";

            // menampilkan input untuk film yang mau dipesan
            getline(cin, film[i]);

            // menampilkan output untuk input Harga tiket
            cout << "Harga tiket: ";

            cin >> harga[i];
            // menampilkan output untuk input tempat tempat duduk

            // menampilkan output untuk pemesanan tempat duduk
            cout << "Tempat duduk: ";

            cin.ignore();

            // menampilkan input untuk pemesanan tempat duduk
            getline(cin, tmpt_duduk[i]);
            cout << endl;
            totalHarga += harga[i];
            cout << "===========================================================================" << endl;
        }

        // Menampilkan detail dari pemesan tiket
        cout << "========================= Struk Pemesanan Tiket ============================" << endl;
        cout << "===========================================================================" << endl;
        cout << "NO    \tPEMESAN    \tTEMPAT DUDUK    \tHARGA     \tFILM" << endl;

        // fungsi ini untuk mengulang detail pesanan dari jumlah tiket yang dipesan
        for (int i = 0; i < jumlah_tiket; i++)
        {
            // menampilkan detail dari pesanan tiket/ Struk
            cout << i + 1;
            cout << "\t" << nama_pemesan[i];
            cout << "\t\t" << tmpt_duduk[i];
            cout << "\t\t\t" << harga[i];
            cout << "\t\t" << film[i];
            while (lanjut)
            {
                // Menulis data dari pesanan tiket ke file pemesanan_tiket.txt
                outputFile << nomor_tiket + 1 << ',' << nama_pemesan[i] << ',' << film[i] << ',' << harga[i] << ',' << tmpt_duduk[i] << '\n';
                nomor_tiket++;
                // untuk memberhentikan program while
                break;
            }
            cout << endl
                 << endl;
        }

        // menampilkan total harga dari semua pesanan tiket
        cout << "Total harga: " << totalHarga << endl
             << endl;
        cout << "===========================================================================" << endl;

        // untuk membuat pemberitahuan pop up message bahwa pesanan tiket telah dibuat
        MessageBoxW(NULL, L"Pesanan Tiket telah dibuat", L"Informasi", MB_ICONINFORMATION | MB_TOPMOST);
        cout << "Data telah disimpan di 'data/pemesanan_tiket.txt'" << endl;

        // menampilkan pemberitahuan apakah user ingin memesan tiket lagi
        cout << "Apakah anda ingin memesan tiket lagi? (y/n): ";

        char input;
        cin >> input;

        // kode ini untuk mengulang lagi ketika user ingin memesan tiket lagi
        // jika user memasukkan input selain huruf y maka program akan berhenti
        if (input != 'y')
        {
            lanjut = false;
        }
    }

    // Menutup file setelah selesai seluruh proses
    outputFile.close();

    return 0;
}
