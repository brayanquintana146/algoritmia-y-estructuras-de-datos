#include <iostream>
#include <string>

using namespace std;

string binary_representation(int n) {
    if (n == 0) return "0";
    if (n == 1) return "1";
    return (binary_representation(n/2)+to_string(n%2));
}


int main() {
    int number = 10;
    string resultado = binary_representation(number);
    cout<<resultado<<endl;
    return 0;
}
