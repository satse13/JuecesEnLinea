//---------------------------------------------------------
// Problema 579 Felipe y sus tareas
//
// https://www.aceptaelreto.com
//
// Alejandro Tobias Angeles
//---------------------------------------------------------

#include <iostream>
using namespace std;

struct tTarea {
	int duracion, prioridad;
};
struct tTareas {
	tTarea tarea[100];
};
 	
bool casoDePrueba() {

	int numTareas;
	
	cin >> numTareas;

	//leer caso de prueba

		if ( numTareas == 0)
			return false;
		else {
			 
			tTareas tareas;

			for (int i = 0; i < numTareas; i++) {
				cin >> tareas.tarea[i].prioridad >> tareas.tarea[i].duracion;
			}

			tTarea tmp;

 			for (int i = 0; i < numTareas - 1; i++) {
 				for (int j = numTareas - 1; j > i; j--) {
					
					if (tareas.tarea[j].prioridad > tareas.tarea[j - 1].prioridad) {
						tmp = tareas.tarea[j] ;
						tareas.tarea[j] = tareas.tarea[j - 1];
						tareas.tarea[j - 1]  = tmp;
					}
					else if (tareas.tarea[j].prioridad == tareas.tarea[j - 1].prioridad) {
						
						if (tareas.tarea[j].duracion < tareas.tarea[j - 1].duracion) {
							tmp = tareas.tarea[j];
							tareas.tarea[j] = tareas.tarea[j - 1];
							tareas.tarea[j - 1] = tmp;
						}
					}
				}

				
			}

			for (int i = 0; i < numTareas; i++) {
				cout << tareas.tarea[i].prioridad << " " << tareas.tarea[i].duracion << endl;
			}
			cout << "---" << endl;

			return true;
		} // if-else marca de fin

} // casoDePrueba

//---------------------------------------------------------




int main() {

	while (casoDePrueba()) {
	}

	return 0;

} // main