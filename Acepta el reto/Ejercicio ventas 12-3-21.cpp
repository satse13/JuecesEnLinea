#include <iostream>

using namespace std;

const int DIAS = 31;
const int SUCURSALES = 4;
const int MESES = 12;
typedef double tVentaMes[DIAS][SUCURSALES];

struct tMes{
	tVentaMes ventas;
	int dias = 0;
};

typedef tMes tVentaAnual[MESES];


const int MAX = 100;

struct tMatriz{
	int matriz[MAX][MAX];
	int dim;
};
 
bool operator* (tMatriz matrizA, tMatriz matrizB);

int main() {

	tVentaAnual anual;
	int total = 0;

	for (int i = 0; i < MESES; i++) {
		for (int j = 0; i < anual[i].dias; j++) {
			for (int k = 0; i < SUCURSALES; k++) {
				total = total + anual[i].ventas[j][k];
			}
		}
	}


	int umbral = 0;
	bool encontrado = false;
	int mes = 0, dia, suc;
	while ((mes < MESES) && !encontrado) {
		dia = 0;
		while ((dia < anual[mes].dias) && !encontrado) {
			suc = 0;
			while ((suc < SUCURSALES) && !encontrado)
			{

				if (anual[mes].ventas[dia][suc] > umbral)
					encontrado = true;
				else
					suc++;
			}
			if (!encontrado)
				dia++;
		}
		if (!encontrado)
			mes++;
	}
	 
	return 0;

}

bool operator* (tMatriz matrizA, tMatriz matrizB) {

	tMatriz matrizMultiplicacion;
	matrizMultiplicacion.dim = matrizA.dim;

	for (int fila = 0; fila < matrizMultiplicacion.dim; fila++) {
		for (int col = 0; col < matrizMultiplicacion.dim; col++) {

			for(int i )
			
		}

	}

}
