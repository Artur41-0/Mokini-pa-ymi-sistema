#include <iostream>
#include <string>

using namespace std;

// Konstantos maksimalioms riboms
const int MAX_M = 100; 
const int MAX_P = 10;

int main() {
    // Kintamųjų deklaravimas
    string vardai[MAX_M];
    int p[MAX_M][MAX_P];
    int pKiekis[MAX_M] = {0};
    int mSkaicius = 0;
    
    int pasirinkimas;

    // Pagrindinis programos ciklas
    do {
        cout << "\n--- MOKINIU SISTEMA ---\n";
        cout << "1. Prideti mokini\n";
        cout << "2. Rodyti sarasa\n";
        cout << "3. Atnaujinti pazymi\n";
        cout << "4. Trinti mokini\n";
        cout << "5. Iseiti\n";
        cout << "Pasirinkite veiksma: ";
        cin >> pasirinkimas;
        } while (pasirinkimas != 5);

    return 0;
}