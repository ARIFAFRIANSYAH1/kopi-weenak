#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Pemain {
  string nama;
  string nim;
  string jurusan;
  float tinggi;
};

const int MAX_SIZE = 100;
Pemain queuePemain[MAX_SIZE];
int front = -1, rear = -1;

bool isFull() {
  	if (rear == MAX_SIZE - 1) {
    	return true;
  	}
  	return false;
}

bool isEmpty() {
  	if (front == -1 || front > rear) {
    	return true;
  	}
  	return false;
}

void enqueue() {
  	if (isFull()) {
    	cout << "Antrian penuh!" << endl;
  	}
	else {
  		system("cls");
	    Pemain volly;
	    cout << "Masukkan data pemain:" << endl;
	    cout << "Nama: ";
	    getline(cin, volly.nama);
	    cout << "NIM: ";
	    getline(cin, volly.nim);
	    cout << "Jurusan: ";
	    getline(cin, volly.jurusan);
		cout << "Tinggi: ";
		cin >> volly.tinggi;
		cin.ignore();
	    if (front == -1) {
	      	front = 0;
    }
    rear++;
    queuePemain[rear] = volly;
    system("cls");
    cout << "Data pemain berhasil dimasukkan ke dalam antrian." << endl << endl;
  }
}

void dequeue() {
  	if (isEmpty()) {
	    cout << "Antrian kosong!" << endl;
	  	}
	 	else {
	 		system("cls");
	    	cout << "Data pemain " << queuePemain[front].nama << " berhasil dihapus." << endl << endl;
	    	front++;
  		}
}

void tampil() {
  	if (isEmpty()) {
    	cout << "Antrian kosong!" << endl;
  	}
	else {
  		system("cls");
  		cout << "========================================================" << endl;
    	cout << "|            Data Pemain Volly UNIBA MADURA             |" << endl;
    	cout << "========================================================" << endl;
    	for (int i = front; i <= rear; i++) {
      		cout << "Nama: " << queuePemain[i].nama << endl;
      		cout << "NIM: " << queuePemain[i].nim << endl;
      		cout << "Jurusan: " << queuePemain[i].jurusan << endl;
      		cout << "Tinggi: " << queuePemain[i].tinggi << endl;
      		cout << "========================================================" << endl; 
    	}
  	}
}

bool comparePemain(Pemain mhs1, Pemain mhs2) {
  return mhs1.tinggi < mhs2.tinggi;
}

void pengururtan() {
  	if (isEmpty()) {
    	cout << "Antrian kosong!" << endl;
  	}
	else {
		system("cls");
		sort(queuePemain + front, queuePemain + rear + 1, comparePemain);
    	cout << "Data pemain berhasil diurutkan berdasarkan tinggi." << endl;
  	}
}

void urutan(){
	cout << "==============================================================================" << endl;
	cout << "| Data Data Pemain volly UNIBA MADURA yang sudah diurutkan berdasarkan tinggi|" << endl;
	cout << "==============================================================================" << endl;
	for (int i = front; i <= rear; i++) {
		cout << "Nama: " << queuePemain[i].nama << endl;
		cout << "NIM: " << queuePemain[i].nim << endl;
		cout << "Jurusan: " << queuePemain[i].jurusan << endl;
		cout << "Tinggi: " << queuePemain[i].tinggi << endl;
		cout << "========================================================" << endl;            
	}
}

int main() {
  	int pilihan;
  	char kembali;

  	menu :
  		
	    cout << "========================================================" << endl;
	    cout << "|                       M E N U                        |" << endl;
	    cout << "========================================================" << endl;
	    cout << "| 1. Masukkan data pemain                              |" << endl;
	    cout << "| 2. Hapus data pemain terakhir                        |" << endl;
	    cout << "| 3. Tampilkan data pemain                             |" << endl;
	    cout << "| 4. Urutkan data pemain berdasarkan tinggi            |" << endl;
	    cout << "| 5. Tampilkan data pemain yang sudah diurutkan        |" << endl;
	    cout << "| 6. Keluar                                            |" << endl;
	    cout << "========================================================" << endl;
	    cout << "\nPilihan Menu: ";
	    cin >> pilihan;
	    cin.ignore();
	    
	    if ( pilihan == 1 ) {
	        enqueue();
	        goto menu;
	    }
		else if ( pilihan == 2 ) {
			system("cls");
			dequeue();
			goto menu;
		}
		else if ( pilihan == 3 ) {
			system("cls");
			tampil();
			pil :
				cout << "\nKembali Ke Menu? y/t : ";
				cin >> kembali;
				if ( kembali == 'y' ) {
					system("cls");
					goto menu;
				}
				else if ( kembali == 't' ) {
					system("cls");
					cout << "TERIMA KASIH!" << endl;
				}
				else if ( kembali != 'y/t' ) {
					tampil();
					cout << "\nPilihan tidak valid" << endl;
					goto pil;
			}
		}
		else if ( pilihan == 4 ) {
			system("cls");
			pengururtan();
			goto menu;
		}
		else if ( pilihan == 5 ) {
			system("cls");
			if (isEmpty()) {
	          	cout << "Antrian kosong!" << endl;
	          	goto menu;
	        }
			else {
				urutan();
				pick :
		         	cout << "\nKembali Ke Menu? y/t : ";
					cin >> kembali;
					if ( kembali == 'y' ) {
						system("cls");
						goto menu;
					}
					else if ( kembali == 't' ) {
						system("cls");
						cout << "TERIMA KASIH!" << endl;
					}
					else if ( kembali != 'y/t' ) {
						urutan();
						cout << "\nPilihan tidak valid" << endl;
						goto pick;
		        }
		    }
		}
	    else if ( pilihan == 6 ) {
	    	system("cls");
	    	cout << "TERIMA KASIH!" << endl;
		}
		else if ( pilihan != 6 ) {
			system("cls");
			cout << "Mohon Maaf, pilihan anda Tidak Valid!" << endl;
			cout << "Silahkan pilih kembali !" << endl;
			goto menu;
		}
  return 0;
}