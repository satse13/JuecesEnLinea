#include <iostream>
using namespace std;

int recursion(int& l1, int& l2) {
    int mayor, menor, operacion, resto;
    if (l1 < 10 || l2 < 10) {
        return 0;
    }
    else {
        mayor = max(l1, l2);
        menor = min(l1, l2);
        operacion = mayor / menor;
        mayor -= operacion * menor;
        resto = operacion + recursion(mayor, menor);
        return resto;
    }
}

bool casoDePrueba() {
    int ancho, largo, contador = 0;
    cin >> ancho >> largo;
    if (ancho == 0 && largo == 0)
        return false;
    else {
        contador = recursion(ancho, largo);
        cout << contador << "\n";
        return true;
    }
}

int main() {
    while (casoDePrueba());
    return 0;
}