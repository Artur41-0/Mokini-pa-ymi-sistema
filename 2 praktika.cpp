#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
// Konstantos nustato maksimalius masyvų dydžius
const int MAX_M = 100; // Maksimalus mokinių skaičius
const int MAX_P = 10;  // Maksimalus pažymių skaičius vienam mokiniui
int main() {
    // Masyvai duomenims saugoti
    string vardai[MAX_M];    // Mokinių vardai
    int p[MAX_M][MAX_P];     // Pažymiai (dvimatis masyvas)
    int pKiekis[MAX_M] = {0};// Kiekvieno mokinio turimų pažymių kiekis
    int mSkaicius = 0;       // Dabartinis mokinių skaičius sąraše
    int pasirinkimas;
    // Pagrindinis ciklas, veikiantis kol nepasirinkta "5"
    do {
        cout << "\n--- MOKINIU SISTEMA ---\n";
        cout << "1. Prideti mokini ir pazymius\n";
        cout << "2. Rodyti visus duomenis\n";
        cout << "3. Atnaujinti pazymi\n";
        cout << "4. Trinti mokini\n";
        cout << "5. Iseiti\n";
        cout << "Pasirinkimas: ";
        cin >> pasirinkimas;
        // Naujo mokinio pridėjimas
        if (pasirinkimas == 1) {
            if (mSkaicius < MAX_M) {
                cout << "Vardas: ";
                cin >> vardai[mSkaicius];
                
                int k;
                cout << "Kiek pazymiu (max " << MAX_P << ")? ";
                cin >> k;
                // Patikriname, kad neviršytų nustatyto limito
                if (k > MAX_P) k = MAX_P;
                
                pKiekis[mSkaicius] = k;
                for (int j = 0; j < k; j++) {
                    cout << " " << j + 1 << "-as pazimys: ";
                    cin >> p[mSkaicius][j];
                }
                mSkaicius++; // Padidiname bendrą mokinių kiekį
            } else {
                cout << "Sarasas pilnas!\n";}} 
        // Visų duomenų rodymas
        else if (pasirinkimas == 2) {
            cout << "\nSarasas:\n";
            for (int i = 0; i < mSkaicius; i++) {
                // setw(10) sulygiuoja vardus, kad sąrašas būtų tvarkingas
                cout << i + 1 << ". " << setw(10) << left << vardai[i] << " | ";
                for (int j = 0; j < pKiekis[i]; j++) {
                    cout << p[i][j] << " ";
                }
                cout << endl;}
        } 
        // Konkretaus pažymio atnaujinimas
        else if (pasirinkimas == 3) {
            int mIdx, pIdx;
            cout << "Mokinio numeris: ";
            cin >> mIdx;
            mIdx--; // Masyvo indeksas prasideda nuo 0, todėl atimame 
            if (mIdx >= 0 && mIdx < mSkaicius) {
                cout << "Kuri pazymi keisti (1-" << pKiekis[mIdx] << ")? ";
                cin >> pIdx;
                pIdx--;
                if (pIdx >= 0 && pIdx < pKiekis[mIdx]) {
                    cout << "Naujas pazymys: ";
                    cin >> p[mIdx][pIdx];
                    cout << "Pakeista.\n";}
            }} 
        // Mokynio pašalinimas iš sarašo
        else if (pasirinkimas == 4) {
            int mIdx;
            cout << "Kuri mokini trinti (numeris)? ";
            cin >> mIdx;
            mIdx--;

            if (mIdx >= 0 && mIdx < mSkaicius) {
                // Visi po ištrinto mokinio einantys mokiniai perkeliami viena vieta atgal
                for (int i = mIdx; i < mSkaicius - 1; i++) {
                    vardai[i] = vardai[i + 1];
                    pKiekis[i] = pKiekis[i + 1];
                    for (int j = 0; j < MAX_P; j++) {
                        p[i][j] = p[i + 1][j];
                    }
                }
                mSkaicius--; // Sumažiname bendrą mokinių skaičių
                cout << "Istrinta.\n";
            }
        }

    } while (pasirinkimas != 5);

    return 0;
}
