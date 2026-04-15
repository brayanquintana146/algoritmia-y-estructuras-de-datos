#include <iostream>
#include <iostream>
#include <cstring>

using namespace std;
const int TAM_MAX_PALAB=8;
const int CANT_MAX_PALAB=8;
const int TAM_MAX_LETRAS=10;


struct Palabra {
    char texto[TAM_MAX_PALAB];
    int cantidad_combina;
    int cant_letras;
};

void determinarCantLetrasDePalabra(Palabra palabras[], int cant_palabras) {
    for (int i=0; i<cant_palabras; i++) {
        palabras[i].cant_letras=0;
        for (int j=0; palabras[i].texto[j]!='\0';j++) {
            palabras[i].cant_letras++;
        }
    }
}

int determinarCantLetras(char letra, char texto[]) {
    int apariciones=0;
    for (int i=0; texto[i]!='\0'; i++) {
        if (letra == texto[i]) {
            apariciones++;
        }
    }
    return apariciones;
}

int factorial(int n) {
    if (n==0) {
        return 1;
    }
    return n*factorial(n-1);
}

int CantDifereEscogerLetra(const int cant_disponib, const int cant_necesita) {
    int numerador=factorial(cant_disponib);
    int denominador=factorial(cant_necesita)*factorial(cant_disponib-cant_necesita);
    return numerador/denominador;
}

void solve(char letras[TAM_MAX_LETRAS], Palabra palabras[CANT_MAX_PALAB]){
    int cant_palabras=0;
    int cant_letras=0;
    for(int i=0; letras[i]; i++) cant_letras++;
    for (int i=0; palabras[i].texto[0]!='\0'; i++) cant_palabras++;
    determinarCantLetrasDePalabra(palabras, cant_palabras);

    // imprimir todas las letras
    cout<<"Si tenemos las letras: ";
    for (int i=0; i<cant_letras; i++) {
        cout<<letras[i];
    }
    cout<<endl<<"Y queremos formas las palabras: ";
    for (int i=0; i<cant_palabras; i++) {
        cout<<palabras[i].texto<<" ";
    }
    cout<<endl<<"------------------------------------------------------"<<endl;
    for (int i=0; i<cant_palabras; i++) {
        int cantCombina=1;
        int cant_letras_sin_repeti=0;
        char palabra_letras_sin_rep[TAM_MAX_PALAB]{};
        for (int j=0; j<palabras[i].cant_letras; j++) {
            char letra=palabras[i].texto[j];
            int cant_apariciones=determinarCantLetras(letra, palabra_letras_sin_rep);
            if (cant_apariciones==0) {
                palabra_letras_sin_rep[cant_letras_sin_repeti]=letra;
                cant_letras_sin_repeti++;
            }
        }
        for (int j=0; j<cant_letras_sin_repeti; j++) {
            char letra_analizada = palabra_letras_sin_rep[j];
            int cant_disponib = determinarCantLetras(letra_analizada, letras);
            int cant_necesita = determinarCantLetras(letra_analizada, palabras[i].texto);
            int cant_dif_escog_letra = CantDifereEscogerLetra(cant_disponib, cant_necesita);
            cantCombina = cantCombina * cant_dif_escog_letra;
        }
        palabras[i].cantidad_combina=cantCombina;
        cout<<palabras[i].texto<<" tiene "<<palabras[i].cantidad_combina
        <<" combinaciones de letras"<<endl;
    }
}

int main() {
    char letras[TAM_MAX_LETRAS] = {'G','A','L','A','O','G','L','M'};
    Palabra palabras[CANT_MAX_PALAB]{
        {"GOL",0},
        {"GALA", 0},
        {"ALA", 0},
        {"LOMA", 0}
    };
    solve(letras, palabras);
    return 0;
}
