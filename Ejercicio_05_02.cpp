// Materia: Programación I, Paralelo 2

// Autor: Raquel Osorio Mamani

// Fecha creación: 21/09/2023

// Fecha modificación: 21/09/2023
 
// Número de ejericio: 2

// Problema planteado: De acuerdo con la siguiente estructura, realice en C++ un programa que lea N atletas y nos devuelva el país que mayor número de medallas ha ganado.

#include <iostream>
#include <cstring>
using namespace std;


struct Datos {
    char N[40];  
    char P[25];  
};

struct Atletas {
    char D[30];          
    struct Datos Pers;  
    int M;             
};

int main() {
    int N;  
    cout << "Ingrese la cantidad de atletas: ";
    cin >> N;

    struct Atletas Ats[30];

    char PM[25] = "";   // País con más medallas
    int MM = 0;       

    for (int i = 0; i < N; i++) {
        cout << "Ingrese el nombre del atleta " << i+1 << ": ";
        cin.ignore();
        cin.getline(Ats[i].Pers.N, 40);
        cout << "Ingrese el pais del atleta " << i+1 << ": ";
        cin.getline(Ats[i].Pers.P, 25);
        cout << "Ingrese el deporte del atleta " << i+1 << ": ";
        cin.getline(Ats[i].D, 30);
        cout << "Ingrese el numero de medallas que tiene el atleta " << i+1 << ": ";
        cin >> Ats[i].M;
        if (Ats[i].M > MM) {
            MM = Ats[i].M;
            strcpy(PM, Ats[i].Pers.P);
        }
    }

    int TM = 0;  // Total de medallas del pais
    for (int i = 0; i < N; i++) {
        if (strcmp(Ats[i].Pers.P, PM) == 0) {
            TM += Ats[i].M;
        }
    }
    cout << "\n*****DATOS DEL ATLETA CON MAYOR NUMERO DE MEDALLAS*****\n";
    cout << "NOMBRE: " << Ats[N - 1].Pers.N << endl;
    cout << "PAIS: " << Ats[N - 1].Pers.P << endl;
    cout << "DEPORTE: " << Ats[N - 1].D << endl;
    cout << "NUMERO DE MEDALLAS: " << Ats[N - 1].M << endl;

    cout << "\n*****PAÍS CON MAS MEDALLAS Y CANTIDAD TOTAL DE MEDALLAS*****\n";
    cout << "PAIS: " << PM << endl;
    cout << "CANTIDAD TOTAL DE MEDALLAS: " << TM << endl;

    return 0;
}
