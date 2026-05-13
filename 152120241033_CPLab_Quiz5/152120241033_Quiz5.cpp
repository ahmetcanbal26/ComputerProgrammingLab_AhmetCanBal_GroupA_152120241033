#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Sensor {
    int sensor_id;
    float sicaklik;
};

int main() {
    long long no;

    cout << "Numara giriniz: ";
    cin >> no;

    int N = no % 50;
    int E = no % 100;

    Sensor s;
    float ilk_deger;

    fstream f("sensors.bin", ios::in | ios::out | ios::binary);

    if (!f) {
        return 1;
    }

    f.seekg(N * sizeof(Sensor), ios::beg);
    f.read((char*)&s, sizeof(Sensor));

    ilk_deger = s.sicaklik;
    s.sicaklik += E;

    f.seekp(N * sizeof(Sensor), ios::beg);
    f.write((char*)&s, sizeof(Sensor));
    f.close();

    string dosya_adi = to_string(no) + "_Quiz5.txt";
    ofstream rapor(dosya_adi);

    if (rapor.is_open()) {
        rapor << "Number: " << no << endl;
        rapor << "Sensor Index Used in the Process: [" << N << "]" << endl;
        rapor << "First Temperature: [" << ilk_deger << "] -> New Temperature: [" << s.sicaklik << "]" << endl;
        rapor.close();
    }

    return 0;
}
