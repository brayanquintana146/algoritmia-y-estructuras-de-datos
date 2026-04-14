#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // debemos encontrar los valores del arreglo ar que,
    // al sumarlos den 15

    int n = 5;
    int ar[5] = {1,1,2,4,12};
    for (int i = 1; i <= pow(2,n); i++) {
        int ar_combin[5]={0};
        int suma = 0;
        for (int j = 0; j < 5; j++) {
            if (1&((i>>n-j-1))) { // devuelve 1 si el último dígito es 1
                suma += ar[j];
                ar_combin[j] = ar[j];
            }
        }
        // Mostrar combinaciones
        if (suma == 15) {
            for (int i = 0; i<n; i++) {
                if (ar_combin[i]!=0) cout<<ar_combin[i]<<' ';
            }
            cout<<endl;
        }
    }
}
