#include <iostream>
#include <cmath>

using namespace std;

const int TOTAL_TABLES = 6;
const int TOTAL_DISKS = 3;

// RESOLUCION DEL PRIMER PROBLEMA DEL LAB01 DEL 2025-1

void copy(const int num_entries, int destination[], const int source[]) {
    for (int i = 0; i < num_entries; i++) {
        destination[i] = source[i];
    }
}

void solve(const int tables[TOTAL_TABLES], const int disks[TOTAL_DISKS]){
    // usaremos estas variable para determinar la solucion mas optima
    int vel_max = -1;
    int best_solution[TOTAL_TABLES];
    int disco_max;

    // Crear todas las posibilidades para los 8 dicos: 102012
    for(int posibility = 0; posibility < pow(TOTAL_DISKS, TOTAL_TABLES); posibility++) {
        int posibilty_copy = posibility;
        int combination[TOTAL_TABLES];
        int performance[TOTAL_DISKS]={};
        bool es_valid = true;

        // copiamos los valores de disks[] a performance[]
        copy(TOTAL_DISKS, performance, disks);
        for (int table = 0; table < TOTAL_TABLES; table++) {
            int cur_disk = posibilty_copy % TOTAL_DISKS; // 0, 1 o 2
            combination[table] = cur_disk;
            posibilty_copy = posibilty_copy/TOTAL_DISKS;

            // guardar el performance de cada grupo
            performance[cur_disk] -= tables[table];

            // si performance[] llega a ser negativo, la solucion no es valida
            if (performance[cur_disk] < 0) {
                es_valid = false;
                break; //no hace falta seguir evaluando la posibilidad 102012
            }
        }
        //cout << endl;
        if (es_valid) {
            // determinar la velocidad minima
            int vel_min = performance[0]; // asignamos por ejemplo al primer dato
            for (int disk = 0; disk < TOTAL_DISKS; disk++) {
                if (performance[disk] < vel_min) {
                    vel_min = performance[disk];
                    disco_max = disk;
                }
            }
            if (vel_max < vel_min) {
                vel_max = vel_min;
                copy(TOTAL_TABLES, best_solution, combination);
            }
        }
    }

    // imprimir
    for (int disk = 0; disk < TOTAL_DISKS; disk++) {
        cout<<"Disco "<<disk+1<<": ";
        for (int table = 0; table < TOTAL_TABLES; table++) {
            if (disk == best_solution[table]) {
                cout<<table+1<<' ';
            }
        }
        cout<<endl;
    }
    cout<<"Esta solucion tiene una velocidad minima de grupo de "
    <<vel_max<<" IOPs que se da en el disco "<<disco_max<<endl;

    /* SOLUCION
    Disco   Tablas
    ---------------
    1       5,3,6
    2       2,4
    3       1
    velo_min: 40
    */
}
int main() {
    // Declarar tablas y discos
    int tables[TOTAL_TABLES] = {150, 100, 80, 50, 120, 10};
    int disks[TOTAL_DISKS] = {250, 200, 200};
    solve(tables, disks);
    return 0;
}
