#include <iostream>

using namespace std;
const int N=10, M=10, alcance=3;


void imprimirMatriz(char matriz[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (matriz[i][j] == ' ') {
                cout << '-'<<' ';
            }
            else cout << matriz[i][j]<<' ';
        }
        cout << endl;
    }
}

void solve(char matriz[N][M], int x, int y, int alcance, int direccion, int&cantEncon) {
    if (alcance==-1) return;
    if (matriz[x][y] == 'A') cantEncon++;
    matriz[x][y] = '*';
    if (direccion>=0) {
        solve(matriz, x-1, y, alcance-1, 1, cantEncon);
        solve(matriz, x-1, y-1, alcance-1, 1, cantEncon);
        solve(matriz, x-1, y+1, alcance-1, 1, cantEncon);
    }
    if (direccion<=0) {
        solve(matriz, x+1, y, alcance-1, -1, cantEncon);
        solve(matriz, x+1, y-1, alcance-1, -1, cantEncon);
        solve(matriz, x+1, y+1, alcance-1, -1, cantEncon);
    }

}

int main() {

    char matriz[N][M]={
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ','A','A',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ','A',' ',' ',' ',' '},
        {' ',' ',' ',' ','A',' ',' ','A',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ','A',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
    };
    int x=5, y=5, cantEncon=0;


    solve(matriz, x, y, alcance, 0, cantEncon);
    imprimirMatriz(matriz);
    cout <<"Cantidad de artefactos encontrados: "<<cantEncon<<endl;

    return 0;
}