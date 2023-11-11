#include <iostream>
using namespace std;

long long int mostrar() {
    long long int nombre1, nombre2;
    char letra;
    cin >> letra;
    if (letra == '+') {
        nombre1 = mostrar() + mostrar();
    }
    else if (letra == '-') {
        nombre1 = mostrar() - mostrar();
    }
    else if (letra == '*') {
        nombre1 = mostrar() * mostrar();
    }
    else if (letra == '/') {
        nombre1 = mostrar() / mostrar();
    }
    else {
        nombre1 = letra - '0';
    }
    return nombre1;
}

void casosDePrueba() {
    cout << mostrar() << "\n";
}

int main() {
    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; i++) {
        casosDePrueba();
    }
    return 0;
}