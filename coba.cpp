#include <iostream>
using namespace std;

class mahasiswa{
    // Syarat enkapsulasi
    // 1. data harus private
    protected:
    string nama;
    string nim;

    private:
    string umur;

    public:
    mahasiswa(string pNama, string pNim, string pUmur):
    nama(pNama), nim(pNim), umur(pUmur){
    }

    //menandakan bahwa ini abstrak class dan sebagai syarat untuk polymorphy 
    virtual void infoMhs() = 0;

    //Abstraksi hanya dapat mengakses melalui method
    void setNama(string pNama){
        nama = pNama;
    }
    string getNama(){
        return nama;
    }
    void setUmur(string pUmur){
        umur = pUmur;
    }
    string getUmur(){
        return umur;
    }
};

class mhsBaru : public mahasiswa{
    public:
    mhsBaru(string pNama, string pNim, string pUmur):
    mahasiswa(pNama, pNim, pUmur){}

    void infoMhs() override{
        cout << "Nama Mhs: " << nama << endl;
        cout << "Nim Mhs: " << nim << endl;//abstraksi
        cout << "Umur Mhs: " << getUmur << endl;//encapsulation

    }
};

class mhsLama : public mahasiswa{
    public:
    mhsLama(string pNama, string pNim, string pUmur):
    mahasiswa(pNama, pNim, pUmur){}

    void infoMhs() override{
        cout << "Nama Mhs: " << nama << endl;
        cout << "Nim Mhs: " << nim << endl;//abstraksi
        cout << "Umur Mhs: " << getUmur << endl;//encapsulation

    }
};

int main(){
    mahasiswa *mhs;
    mhsBaru mhsb("Joko", "2023", "45");
    mhsLama mhsl("Jarwo", "2021", "35");

    mhs = &mhsb;
    mhs->infoMhs();
    mhs = &mhsl;
    mhs->infoMhs();
}