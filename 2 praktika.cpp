#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
const int MAX_M = 100;
const int MAX_P = 10;
int main() {
    string vardai[MAX_M];
    int p[MAX_M][MAX_P];
    int pKiekis[MAX_M] = {0};
    int mSkaicius = 0;
    int pasirinkimas;

    do {
        cout << "\n--- MOKINIU SISTEMA ---\n";
        cout << "1. Prideti mokini ir pazymius\n";
        cout << "2. Rodyti visus duomenis\n";
        cout << "3. Atnaujinti pazymi\n";
        cout << "4. Trinti mokini\n";
        cout << "5. Iseiti\n";
        cout << "Pasirinkimas: ";
        cin >> pasirinkimas;
        if (pasirinkimas == 1) {
            if (mSkaicius < MAX_M) {
                cout << "Vardas: ";
                cin >> vardai[mSkaicius];
                
                int k;
                cout << "Kiek pazymiu (max " << MAX_P << ")? ";
                cin >> k;
                
                if (k > MAX_P) k = MAX_P;
                
                pKiekis[mSkaicius] = k;
                for (int j = 0; j < k; j++) {
                    cout << " " << j + 1 << "-as pazimys: ";
                    cin >> p[mSkaicius][j];}
                mSkaicius++;
            } else {
                cout << "Sarasas pilnas!\n";}} 
        else if (pasirinkimas == 2) {
            cout << "\nSarasas:\n";
            for (int i = 0; i < mSkaicius; i++) {
                cout << i + 1 << ". " << setw(10) << left << vardai[i] << " | ";
                for (int j = 0; j < pKiekis[i]; j++) {
                    cout << p[i][j] << " ";
                }
                cout << endl;
            }} 
        else if (pasirinkimas == 3) {
            int mIdx, pIdx;
            cout << "Mokinio numeris: ";
            cin >> mIdx;
            mIdx--;

            if (mIdx >= 0 && mIdx < mSkaicius) {
                cout << "Kuri pazymi keisti (1-" << pKiekis[mIdx] << ")? ";
                cin >> pIdx;
                pIdx--;

                if (pIdx >= 0 && pIdx < pKiekis[mIdx]) {
                    cout << "Naujas pazymys: ";
                    cin >> p[mIdx][pIdx];
                    cout << "Pakeista.\n";}}
        } 
        else if (pasirinkimas == 4) {
            int mIdx;
            cout << "Kuri mokini trinti (numeris)? ";
            cin >> mIdx;
            mIdx--;

            if (mIdx >= 0 && mIdx < mSkaicius) {
                for (int i = mIdx; i < mSkaicius - 1; i++) {
                    vardai[i] = vardai[i + 1];
                    pKiekis[i] = pKiekis[i + 1];
                    for (int j = 0; j < MAX_P; j++) {
                        p[i][j] = p[i + 1][j];}}
                mSkaicius--;
                cout << "Istrinta.\n";}
        }

    } while (pasirinkimas != 5);

    return 0;
}
