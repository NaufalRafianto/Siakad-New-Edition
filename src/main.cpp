#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

#include "include/person.hpp"
#include "include/mahasiswa.hpp"
#include "include/dosen.hpp"
#include "include/tendik.hpp"
#include "include/matkul.hpp"

using namespace std;

void cls()
{
    system("cls") && system("clear");
}

int main()
{
    vector<mahasiswa> recMhs;
    vector<dosen> recDosen;
    vector<tendik> recTendik;
    vector<matkul> recMatkul;

    int menu_terpilih;
    float ips;
    float ipk = 0, asal = 0;
    int idS = 0, idL = 0, idSt = 0, idUser = 0, idMatkul = 0;
    long unsigned i;
    string id, name, studentID, staffID, department, unit, showGPA, user, menuAdmin, education;
    char repeat, mengeditIP;
    int bornYear, bornMonth, bornDay, yearEntry, semester;
    int menu = 0;
    cout << "Login as: ";
    cin >> user;

    if (user == "Admin" or user == "admin")
    {
        menu = 1;
    }
    else if (user == "Mahasiswa" or user == "mahasiswa")
    {
        menu = 2;
    }
    else if (user == "tendik" or user == "Tendik")
    {
        menu = 3;
    }
    else if (user == "dosen" or user == "Dosen")
    {
        menu = 4;
    }
    else
    {
        cout << "User was not Found" << endl;
    }

    while (menu == 1)
    {
        cls();
        cout << "Selamat datang di Institut Teknologi Suka Suka" << endl;
        cout << "Data statistik:" << endl;
        cout << "  1. Jumlah Mahasiswa             : " << recMhs.size() << " Mahasiswa" << endl;
        cout << "  2. Jumlah Dosen                 : " << recDosen.size() << " Orang" << endl;
        cout << "  3. Jumlah Tenaga Kependidikan   : " << recTendik.size() << " Orang" << endl;
        cout << "  4. Jumlah Matkul   : " << recMatkul.size() << " Buah" << endl;
        cout << endl;
        cout << "Menu: " << endl;
        cout << "  1. Tambah Mahasiswa" << endl;
        cout << "  2. Tambah Dosen" << endl;
        cout << "  3. Tambah Tenaga Kependidikan" << endl;
        cout << "  4. Tambah Mata Kuliah " << endl;
        cout << "  5. Tampilkan semua Mahasiswa" << endl;
        cout << "  6. Tampilkan semua Dosen" << endl;
        cout << "  7. Tampilkan semua Tenaga Kependidikan" << endl;
        cout << "  8. Tampilkan semua Matkul" << endl;
        cout << "  9. Ganti User" << endl;
        cout << "  10. Tutup Program" << endl;
        cout << "-> Silahkan memilih salah satu: ";
        cin >> menu_terpilih;
        switch (menu_terpilih)
        {
        case 1:
        {
            cls();
            idS++;
            id = to_string(idS);
            cout << "Masukkan Nama Mahasiswa: ";
            getline(cin >> ws, name);
            cout << "Masukkan Tanggal Lahir : ";
            cin >> bornDay;
            cout << "Masukkan Bulan Lahir : ";
            cin >> bornMonth;
            cout << "Masukkan Tahun Lahir : ";
            cin >> bornYear;
            cout << "Masukkan NRP : ";
            cin >> studentID;
            cout << "Masukkan Departemen : ";
            getline(cin >> ws, department);
            cout << "Masukkan Tahun Masuk : ";
            cin >> yearEntry;
            cout << "Masukkan Semester: ";
            cin >> semester;
            mahasiswa inputStudent = mahasiswa(id, name, bornDay, bornMonth, bornYear, studentID, department, semester);
            recMhs.push_back(inputStudent);
        }
        break;
        case 2:
        {
            cls();
            idL++;
            id = to_string(idL);
            cout << "Masukkan Nama Dosen: ";
            cin >> name;
            cout << "Masukkan Tanggal Lahir : ";
            cin >> bornDay;
            cout << "Masukkan Bulan Lahir : ";
            cin >> bornMonth;
            cout << "Masukkan Tahun Lahir : ";
            cin >> bornYear;
            cout << "Masukkan NPP : ";
            cin >> staffID;
            cout << "Masukkan Departemen : ";
            getline(cin >> ws, department);
            cout << "Masukkan Riwayat Pendidikan : ";
            getline(cin >> ws, education);
            dosen inputLecturer = dosen(id, name, bornDay, bornMonth, bornYear, staffID, department, education);
            recDosen.push_back(inputLecturer);
        }
        break;
        case 3:
        {
            cls();
            idSt++;
            id = to_string(idSt);
            cout << "Masukkan Nama Tendik : ";
            cin >> name;
            cout << "Masukkan Tanggal Lahir : ";
            cin >> bornDay;
            cout << "Masukkan Bulan Lahir : ";
            cin >> bornMonth;
            cout << "Masukkan Tahun Lahir : ";
            cin >> bornYear;
            cout << "Masukkan NPP : ";
            cin >> staffID;
            cout << "Masukkan Unit : ";
            getline(cin, unit);
            tendik inputTendik = tendik(id, name, bornDay, bornMonth, bornYear, staffID, unit);
            recTendik.push_back(inputTendik);
        }
        break;
        case 4:
        {
            cls();
            string namaMatkul;
            idMatkul++;
            id = to_string(idMatkul);
            cout << "Masukkan Mata Kuliah : ";
            cin >> namaMatkul;
            matkul inputMatkul(id, namaMatkul);
            recMatkul.push_back(inputMatkul);
        }
        break;
        case 5:
        {
            if (recMhs.size() == 0)
            {
                cout << "Data tidak ditemukan!" << endl;
                cout << "Tekan apapun untuk kembali ke menu..." << endl;
                return main();
            }
            else if (recMhs.size() != 0)
            {
                for (int i = 0; i < recMhs.size(); i++)
                {
                    cout << "Nama: " << recMhs[i].getNama() << "-- ( " << recMhs[i].getId() << " )" << endl;
                }
                cout << "Pilih berdasarkan ID: ";
                cin >> idUser;
            }
            if ((idUser > recMhs.size()))
            {
                cls();
                cout << "Data tidak ditemukan!" << endl;
                cout << "Tekan apapun untuk kembali ke menu..." << endl;
                return main();
            }
            cls();
            for (int i = 0; i < recMhs.size(); i++)
            {
                cout << "---------------------------------- Data Mahasiswa --------------------------------" << endl;
                cout << " ID Mahasiswa: " << idUser << endl;
                cout << "Nama : " << recMhs[idUser - 1].getNama() << endl;
                cout << "Tanggal Lahir : " << recMhs[idUser - 1].getTglLahir() << "/" << recMhs[idUser - 1].getBulanLahir() << "/" << recMhs[idUser - 1].getTahunLahir() << endl;
                cout << "NRP : " << recMhs[idUser - 1].getNRP() << endl;
                cout << "Departemen : " << recMhs[idUser - 1].getDepartment() << endl;
                // cout << "Tahun Masuk : " << recMhs[i].getTahunMasuk() << endl;
                cout << "Semester : " << recMhs[idUser - 1].getSemester() << endl;
                cout << "Jumlah SKS yang Lulus : " << recMhs[i].getSKSLulus() << endl;
            }
            cout << "Pilih Salah satu : " << endl;
            cout << "-------------------------------------------------------" << endl;
            cout << "Menu Tambahan: " << endl;
            cout << "  1. Input IP Semester" << endl;
            cout << "  2. Lihat IPS dan IPK " << endl;
            cout << "  3. Kembali ke Menu Utama" << endl;
            cin >> mengeditIP;

            switch (mengeditIP)
            {
            case 1:
            {
                cls();
                for (int i = 1; i <= recMhs[idUser - 1].getSemester(); i++)
                {
                    cout << "Masukkan IP Semester ke-" << i << ":" << endl;
                    semester = i;
                    cin >> ips;
                }
                recMhs[idUser - 1].setIPS(semester, ips);
            }
            break;
            case 2:
            {
                cls();
                if (recMhs[idUser - 1].getIPS(1) == 0 && recMhs[idUser - 1].getIPS(2) == 0)
                {
                    cout << "IP Semester dan IP Kumulatif Mahasiswa Belum Terisi" << endl
                         << endl;
                    cout << "Tekan Apapun Untuk Kembali ke Menu Utama...";
                    return main();
                }
                for (i = 1; i <= recMhs[idUser - 1].getSemester(); i++)
                {
                    cout << "IP Semester " << i << ": " << recMhs[idUser - 1].getIPS(i) << endl;
                }
                for (i = 1; i <= recMhs[idUser - 1].getSemester(); i++)
                {
                    asal += recMhs[idUser - 1].getIPS(i);
                }
                ipk = asal / (i - 1);
                cout << endl
                     << "IP Kumulatif: " << ipk << endl
                     << endl;
                cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
                cin.ignore();
                cin.ignore();
            }
            break;
            case 3:
            {
            }
            break;
            default:
            {
                cls();
                cout << "Pilihan salah!" << endl;
                cout << "Tekan apapun untuk kembali ke menu Utama...";
            }
            }
        }
        break;
        case 6:
        {
            cls();
            while (recDosen.size() == 0)
            {
                cout << "Data Tidak Ditemukan!" << endl;
                cout << "Tekan Apapun Untuk kembali!" << endl;
                return main();
            }
            for (int i = 0; i < recDosen.size(); i++)
            {
                cout << "Nama: " << recDosen[idUser - 1].getNama() << "-- ( " << recDosen[i].getId() << " )" << endl;
            }
            cout << "Masukan ID Dosen: ";
            cin >> idUser;
            cls();
            for (int i = 0; i < recDosen.size(); i++)
            {
                cout << "---------------------------------- Data Dosen --------------------------------" << endl;
                cout << "Nama: " << recDosen[idUser - 1].getNama() << endl;
                cout << "Tanggal Lahir: " << recDosen[idUser - 1].getTglLahir() << "/" << recDosen[idUser - 1].getBulanLahir() << "/" << recDosen[idUser - 1].getTahunLahir() << endl;
                cout << "NRP: " << recDosen[idUser - 1].getNPP() << endl;
                cout << "Departemen: " << recDosen[idUser - 1].getDepartment() << endl;
                cout << "Pendidikan: " << recDosen[idUser - 1].getPendidikan() << endl;
            }
        }
        break;
        case 7:
        {
            cls();
            while (recTendik.size() == 0)
            {
                cout << "Belum ada data tendik" << endl
                     << endl;
                cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
                cin.ignore();
                cin.ignore();
                return main();
            }

            for (int i = 0; i < recTendik.size(); i++)
            {

                cout << "Nama: " << recTendik[idUser - 1].getNama() << "-- ( " << recTendik[i].getId() << " )" << endl;
            }
            cout << "Masukan ID Tendik: ";
            cin >> idUser;
            cls();
            while (idUser > recTendik.size())
            {
                cout << "ID Tendik Tidak Ditemukan" << endl;
                cout << "Tekan Apapun Untuk Kembali ke Menu Utama...";
                cin.ignore();
                cin.ignore();
                return main();
            }
            for (int i = 0; i < recTendik.size(); i++)
            {
                cout << "---------------------------------- Data Mahasiswa --------------------------------" << endl;
                cout << i + 1 << ". data tendik dengan id: " << recTendik[i].getId() << endl;
                cout << "\tNama        : " << recTendik[i].getNama() << endl;
                cout << "\tTanggal Lahir    : " << recTendik[i].getTglLahir() << "/" << recTendik[i].getBulanLahir() << "/" << recTendik[i].getTahunLahir() << endl;
                cout << "\tNPP         : " << recTendik[i].getNPP() << endl;
                cout << "\tUnit        : " << recTendik[i].getUnit() << endl
                     << endl;
            }
        }
        break;
        case 8:
        {
            while (recMatkul.size() == 0)
            {
                cout << "Belum ada data Mata Kuliah" << endl
                     << endl;
                cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
                cin.ignore();
                cin.ignore();
                return main();
            }
            for (int i = 0; i < recMatkul.size(); i++)
            {

                cout << "Nama: " << recMatkul[i].getNama() << " -- ( " << recMatkul[i].getId() << " )" << endl;
            }
            cout << "Masukan ID Matkul: ";
            cin >> idUser;
            cls();
            while (idMatkul > recMatkul.size())
            {
                cout << "ID Matkul Tidak Ditemukan" << endl;
                cout << "Tekan Apapun Untuk Kembali ke Menu Utama...";
                cin.ignore();
                cin.ignore();
                return main();
            }
            for (int i = 0; i < recMatkul.size(); i++)
            {
                cout << "---------------------------------- Data Mata Kuliah --------------------------------" << endl;
                cout << i + 1 << ".  Id: " << recMatkul[i].getId() << endl;
                cout << "\tNama        : " << recMatkul[i].getNama() << endl;
            }
        }
        break;
        case 9:
        {
            return main();
        }
        break;
        case 10:
        {
            cls();
            return 0;
        }
        }
    }
    while (menu == 2)
    {
        cout << "Masukkan ID Mahasiswa Anda: ";
        cin >> idS;
        while (idS == 0)
        {
            cout << "ID Mahasiswa Tidak Ditemukan" << endl
                 << endl;
            cout << "Tekan Apapaun Untuk Kembali ke Menu Utama...";
            cin.ignore();
            cin.ignore();
            return main();
        }
        while (idS > recMhs.size())
        {
            cls();
            cout << "Selamat datang di Institut Teknologi Suka Suka " << endl;
            cout << "-----------------------------------------------------------" << endl
                 << endl;
            cout << "DATA MAHASISWA" << endl;
            cout << "--------------" << endl;
            cout << "ID Mahasiswa: " << idS << endl;
            cout << "Nama: " << recMhs[idS - 1].getNama() << endl;
            cout << "Tanggal Lahir: " << recMhs[idS - 1].getTglLahir() << "/" << recMhs[idS - 1].getBulanLahir() << "/" << recMhs[idS - 1].getTahunLahir() << endl;
            cout << "NRP: " << recMhs[idS - 1].getNRP() << endl;
            cout << "Departemen: " << recMhs[idS - 1].getDepartment() << endl;
            cout << "Tahun Masuk: " << recMhs[idS - 1].getTahunMasuk() << endl;
            cout << "Semester: " << recMhs[idS - 1].getSemester() << endl;
            cout << "Jumlah SKS Lulus: " << recMhs[idS - 1].getSKSLulus() << endl
                 << endl;
            cout << "Menu: " << endl;
            cout << "  1. Cek IP Semester & IP Kumulatif" << endl;
            cout << "  2. Logout" << endl;
            cout << "  3. Keluar Program" << endl;
            cout << "-> Silahkan memilih salah satu: ";
            cin >> menu_terpilih;
            switch (menu_terpilih)
            {
            case 1:
            {
                cls();
                cout << "IP SEMESTER & KUMULATIF" << endl;
                cout << "-----------------------" << endl;
                if (recMhs[idS - 1].getIPS(1) == 0 && recMhs[idS - 1].getIPS(2) == 0)
                {
                    cout << "IP Semester dan IP Kumulatif Anda Belum Terisi" << endl
                         << endl;
                    cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
                    cin.ignore();
                    cin.ignore();
                    return main();
                }
                for (i = 1; i <= recMhs[idS - 1].getSemester(); i++)
                {
                    cout << "IP Semester " << i << ": " << recMhs[idS - 1].getIPS(i) << endl;
                }
                float ipk = 0, temp = 0;
                for (i = 1; i <= recMhs[idS - 1].getSemester(); i++)
                {
                    temp += recMhs[idS - 1].getIPS(i);
                }
                ipk = temp / (i - 1);
                cout << endl
                     << "IP Kumulatif: " << ipk << endl
                     << endl;
                cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
                cin.ignore();
                cin.ignore();
            }
            break;
            case 2:
            {
                return main();
            }
            break;
            case 3:
            {
                cls();
                return 0;
            }
            break;
            default:
            {
                cls();
                cout << "Pilihan tidak ditemukan" << endl
                     << endl
                     << "Tekan Enter Untuk Kembali ke Menu Utama";
                cin.ignore();
            }
            break;
            }
            cin.clear();
            cin.ignore();
        }
        return 0;
    }
}