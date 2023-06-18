#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <chrono>
using namespace std;
int main()
{
    string matkul;
    cout << "KELAS 1B TMJ (POLYMESA)" << endl;
    int anggotaPerKelompok;
    vector<string> tmj = {
        "Ahmad Jilan Shadiq", "Ahmadan Fatrah Rusnan", "Arni Noviani",
        "Faya Kasenda", "Fuad Ali Rahman", "M. Arfi Ayuzar Dg. Romo", "Moch. Fajar Anugrah Amirwan", "Rahmat Hidayat",
        "Syahnur Haq", "Andi Afdhal Hilmi", "Faiz Huzaini Maulana M", "Hafidz Mufly", "Jeanne Angraini Sirupa", "Muhammad Faiz Fajar M.",
        "Muhammad Rifai Rahim", "Rezki Andika", "Juliana Sari", "Muhammad Fadhel", "Nur Aqilah Hirman", "Rina", "St. Nurhalisa",
        "Abid Muzhaffar Tadjuddin", "Firdania Sasmita Sari", "Muh. Afdhol Ridho", "Rizaldy Junaedy", "Syamryan Suci Hastiwi"};
    cout << "Nama Mata Kuliah : ";
    getline(cin, matkul);
    cout << "Berapa anggota tiap kelompok ? : ";
    cin >> anggotaPerKelompok;
    int totaltmj = tmj.size();
    int kelompok = totaltmj / anggotaPerKelompok;
    int tmjTersisa = totaltmj % anggotaPerKelompok;
    cout << "Anggota tersisa : " << tmjTersisa << endl;
    cout << "NOTE : Anggota yang tersisa akan dilempar masuk ke kelompok lain" << endl;
    cout << endl;
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 gen(seed);
    shuffle(tmj.begin(), tmj.end(), gen);

    vector<vector<string>> kelompoktmj(kelompok);

    int index = 0;
    for (int i = 0; i < kelompok; ++i)
    {
        for (int j = 0; j < anggotaPerKelompok; ++j)
        {
            kelompoktmj[i].push_back(tmj[index]);
            index++;
        }
    }

    vector<int> kelompoksisa(kelompok);
    for (int i = 0; i < kelompok; ++i)
    {
        kelompoksisa[i] = i;
    }

    shuffle(kelompoksisa.begin(), kelompoksisa.end(), gen);

    if (tmjTersisa > 0)
    {
        for (int i = 0; i < tmjTersisa; ++i)
        {
            kelompoktmj[kelompoksisa[i]].push_back(tmj[index]);
            index++;
        }
    }

    for (int i = 0; i < kelompok; ++i)
    {
        cout << "Kelompok " << i + 1 << ":" << endl;
        for (int j = 0; j < kelompoktmj[i].size(); j++)
        {
            const string &nama = kelompoktmj[i][j];
            cout << j + 1 << ". " << nama << endl;
        }
        cout << endl;
    }

    return 0;
}
