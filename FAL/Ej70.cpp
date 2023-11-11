// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;
using tMatriz = vector<vector<int>>;

struct tDatos {
    int hab;
    int inv;
    int mala;
    tMatriz m;
    tDatos(int h, int i, int ma, tMatriz mat) :hab(h), inv(i), mala(ma), m(mat) {}
};

struct tSol {
    int satis = 0;
    vector<int> sol;
    vector<bool> marcas;
    int cont = 0;
    bool pos = false;
};

bool esValida(tSol& s,tDatos& d,int k,int i) {

    if (d.m[k][i] < 0)
        return false;
    int cont = 0;
    for (int j = 0; j <= k; j++) {
        if (s.sol[j] == j) {
            cont++;
        }
    }
    if (cont > s.sol.size() / 3)
        return false;
    return true;
}

bool esSolucion(tDatos& d, tSol& s) {
    int i = 0;
    bool fin = false;
    while (i < s.sol.size() && !fin) {
        if (s.sol[i] == d.mala)
            fin = true;
        i++;
    }
    return fin;
}

// funcioÌn que resuelve el problema
void resolver(tDatos& d,tSol& s,int k,int& mejorSol,vector<int>& est) {

    for (int i = 0; i < s.marcas.size(); i++) {
        s.sol[k] = i;
        if (!s.marcas[i]) {
            s.marcas[i] = true;
            s.satis += d.m[k][i];
            if (esValida(s,d,k,i)) {
                if (k == s.sol.size()-1) {
                    if (esSolucion(d,s)) {
                        if (s.satis == mejorSol) {
                            s.cont++;
                        }
                        else if (s.satis > mejorSol) {
                            mejorSol = s.satis;
                            s.cont = 1;
                        }
                        s.pos = true;
                    }
                }
                else {
                    if (s.satis + est[k+1] >= mejorSol)
                        resolver(d, s, k + 1, mejorSol,est);
                }
            }
            s.marcas[i] = false;
            s.satis -= d.m[k][i];
        }
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int hab;
    cin >> hab;
    if (hab == 0)
        return false;
    int inv;
    cin >> inv;
    int mala;
    cin >> mala;
    tMatriz matriz(inv, vector<int>(hab));
    for (vector<int> &v : matriz) {
        for (int& i : v) {
            cin >> i;
        }
    }
    tDatos d(hab, inv, mala, matriz);
    tSol s;
    s.sol.resize(inv);
    s.marcas.assign(hab, false);

    int mejorSol = INT_MIN;
    vector<int> est(inv);

    for (int i = 0; i < inv; i++) {
        int auxMax = d.m[i][0];
        for (int j = 1; j < hab; j++) {
            if (d.m[i][j] > auxMax)
                auxMax = d.m[i][j];
        }
        est[i] = auxMax;
    }

    for (int i = inv - 1; i > 0; i--) {
        est[i - 1] += est[i];
    }

    resolver(d, s, 0, mejorSol,est);

    if (!s.pos) {
        cout << "No" << endl;
    }
    else
        cout << mejorSol << " " << s.cont << endl;
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