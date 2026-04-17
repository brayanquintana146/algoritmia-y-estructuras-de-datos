#include <iostream>

using namespace std;

void print_binary_representation(int number) {
    if (number != 0) {
        int digit = number % 2;
        print_binary_representation(number / 2);
        cout << digit;
    }
}

int main() {
    int number = 10;
    print_binary_representation(number);
    return 0;
}
