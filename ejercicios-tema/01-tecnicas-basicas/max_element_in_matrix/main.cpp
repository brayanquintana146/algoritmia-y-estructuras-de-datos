#include <iostream>
#include <strings.h>

using namespace std;

const int N = 2;
const int M = 10;

int find_max_value(int numbers[N][M], int row, int column) {
    // caso base
    if (row == N-1 and column == M-1) {
        return numbers[row][column];
    }
    // caso recursivo 1: si estamos en la última columna, comparamos ese elemento
    // con el máximo de toda la fila siguiente
    else if (column == M-1 and row != N) {
        return max(numbers[row][column], find_max_value(numbers, row+1, 0));
    }
    // caso recursivo 2: si no estamos ni en el final de una fila ni en el final de la matriz,
    // comparamos ese elemento con el máximo de todo el resto de la fila
    return max(numbers[row][column], find_max_value(numbers, row, column+1));
}

int main() {
    int numbers[N][M] = {
        {4, 8, -15, 15, 4, 26, 6, 8, 10, 5},
        {40, -4, 5487, 15, 4, 222, 87, 8, 10, 5},
    };
    int max_number = find_max_value(numbers, 0, 0);
    cout << "Maximum in an array " << max_number << endl;
    return 0;
}
