// Nombre del alumno ..... Daniela Vidal León y Alejandro Tobías Ángeles
// Usuario del Juez ...... PC02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cstring>
#include <climits>
#include <queue>
using namespace std;
using ii = pair<int, int>;

int dist[201][201];
int suma;
int a, b, c, d;
pair<int, ii> solMejor;

/*
* 
* c-> a
* c -> b
* a -> c 
* b -> c 
* a -> b 
* b -> a
* 
*/


pair<int,ii> next(const ii& act,int& i) {
    switch (i) {
    case 0:  // c -> a
        if (act.first + suma - act.first - act.second >= a)
            return { a - act.first,{a,act.second }};
        else
            return {suma - act.first - act.second ,{act.first + suma - act.first - act.second, act.second } };
    case 1: // c -> b
        if (act.second + suma - act.first - act.second >= b)
            return {b- act.second ,{act.first,b}};
        else
            return { suma - act.first - act.second , {act.first, act.second + suma - act.first - act.second } };
    case 2: // a -> c
        if (act.first + suma - act.first - act.second >= c)
            return {c - (suma - act.first - act.second) ,{act.first - (c - (suma - act.first - act.second)),act.second}};
        else
            return {act.first ,{0, act.second } };
    
    case 3: // b->c
        if (act.second + suma - act.first - act.second >= c)
            return { c - (suma - act.first - act.second ) ,{act.first,act.second - (c - (suma - act.first - act.second ))} };
        else
            return { act.second ,{act.first,0} };

    case 4: // a -> b
        if (act.first + act.second >= b)
            return { b - act.second ,{act.first - b + act.second, b}};
        else
            return {act.first ,{0, act.first + act.second} };

    case 5: // b -> a
        if (act.first + act.second >= a)
            return {a - act.first ,{ a, act.second - a + act.first } };
        else
            return {act.second,{act.first + act.second , 0} };
    }   
}

bool mejor(const pair<int, ii>& solActual, const pair<int, ii>& solMejor, const int& litros) {

        int difA, difB, difC;
        difA = solMejor.second.first <= d? d - solMejor.second.first : INT_MAX;
        difB = solMejor.second.second <= d ? d - solMejor.second.second : INT_MAX;
        difC = suma - solMejor.second.first - solMejor.second.second <= d ? d - (suma - solMejor.second.first - solMejor.second.second) : INT_MAX;

        int difaA, difaB, difaC;
        difaA= solActual.second.first <= d ? d - solActual.second.first : INT_MAX;
        difaB = solActual.second.second <= d ? d - solActual.second.second : INT_MAX;
        difaC = suma - solActual.second.first - solActual.second.second <= d ? d - (suma - solActual.second.first - solActual.second.second) : INT_MAX;

        int minM = min(difC, min(difA, difB));
        int minA = min(difaC, min(difaA, difaB));

        if (minA < minM)
            return true;

        else if (minA == minM) {
            if (litros < solMejor.first)
                return true;
        }
        return false;
}

// funcioÌn que resuelve el problema
void dijkstra(ii s,const int& d) {
  
    solMejor = { 0,s };
    dist[s.first][s.second] = 0;
    priority_queue<pair<int,ii>, vector<pair<int, ii>>, greater<pair<int, ii>>> pq;
    pq.push({ 0, s });
    while (!pq.empty()) {
        pair<int, ii> front = pq.top(); pq.pop();
        int k = front.first;
        ii u = front.second;
        if (k > dist[u.first][u.second]) continue;
        for (int i = 0; i < 6;i++) { 
            pair<int, ii> w = next(u, i);
            if (w.second.first <= a && w.second.second <= b && suma - w.second.first - w.second.second <= c && w.second.first >= 0 && w.second.second >= 0 && suma - w.second.first - w.second.second >= 0) {  
                if (mejor(w,solMejor,w.first+k)) {
                    solMejor = { w.first + k, w.second };
                }
                if (dist[u.first][u.second] + w.first < dist[w.second.first][w.second.second]) {
                    dist[w.second.first][w.second.second] = dist[u.first][u.second] + w.first;
                    pq.push({ dist[w.second.first][w.second.second], w.second });
                }
            }
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada


    cin >> a >> b >> c >> d;
    suma = c;
    memset(dist, 1000000, c*sizeof(dist[0]));
    dijkstra({ 0,0 }, d);
    int difA, difB, difC;

    difA = solMejor.second.first <= d ? d - solMejor.second.first : INT_MAX;
    difB = solMejor.second.second <= d ? d - solMejor.second.second : INT_MAX;
    difC = suma - solMejor.second.first - solMejor.second.second <= d ? d - (suma - solMejor.second.first - solMejor.second.second) : INT_MAX;

    int minM;
    if (difA < difB && difA < difC) {
        minM = solMejor.second.first;
    }
    else if (difB < difA && difB < difC) {
        minM = solMejor.second.second;
    }
    else
        minM = suma - solMejor.second.first - solMejor.second.second;

    if (minM > d)
        minM = 0;
    cout << solMejor.first << " " << minM << endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}