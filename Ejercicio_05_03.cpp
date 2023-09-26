// Materia: Programación I, Paralelo 2

// Autor: Raquel Osorio Mamani

// Fecha creación: 21/09/2023

// Fecha modificación: 21/09/2023
 
// Número de ejericio: 3

// Problema planteado: Realice un programa en C++ con funciones y estructuras para el estacionamiento del Multicine.
// Este estacionamiento cuenta con 4 pisos, cada piso tiene distintas capacidades de autos
// Piso 1 – 50 autos
// Piso 2 – 40 autos
// Piso 3 – 30 autos
// Piso 4 – 45 autos
// El estacionamiento debe recibir varios tipos de autos (vagoneta, camionetas, automóviles, minivans y motocicletas), marca del auto, modelo del auto y color del auto.
// Escribir un programa en C++ utilizando funciones y estructuras para:
// • Simular la entrada de vehículos, el programa debe pedir la cantidad de vehículos ingresados y el programa debe simular los tipos de vehículo, la marca, el modelo, el color y en 
// que piso se han estacionado.
// • La simulación puede repetirse varias veces hasta que el usuario ingrese el valor de 0 (cero) en la cantidad de vehículos. La cantidad de vehículos debe se incremental.
// • Luego de cada ingreso de vehículos se desea saber cuantos hay estacionado en cada piso.
// • Cuantos son vagoneta, camionetas, automóviles, minivans y motocicletas.
// • Hacer un reporte por colores de autos, modelo y marca.
// • La simulación debe determinar cuando el parqueo se ha llenado.
// • La simulación debe determinar cuántos espacios libres queda.

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Vh {
    string tp;
    string mc;
    string mdl;
    string clr;
    int yr;
};

const int NP = 4;
const int CP[NP] = {50, 40, 30, 45};
vector<vector<char>> estacionamiento(NP, vector<char>(50, ' '));

void initEst() {
    for (int i = 0; i < NP; i++) {
        for (int j = 0; j < CP[i]; j++) {
            estacionamiento[i][j] = ' ';
        }
    }
}

void imprEst() {
    for (int i = 0; i < NP; i++) {
        cout << "Piso " << i + 1 << ":\n";
        for (int j = 0; j < CP[i]; j++) {
            cout << estacionamiento[i][j] << " ";
        }
        cout << endl;
    }
}


string genTp() {
    string tipos[] = {"vagoneta", "camioneta", "automóvil", "minivan", "motocicleta"};
    return tipos[rand() % 5];
}

string genMc() {
    string marcas[] = {"Toyota", "Ford", "Honda", "Chevrolet", "Nissan", "Volkswagen", "BMW", "Hyundai"};
    return marcas[rand() % 8];
}

string genClr() {
    string colores[] = {"Rojo", "Azul", "Blanco", "Negro", "Plateado", "Gris", "Verde"};
    return colores[rand() % 7];
}

int genYr() {
    return 1990 + rand() % 32; // Años entre 1990 y 2021
}

bool agrVh() {
    for (int i = 0; i < NP; i++) {
        for (int j = 0; j < CP[i]; j++) {
            if (estacionamiento[i][j] == ' ') {
                estacionamiento[i][j] = 'X';
                return true;
            }
        }
    }
    return false;
}

void imprSep() {
    cout << "----------------------------------------" << endl;
}

int main() {
    srand(time(0));

    initEst();

    int totVhIngresados = 0;
    map<string, int> tpVhCnt;
    map<string, int> clrCnt;
    map<string, int> mcCnt;
    map<int, int> yrCnt;

    cout << "Bienvenido al estacionamiento del Multicine!!!!" << endl;

    while (true) {
        cout << "Ingrese la cantidad de vehiculos a agregar (0 para finalizar): ";
        int N;
        cin >> N;
        if (N == 0) {
            break;
        } else {
            for (int i = 0; i < N; i++) {
                bool estacionado = agrVh();
                if (estacionado) {
                    totVhIngresados++;

                    Vh vehiculo;
                    vehiculo.tp = genTp();
                    vehiculo.mc = genMc();
                    vehiculo.clr = genClr();
                    vehiculo.yr = genYr();

                    tpVhCnt[vehiculo.tp]++;
                    clrCnt[vehiculo.clr]++;
                    mcCnt[vehiculo.mc]++;
                    yrCnt[vehiculo.yr]++;
                } else {
                    cout << "El estacionamiento esta lleno. No se puede estacionar más vehiculos." << endl;
                    break;
                }
            }
        }
    }

    cout << "----------------------------------------" << endl;
    cout << "           INFORME DE ESTACIONAMIENTO   " << endl;
    cout << "----------------------------------------" << endl;

    cout << "Estado final del estacionamiento:\n";
    imprEst();

    cout << "----------------------------------------" << endl;

    cout << "Total de vehiculos estacionados: " << totVhIngresados << endl;
    imprSep();

    for (int i = 0; i < NP; i++) {
        int vhEstacionados = CP[i] - count(estacionamiento[i].begin(), estacionamiento[i].end(), ' ');
        if (vhEstacionados < 0) {
            vhEstacionados = 0;
        }
        cout << "En el piso " << i + 1 << " hay " << vhEstacionados << " vehiculos estacionados." << endl;
    }
    imprSep();

    for (const auto& entry : tpVhCnt) {
        cout << "Cantidad de " << entry.first << "s: " << entry.second << endl;
    }
    imprSep();

    for (const auto& entry : clrCnt) {
        cout << "Cantidad de vehículos de color " << entry.first << ": " << entry.second << endl;
    }
    imprSep();

    for (const auto& entry : mcCnt) {
        cout << "Cantidad de vehículos de la marca " << entry.first << ": " << entry.second << endl;
    }
    imprSep();

    for (const auto& entry : yrCnt) {
        cout << "Cantidad de vehículos del año " << entry.first << ": " << entry.second << endl;
    }
cout << "Muchas gracias por usar el sistema de estacionamiento del Multicine!!!!" << endl;
    return 0;
}

