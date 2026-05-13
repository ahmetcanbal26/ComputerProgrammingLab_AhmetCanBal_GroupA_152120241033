#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Sensor {
    int sensor_id;
    float sicaklik;
};

int main() {
    long long studentID = 152120241033;
    int N = studentID % 50;
    int E = studentID % 100;

    Sensor s;
    float eskiSicaklik;

    fstream dosya("sensors.bin", ios::in | ios::out | ios::binary);

    if (!dosya) {
        return 1;
    }

    dosya.seekg(N * sizeof(Sensor), ios::beg);
    dosya.read((char*)&s, sizeof(Sensor));

    eskiSicaklik = s.sicaklik;
    s.sicaklik += E;

    dosya.seekp(N * sizeof(Sensor), ios::beg);
    dosya.write((char*)&s, sizeof(Sensor));
    dosya.close();

    string raporAdi = to_string(studentID) + "_Quiz5.txt";
    ofstream rapor(raporAdi);

    if (rapor.is_open()) {
        rapor << "Number: " << studentID << endl;
        rapor << "Sensor Index Used in the Process: [" << N << "]" << endl;
        rapor << "First Temperature: [" << eskiSicaklik << "] -> New Temperature: [" << s.sicaklik << "]" << endl;
        rapor.close();
    }

    return 0;
}
