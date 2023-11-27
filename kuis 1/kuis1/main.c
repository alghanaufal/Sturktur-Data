#include "header.h"

int main()
{
    list L1, L2; // L1 untuk warung 1 dan L2 untuk warung 2
    createList(&L1);
    createList(&L2);

    int n1, n2; // jumlah menu kedua warung

    scanf("%d", &n1); // scan jumlah menu warung 1

    for (int i = 0; i < n1; i++)
    {
        makanan temp;
        scanf("%s %s %s", temp.jenis, temp.nama, temp.harga);
        addLast(temp.jenis, temp.nama, temp.harga, &L1); // gunakan addLast sehingga data urutan data sama dengan urutan scan
    }

    scanf("%d", &n2); // scan jumlah menu warung 2

    for (int i = 0; i < n2; i++)
    {
        makanan temp;
        scanf("%s %s %s", temp.jenis, temp.nama, temp.harga);
        addLast(temp.jenis, temp.nama, temp.harga, &L2); // gunakan addLast sehingga data urutan data sama dengan urutan scan
    }

    char tentu[250];
    char listke[250];
    scanf("%s %s", &listke, &tentu); // scan jumlah menu

    if (strcmp(listke, "pertama") == 0)
    {
        if (strcmp(tentu, "minuman") == 0)
        {
            for (int i = 0; i < n1; i++)
            {
                int urut = 0; // karena nama_kiri belum tentu menu yang ada di warung1, maka harus ada variabel untuk membedakan

                elemen *tukar1 = getAddressM(tentu, L1); // cari nama_kiri di list pertama
                if (tukar1 == NULL)                      // jika menu tidak ada di list pertama
                {
                    urut = 1;                        // maka urutan tukar nya nama_kiri ada di list2, nama_kanan ada di list1
                    tukar1 = getAddressM(tentu, L2); // lalu cari nama_kiri di list2
                }
                elemen *tukar2 = getAddressS(tentu, L1); // cari nama_kanan di list kedua
                if (tukar2 == NULL)                      // jika menu tidak ada di list pertama
                {
                    tukar2 = getAddressS(tentu, L2); // cari menu di list2
                }

                if (urut == 0) // jika urutan nya nama_kiri ada di list1 dan nama_kanan ada di list2
                {
                    swap(tukar1, tukar2, &L1, &L2); // masukkan argumen fungsi dengan urutan seperti ini
                }
                else // jika urutan nya nama_kiri ada di list2 dan nama_kanan ada di list1
                {
                    swap(tukar2, tukar1, &L1, &L2); // masukkan argumen fungsi dengan urutan seperti ini
                }
            }
            for (int i = 0; i < n2; i++)
            {
                int urut = 0; // karena nama_kiri belum tentu menu yang ada di warung1, maka harus ada variabel untuk membedakan

                elemen *tukar1 = getAddressM(tentu, L1); // cari nama_kiri di list pertama
                if (tukar1 == NULL)                      // jika menu tidak ada di list pertama
                {
                    urut = 1;                        // maka urutan tukar nya nama_kiri ada di list2, nama_kanan ada di list1
                    tukar1 = getAddressM(tentu, L2); // lalu cari nama_kiri di list2
                }
                elemen *tukar2 = getAddressS(tentu, L1); // cari nama_kanan di list kedua
                if (tukar2 == NULL)                      // jika menu tidak ada di list pertama
                {
                    tukar2 = getAddressS(tentu, L2); // cari menu di list2
                }

                if (urut == 0) // jika urutan nya nama_kiri ada di list1 dan nama_kanan ada di list2
                {
                    swap(tukar1, tukar2, &L1, &L2); // masukkan argumen fungsi dengan urutan seperti ini
                }
                else // jika urutan nya nama_kiri ada di list2 dan nama_kanan ada di list1
                {
                    swap(tukar2, tukar1, &L1, &L2); // masukkan argumen fungsi dengan urutan seperti ini
                }
            }
        }
        else if (strcmp(tentu, "snack") == 0)
        {
            for (int i = 0; i < n1; i++)
            {
                int urut = 0; // karena nama_kiri belum tentu menu yang ada di warung1, maka harus ada variabel untuk membedakan

                elemen *tukar1 = getAddressS(tentu, L1); // cari nama_kiri di list pertama
                if (tukar1 == NULL)                      // jika menu tidak ada di list pertama
                {
                    urut = 1;                        // maka urutan tukar nya nama_kiri ada di list2, nama_kanan ada di list1
                    tukar1 = getAddressS(tentu, L2); // lalu cari nama_kiri di list2
                }
                elemen *tukar2 = getAddressM(tentu, L1); // cari nama_kanan di list kedua
                if (tukar2 == NULL)                      // jika menu tidak ada di list pertama
                {
                    tukar2 = getAddressM(tentu, L2); // cari menu di list2
                }

                if (urut == 0) // jika urutan nya nama_kiri ada di list1 dan nama_kanan ada di list2
                {
                    swap(tukar1, tukar2, &L1, &L2); // masukkan argumen fungsi dengan urutan seperti ini
                }
                else // jika urutan nya nama_kiri ada di list2 dan nama_kanan ada di list1
                {
                    swap(tukar2, tukar1, &L1, &L2); // masukkan argumen fungsi dengan urutan seperti ini
                }
            }
            for (int i = 0; i < n2; i++)
            {
                int urut = 0; // karena nama_kiri belum tentu menu yang ada di warung1, maka harus ada variabel untuk membedakan

                elemen *tukar1 = getAddressS(tentu, L1); // cari nama_kiri di list pertama
                if (tukar1 == NULL)                      // jika menu tidak ada di list pertama
                {
                    urut = 1;                        // maka urutan tukar nya nama_kiri ada di list2, nama_kanan ada di list1
                    tukar1 = getAddressS(tentu, L2); // lalu cari nama_kiri di list2
                }
                elemen *tukar2 = getAddressM(tentu, L1); // cari nama_kanan di list kedua
                if (tukar2 == NULL)                      // jika menu tidak ada di list pertama
                {
                    tukar2 = getAddressM(tentu, L2); // cari menu di list2
                }

                if (urut == 0) // jika urutan nya nama_kiri ada di list1 dan nama_kanan ada di list2
                {
                    swap(tukar1, tukar2, &L1, &L2); // masukkan argumen fungsi dengan urutan seperti ini
                }
                else // jika urutan nya nama_kiri ada di list2 dan nama_kanan ada di list1
                {
                    swap(tukar2, tukar1, &L1, &L2); // masukkan argumen fungsi dengan urutan seperti ini
                }
            }
        }
    }

    if (strcmp(listke, "kedua") == 0)
    {
        if (strcmp(tentu, "minuman") == 0)
        {
            for (int i = 0; i < n1; i++)
            {
                int urut = 0; // karena nama_kiri belum tentu menu yang ada di warung1, maka harus ada variabel untuk membedakan

                elemen *tukar1 = getAddressM(tentu, L1); // cari nama_kiri di list pertama
                if (tukar1 == NULL)                      // jika menu tidak ada di list pertama
                {
                    tukar1 = getAddressM(tentu, L2); // lalu cari nama_kiri di list2
                }
                elemen *tukar2 = getAddressS(tentu, L1); // cari nama_kanan di list kedua
                if (tukar2 == NULL)                      // jika menu tidak ada di list pertama
                {
                    urut = 1;                        // maka urutan tukar nya nama_kiri ada di list2, nama_kanan ada di list1
                    tukar2 = getAddressS(tentu, L2); // cari menu di list2
                }

                if (urut == 0) // jika urutan nya nama_kiri ada di list1 dan nama_kanan ada di list2
                {
                    swap(tukar1, tukar2, &L1, &L2); // masukkan argumen fungsi dengan urutan seperti ini
                }
                else // jika urutan nya nama_kiri ada di list2 dan nama_kanan ada di list1
                {
                    swap(tukar2, tukar1, &L1, &L2); // masukkan argumen fungsi dengan urutan seperti ini
                }
            }
            for (int i = 0; i < n2; i++)
            {
                int urut = 0; // karena nama_kiri belum tentu menu yang ada di warung1, maka harus ada variabel untuk membedakan

                elemen *tukar1 = getAddressM(tentu, L1); // cari nama_kiri di list pertama
                if (tukar1 == NULL)                      // jika menu tidak ada di list pertama
                {
                    tukar1 = getAddressM(tentu, L2); // lalu cari nama_kiri di list2
                }
                elemen *tukar2 = getAddressS(tentu, L1); // cari nama_kanan di list kedua
                if (tukar2 == NULL)                      // jika menu tidak ada di list pertama
                {
                    urut = 1;                        // maka urutan tukar nya nama_kiri ada di list2, nama_kanan ada di list1
                    tukar2 = getAddressS(tentu, L2); // cari menu di list2
                }

                if (urut == 0) // jika urutan nya nama_kiri ada di list1 dan nama_kanan ada di list2
                {
                    swap(tukar1, tukar2, &L1, &L2); // masukkan argumen fungsi dengan urutan seperti ini
                }
                else // jika urutan nya nama_kiri ada di list2 dan nama_kanan ada di list1
                {
                    swap(tukar2, tukar1, &L1, &L2); // masukkan argumen fungsi dengan urutan seperti ini
                }
            }
        }
        else if (strcmp(tentu, "snack") == 0)
        {
            for (int i = 0; i < n1; i++)
            {
                int urut = 0; // karena nama_kiri belum tentu menu yang ada di warung1, maka harus ada variabel untuk membedakan

                elemen *tukar1 = getAddressS(tentu, L1); // cari nama_kiri di list pertama
                if (tukar1 == NULL)                      // jika menu tidak ada di list pertama
                {
                    tukar1 = getAddressS(tentu, L2); // lalu cari nama_kiri di list2
                }
                elemen *tukar2 = getAddressM(tentu, L1); // cari nama_kanan di list kedua
                if (tukar2 == NULL)                      // jika menu tidak ada di list pertama
                {
                    urut = 1;                        // maka urutan tukar nya nama_kiri ada di list2, nama_kanan ada di list1
                    tukar2 = getAddressM(tentu, L2); // cari menu di list2
                }

                if (urut == 0) // jika urutan nya nama_kiri ada di list1 dan nama_kanan ada di list2
                {
                    swap(tukar1, tukar2, &L1, &L2); // masukkan argumen fungsi dengan urutan seperti ini
                }
                else // jika urutan nya nama_kiri ada di list2 dan nama_kanan ada di list1
                {
                    swap(tukar2, tukar1, &L1, &L2); // masukkan argumen fungsi dengan urutan seperti ini
                }
            }
            for (int i = 0; i < n2; i++)
            {
                int urut = 0; // karena nama_kiri belum tentu menu yang ada di warung1, maka harus ada variabel untuk membedakan

                elemen *tukar1 = getAddressS(tentu, L1); // cari nama_kiri di list pertama
                if (tukar1 == NULL)                      // jika menu tidak ada di list pertama
                {
                    tukar1 = getAddressS(tentu, L2); // lalu cari nama_kiri di list2
                }
                elemen *tukar2 = getAddressM(tentu, L1); // cari nama_kanan di list kedua
                if (tukar2 == NULL)                      // jika menu tidak ada di list pertama
                {
                    urut = 1;                        // maka urutan tukar nya nama_kiri ada di list2, nama_kanan ada di list1
                    tukar2 = getAddressM(tentu, L2); // cari menu di list2
                }

                if (urut == 0) // jika urutan nya nama_kiri ada di list1 dan nama_kanan ada di list2
                {
                    swap(tukar1, tukar2, &L1, &L2); // masukkan argumen fungsi dengan urutan seperti ini
                }
                else // jika urutan nya nama_kiri ada di list2 dan nama_kanan ada di list1
                {
                    swap(tukar2, tukar1, &L1, &L2); // masukkan argumen fungsi dengan urutan seperti ini
                }
            }
        }
    }

    printElement(L1);
    printElement(L2);

    return 0;
}