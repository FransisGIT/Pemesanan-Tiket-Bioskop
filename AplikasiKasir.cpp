#include <iostream>
#include <iomanip>

using namespace std;
int main()
{

    cout << "=== Program Kasir Toko Elektronik ===";
    cout << endl;

    const int max_item(10);
    string namaItem[max_item];
    long hargaItem[max_item];
    int jumlahItem[max_item];
    long jumlahTotalBarang;
    long totalHarga(0);
    long jumlahBayar(0);

    cout << ("=== Selamat Datang di Toko Elektronik ===") << endl;
    cout << endl;

    cout << ("MASUKKAN JUMLAH YANG INGIN DIBELI: ") << endl;
    cin >> jumlahTotalBarang;
    cout << endl;

    if (jumlahTotalBarang <= 0 || jumlahTotalBarang > max_item)
    {
        cout << "Jumlah barang tidak valid!" << endl;
        return 0;
    }
    for (int i = 0; i < jumlahTotalBarang; i++)
    {
        cout << "Barang ke-" << i + 1 << endl;
        cout << "Nama barang : ";
        getline(cin >> ws, namaItem[i]);
        cout << "Harga satuan : ";
        cin >> hargaItem[i];
        cout << "Jumlah" << namaItem[i] << "yang dibeli: ";
        cin >> jumlahItem[i];
        cout << endl;
    }
    cout << endl;

    cout << "===================================" << endl;
    cout << "======= Struk Pembelian Item=======" << endl;
    cout << "===================================" << endl;
    cout << "No    Barang    Jumlah    Harga Satuan     Sub Total" << endl;

    for (int i = 0; i < jumlahTotalBarang; i++)
    {
        cout << setw(1) << i + 1 << " ";
        cout << left << setw(12) << namaItem[i];
        cout << right << setw(5) << jumlahItem[i];
        cout << setw(18) << hargaItem[i];
        cout << setw(15) << (jumlahItem[i] * hargaItem[i]);
        cout << endl;

        totalHarga = totalHarga + (jumlahItem)[i] * hargaItem[i];
    }
    cout << "===================================" << endl;
    cout << "Total harga :Rp." << totalHarga << endl
         << endl;

    cout << "Jumlah Bayar: Rp.";
    cin >> jumlahBayar;
    cout << endl;

    while (jumlahBayar - totalHarga < 0)
    {
        cout << "Maaf, uang anda kurang. mohon lakukan ulang pembayaran" << endl;
        cout << "Jumlah Bayar: Rp.";
        cin >> jumlahBayar;
        cout << endl;
    }

    cout << "Kembalian     : Rp." << jumlahBayar - totalHarga << endl;

    cout << "===================================" << endl;
    cout << "=====Thank You for Shopping ;3=====" << endl;
    cout << "===================================" << endl;

    return 0;
}
