// Nombre del alumno ..... Daniela Vidal Leon y Alejandro Tobias Angeles
// Usuario del Juez ......  PC02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <math.h>
using namespace std;

int n, m, s, v;
vector<int> match, vis;
vector<vector<int>> grafo;
unordered_map<int, pair<float, float>> mapaN;
unordered_map<int, pair<float, float>> mapaA;


int aug(int l) {
    if (vis[l]) return 0;
    vis[l] = 1;
    for (auto r : grafo[l]) 
        if (match[r] == -1 || aug(match[r])) {
            match[r] = l;
            return 1;
        }
    return 0;
}

int berge_mcbm() {
    int mcbm = 0;
    match.assign(n+m, -1);
    for(int l = 0; l < n; l++){
        vis.assign(n, 0);
        mcbm += aug(l);
    }
    return mcbm;
}


 float dist(int g, int h) {

    return  sqrt(((mapaN[g].first - mapaA[h].first) * (mapaN[g].first - mapaA[h].first)) + ((mapaN[g].second - mapaA[h].second) * (mapaN[g].second - mapaA[h].second)));

}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    cin >> n;

    if (!std::cin)
        return false;
    cin >> m >> s >> v;

    grafo.clear();
    grafo.resize(n);

    float x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        mapaN[i] = { x,y };
    }

    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        mapaA[i] = { x,y };
        for (int j = 0; j < n; j++) {
            if(s >= (dist(j,i) / (float)v))
                grafo[j].push_back(i);
        }
    }

    cout << n - berge_mcbm() << endl;

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