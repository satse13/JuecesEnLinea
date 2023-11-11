
/* ¿Cuántas me llevo? */

#include <string>
#include <string.h>
#include <iostream>
using namespace std;

int main() {
    char numero1[1001], numero2[1001];
    int terminado, acarreo, count;
    int i;
    while (1) {
        cin >> numero1 >> numero2;
        if ((numero1[0] == '0' && numero2[0] == '0'))
            return 0;
        i = 0;
        count = 0;
        acarreo = 0;
        terminado = 0;
        while (!terminado) {
            acarreo = (i < strlen(numero1) ? numero1[strlen(numero1) - i - 1] - '0' : 0) + (i < strlen(numero2) ? numero2[strlen(numero2) - i - 1] - '0' : 0) + acarreo;
            if (acarreo > 9) {
                count++;
                acarreo = 1;
            }
            else {
                acarreo = 0;
            }
            i++;
            if (!acarreo && (i > strlen(numero1) - 1 || i > strlen(numero2) - 1))
                terminado = 1;
        }
        cout << count << endl;
    }
}