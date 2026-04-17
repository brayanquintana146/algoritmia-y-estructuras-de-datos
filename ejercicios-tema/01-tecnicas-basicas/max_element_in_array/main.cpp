#include <iostream>

using namespace std;

const int N=8;

int find_max(int numbers[N], int index) {
    //caso base
    if (index == N-1) {
        return numbers[index];
    }
    //caso recursivo
    return max(numbers[index], find_max(numbers, index+1));
}

int main() {
    int numbers[N] = {4, 8, -15, 15, 4, 26, 6, 8};
    int max_number = find_max(numbers, 0);
    cout << "Maximum number in array is: " << max_number << endl;
    return 0;
}
