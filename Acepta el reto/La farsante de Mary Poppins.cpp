#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void casosDePrueba() {
    string palabra;
    cin >> palabra;
    if (palabra[0] == toupper(palabra[0])) {
        palabra[0] = tolower(palabra[0]);
        palabra[palabra.length() - 1] = toupper(palabra[palabra.length() - 1]);
    }
    reverse(palabra.begin(), palabra.end());
    cout << palabra << "\n";
}

//--------------------------------------------------------------------------

int main()
{
    unsigned int numCasos, i;
    cin >> numCasos;
    for (int i = 0; i < numCasos; i++) {
        casosDePrueba();
    }
    return 0;
}