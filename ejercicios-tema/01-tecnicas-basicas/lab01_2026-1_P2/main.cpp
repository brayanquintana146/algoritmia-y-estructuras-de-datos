#include <iostream>
#include <cmath>

using namespace std;

struct Diente {
    int id;
    int tiempo;
    int ganancia;
};



int main() {
    int tipo_de_dientes[8] = {1,1,2,3,3,4,4,4};
    int caries_de_dientes[8] = {3,1,0,1,2,1,2,3};
    //     1, 2,  3, 4
    int tiempo_por_caries[5] = {0, 5, 7, 10, 12}; // indice nunca será 0
    int ganancia_por_caries[5] = {0, 20, 30, 35, 42}; // indice nunca será 0

    // arreglo de dientes
    Diente dientes[8];
    int mejor_ganancia=0;
    int mejor_combinacion[8]{};

    // llenamos el arreglo de dientes
    for (int i = 0; i < 8; i++) {
        int tipo = tipo_de_dientes[i]; // 1
        int cantCaries = caries_de_dientes[i]; // 3

        dientes[i].id = i+1; // Para que dientes empiece en 1
        dientes[i].tiempo = cantCaries*tiempo_por_caries[tipo];
        dientes[i].ganancia = cantCaries*ganancia_por_caries[tipo];
    }

    int combinaciones = pow(4, 8);
    for (int comb = 0; comb < combinaciones; comb++) {
        int comb_actual[8];
        int copia_comb = comb;
        int tiempo_c1 = 0, tiempo_c2 = 0, tiempo_c3 = 0;
        int ganancia_combinacion=0;
        bool comb_valida = true;

        for (int j = 0; j < 8; j++) {
            comb_actual[j] = copia_comb%4; // valores de 0,1,2,3,4
            copia_comb /= 4;

            // si el valor es 3, no haremos nada
            if (comb_actual[j]==3) continue;

            if (comb_actual[j] == 0) {
                tiempo_c1 += dientes[j].tiempo;
            }
            else if (comb_actual[j] == 1) {
                tiempo_c2 += dientes[j].tiempo;
            }
            else if (comb_actual[j] == 2) {
                tiempo_c3 += dientes[j].tiempo;
            }
            ganancia_combinacion += dientes[j].ganancia;
        }
        // si se supera el límite del tiempo, se descarta la combinacion
        if (tiempo_c1 > 60 || tiempo_c2 > 45 || tiempo_c3 > 50) continue;

        // llegaremos a esta línea en caso de que el tiempo esté bien
        // buscamos la mejor ganancia
        if (ganancia_combinacion > mejor_ganancia) {
            mejor_ganancia=ganancia_combinacion;
            // copiamos la combinacion a mejor combinacion
            for (int j = 0; j < 8; j++) {
                mejor_combinacion[j] = comb_actual[j];
            }
        }
    }

    // imprimir la mejor solucion
    for (int i = 0; i < 3; i++) {
        cout<<"Cita "<<i+1<<": ";
        for (int j = 0; j < 8; j++) {
            if (mejor_combinacion[j] == i) {
                cout<<dientes[j].id<<' ';
            }
        }
        cout<<endl;
    }
    cout<<"Mejor ganancia: "<<mejor_ganancia<<endl;
    return 0;
}