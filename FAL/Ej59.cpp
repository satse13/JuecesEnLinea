// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

bool esValida(vector<int>&sol,int k,vector<int>& puesto,vector<int>& lluvias,vector<int>& sopor) {

    // Comprobar que no repito abrigo 
    // Comprobar que no me pongo uno mucho
    
    if (k > 0 && sol[k - 1] == sol[k])
        return false;
    else if (puesto[sol[k]] > k / 3 + 2)
        return false;
    else if (lluvias[k] > sopor[sol[k]])
        return false;
    return true;


}


bool esSolucion(vector<int>& sol) {
    if (sol[sol.size() - 1] == sol[0])
        return false;
    return true;
}

// funcioÌn que resuelve el problema
int resolver(vector<int>& sol,vector<int>& lluvias, vector<int>& sopor, vector<int>& puesto,int k) {
    int solu = 0;
    for (int i = 0; i < sopor.size(); i++) {
        sol[k] = i;
        puesto[i]++;
        if (esValida(sol,k,puesto,lluvias,sopor)) {
            if (k == lluvias.size() - 1) {
                if (esSolucion(sol)) {
                    solu++;
                }
            }
            else {
               solu += resolver(sol, lluvias, sopor, puesto, k + 1);
            }
        }
        puesto[i]--;
    }
    return solu;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int dias, abr;
    cin >> dias >> abr;
    if (dias == 0 && abr == 0)
        return false;

    vector<int> lluvias(dias);
    vector<int> sopor(abr);
    vector<int> puesto(abr);
    vector<int> sol(dias);

    for (int& i : lluvias) cin >> i;
    for (int& i : sopor) cin >> i;
    int comb = 0;
   int s =  resolver(sol,lluvias,sopor,puesto,0);
    if (!s)
        cout << "Lo puedes comprar" << endl;
    else
        cout << s << endl;

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