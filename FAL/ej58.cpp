// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A64


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


const string colores[3] = {"azul ","rojo ","verde "};

struct tP {
    int piezas[3];
};

// RESTRICCIONES 
    // la torre empieza por rojo
    // no puede haber mas verdes que azules mientras construye la torre
    // tiene que haber mas rojos que azules y verdes al final 
    // no puede haber dos verdes seguidas

// funcioÌn que resuelve el problema

bool esValida(vector<string>&sol,tP p,int k,int i, const vector<int>& marcas) {
    // No puede haber dos verdes seguidas
    if (sol[k] == sol[k - 1] && sol[k] == colores[2])return false;
    // Tengo que tener suficientes piezas del color que toque
    if (marcas[i] > p.piezas[i]) return false;
    // Tiene que haber mas azules que verdes
    if (marcas[2] > marcas[0])return false;
    else
        return true;
}

bool esSolucion(const vector<int>& marcas) {
    if (marcas[1] <= marcas[0] + marcas[2]) return false;
    else return true;
}

void escribe(const vector<string>& sol) {
    for (string s : sol)
        cout << s;
    cout << endl;
}


void resolver(int k,vector<string>& sol,tP p,vector<int>& marcas,int &contador) {
    int solucion = 0;

    for (int i = 0; i < 3; i++) {
        sol[k] = colores[i];
        ++marcas[i];
        if (esValida(sol, p, k, i, marcas)) {
            if (k == sol.size() - 1) {
                if (esSolucion(marcas)) {
                    escribe(sol);
                    contador++;
                }
            }
            else {
                resolver(k + 1, sol, p, marcas, contador);
            }
        }
        --marcas[i];
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    
    int altura, azules, rojos, verdes;
    cin >> altura;

    tP p;

    for (int i = 0; i < 3; i++) {
        cin >> p.piezas[i];
    }

    if (altura == 0 && p.piezas[0] == 0 && p.piezas[1] == 0 && p.piezas[2] == 0)
        return false;

    vector<string>sol(altura);
    vector<int>marcas(3);
   

    sol[0] = colores[1];
    ++marcas[1];


    int contador = 0;

    resolver(1, sol, p, marcas,contador);

    if(contador == 0)
        cout << "SIN SOLUCION" << endl;
   
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