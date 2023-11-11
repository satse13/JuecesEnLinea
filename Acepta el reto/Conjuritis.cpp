#include <iostream>
using namespace std;

bool casoDePrueba() {
    int nHechizos, dano[200000];
    long long int total, maximo = 0, diferencia;
    cin >> nHechizos;

    if (nHechizos == 0)
        return false;
    else {

        for (int i = 0; i < nHechizos; i++) {
            cin >> dano[i];
            maximo = maximo + dano[i];
        }
        cin >> total;

        diferencia = maximo - total;
        bool encontrado = false;
        int i = 0;
        int j = nHechizos - 1;

        while (!encontrado) {
            if ((dano[i] + dano[j]) == diferencia) {
                cout << dano[i] << " " << dano[j] << "\n";
                encontrado = true;
            }
            else if ((dano[i] + dano[j]) > diferencia) {
                j--;
            }
            else {
                i++;
            }
        }
        return true;
    }
}

int main() {
    while (casoDePrueba());
    return 0;
}
