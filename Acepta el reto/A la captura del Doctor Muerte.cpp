#include <iostream>
 using namespace std;

const int N = 1000;

struct tArma {
    int inocentes;
    int villano;
    int posArma = 0;
};

struct tArmamento {
    tArma arma[N];
    int nArmas;
};

bool casoDePrueba() {
    tArmamento armamento;
    int vitalidad;
    cin >> vitalidad >> armamento.nArmas;
    if (vitalidad == 0)
        return false;
    else {

        for (int i = 0; i < armamento.nArmas; i++) {
            cin >> armamento.arma[i].inocentes >> armamento.arma[i].villano;
            armamento.arma[i].posArma = i + 1;
        }

        bool fin = true;
        int i = 0;
        while ((i < armamento.nArmas - 1) && fin) {
            fin = false;
            for (int j = armamento.nArmas - 1; j > i; j--) {
                if (armamento.arma[j].inocentes < armamento.arma[j - 1].inocentes || (armamento.arma[j].inocentes == armamento.arma[j - 1].inocentes && armamento.arma[j].villano > armamento.arma[j - 1].villano)) {
                    tArma aux;
                    aux = armamento.arma[j];
                    armamento.arma[j] = armamento.arma[j - 1];
                    armamento.arma[j - 1] = aux;
                    fin = true;
                }
            }
            if (fin) {
                i++;
            }
        }

        int total = 0;
        int k = 0;

        while (total < vitalidad && k < armamento.nArmas) {
            total = total + armamento.arma[k].villano;
            k++;
        }

        if (total < vitalidad) {
            cout << "MUERTE ESCAPA" << endl;
        }
        else {
            for (int j = 0; j < k - 1; j++) {
                cout << armamento.arma[j].posArma << " ";
            }
            cout << armamento.arma[k - 1].posArma << endl;
        }

        return true;
    }
}

int main() {
    while (casoDePrueba());
    return 0;
}