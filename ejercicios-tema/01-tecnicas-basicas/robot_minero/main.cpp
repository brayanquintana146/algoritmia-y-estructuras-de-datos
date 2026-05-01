#include <iostream>

using namespace std;

const int N=6, M=11;

void inicializarMina(int mina[N][M]) {
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            mina[i][j]=-1;
        }
    }
}

void imprimirMina(int mina[N][M]) {
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (mina[i][j]==-1) cout<<'.'<<' ';
            else if (mina[i][j]==0) cout<<'*'<<' ';
            else cout<<mina[i][j]<<' ';
        }
        cout<<endl;
    }
}

bool solve(int mina[N][M], int row, int column, int nivel) {
    if (row < 0 || row >= N || column < 0 || column >= M) return false;
    if (mina[row][column] != -1) return false;

    mina[row][column]=nivel;

    if (column == M-1) {
        solve(mina, N - nivel-1, 0, nivel+1);
        return true;
    };
    // Bajar (para pegarse al piso o a la galería anterior)
    if (row+1 < N && mina[row+1][column]==-1
        && solve(mina, row+1, column, nivel)) {
        return true;
    }
    // Derecha (Avanzar hacia la meta)
    else if (column+1 < M && mina[row][column+1]==-1
        && solve(mina, row, column+1, nivel)) {
        return true;
    }
    // Arriba (Para rodear obstáculos si no puede bajar ni avanzar)
    else if (row-1>=0 && mina[row-1][column]==-1
        && solve(mina, row-1, column, nivel)) {
        return true;
    }
    mina[row][column]=-1; // para retroceder si no hay salidas
    return false;
}

int main() {
    int mina[N][M];
    inicializarMina(mina);
    mina[3][5]=0;
    mina[4][5]=0;
    mina[5][5]=0;
    solve(mina,N-1,0,1);
    imprimirMina(mina);
    return 0;
}