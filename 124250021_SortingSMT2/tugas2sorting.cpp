#include <iostream>
#include <string>
using namespace std;
// buble sort asc rumus
void bubbleSort(string arr[], int n)
{ for (int i = 0; i < n - 1; i++) 
	{for (int j = 0; j < n - 1 - i; j++) 
		{if (arr[j] > arr[j + 1]) 
			{swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// quick sort desc rumus
void quickSort(string arr[], int low, int high) 
{int i = low, j = high;
 string pivot = arr[(low + high) / 2];
    while (i <= j) {
        while (arr[i] > pivot)  
            i++;
        while (arr[j] < pivot)  
            j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (low < j)
        quickSort(arr, low, j);
    if (i < high)
        quickSort(arr, i, high);
}

// inputan user
void inputData(string arr[], int &n) {
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        cout << "Nama ke-" << i + 1 << " : ";
        getline(cin, arr[i]);
    }
}

// hasil pengurutan 
void tampilData(string arr[], int n) {
    cout << "\nHasil Pengurutan:\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << arr[i] << endl;
    }
    cout << endl;
}

int main() {
    const int MAX = 100;
    string nama[MAX];
    int n, pilihan;
    char ulang;

    do {
        cout << "================= MENU ================="<<endl;
        cout << "1. Bubble Sort (Ascending)"<<endl;
        cout << "2. Quick Sort (Descending)"<<endl;
        cout << "3. Keluar"<<endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        if (pilihan == 1) {
            do {
                inputData(nama, n);
                bubbleSort(nama, n);
                tampilData(nama, n);
                cout << "Ulangi Bubble Sort? (y/n): ";
                cin >> ulang;
            } while (ulang == 'y' || ulang == 'Y');
        } else if (pilihan == 2) {
            do {
                inputData(nama, n);
                quickSort(nama, 0, n - 1);
                tampilData(nama, n);
                cout << "Ulangi Quick Sort? (y/n): ";
                cin >> ulang;
            } while (ulang == 'y' || ulang == 'Y');
        } else if (pilihan == 3) {
            cout << "Program selesai terimakasih sudah menggunakan."<<endl;
        } else {
            cout << "Pilihan tidak valid!"<<endl;
        }
    } while (pilihan != 3);
    return 0;
}
