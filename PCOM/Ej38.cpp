// Nombre del alumno ..... Daniela Vidal y Alejandro Tobias
// Usuario del Juez ...... PC02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    string s;
    cin >> s;

    if (!std::cin)
        return false;

    float ceroUno = 0;
    float ceroCero = 0;
    float cero = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            cero++;
            if (s[(i + 1) % s.size()] == '0')
                ceroCero++;
            else
                ceroUno++;
        }
    }   

    float shoot = (ceroCero) / (ceroCero + ceroUno);
    float rotate = cero / s.size();
    if (shoot > rotate)
        cout << "SHOOT";
    else if (shoot == rotate)
        cout << "EQUAL";
    else
        cout << "ROTATE";

    cout << endl;

    // escribir sol


    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}