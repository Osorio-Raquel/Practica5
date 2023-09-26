// Materia: Programación I, Paralelo 2

// Autor: Raquel Osorio Mamani

// Fecha creación: 21/09/2023

// Fecha modificación: 21/09/2023
 
// Número de ejericio: 1

// Problema planteado: La información de todos los empleados de la UCB se almacena en una variable tipo struct llamada “empleado”. La información con que se cuenta es: nombre, ci, 
// departamento y salario. Realizar un programa en C++ que lea un array de estructura de los datos de N empleados e imprima los siguiente:
// • Empleado con mayor salario
// • Empleado con menor salario
// • Promedio salarial
// • Promedio por departamento
// • Departamento con mayor salario en promedio
// • Departamento con menor salario en promedio

#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Empleado {
    string n;
    int c;
    string d;
    double s;
};

Empleado empMaxS(Empleado e[], int N) {
    Empleado maxS = e[0];
    for (int i = 1; i < N; i++) {
        if (e[i].s > maxS.s) {
            maxS = e[i];
        }
    }
    return maxS;
}

Empleado empMinS(Empleado e[], int N) {
    Empleado minS = e[0];
    for (int i = 1; i < N; i++) {
        if (e[i].s < minS.s) {
            minS = e[i];
        }
    }
    return minS;
}


double promSal(Empleado e[], int N) {
    double sumaS = 0.0;
    for (int i = 0; i < N; i++) {
        sumaS += e[i].s;
    }
    return sumaS / N;
}

string depMaxS(Empleado e[], int N) {
    double maxProm = 0.0;
    string depMaxProm = "";

    for (int i = 0; i < N; i++) {
        string depActual = e[i].d;
        double sumaS = 0.0;
        int contador = 0;

        for (int j = 0; j < N; j++) {
            if (e[j].d == depActual) {
                sumaS += e[j].s;
                contador++;
            }
        }

        double promedio = sumaS / contador;

        if (promedio > maxProm) {
            maxProm = promedio;
            depMaxProm = depActual;
        }
    }

    return depMaxProm;
}

string depMinS(Empleado e[], int N) {
    double minProm = numeric_limits<double>::max();
    string depMinProm = "";

    for (int i = 0; i < N; i++) {
        string depActual = e[i].d;
        double sumaS = 0.0;
        int contador = 0;

        for (int j = 0; j < N; j++) {
            if (e[j].d == depActual) {
                sumaS += e[j].s;
                contador++;
            }
        }

        double promedio = sumaS / contador;

        if (promedio < minProm) {
            minProm = promedio;
            depMinProm = depActual;
        }
    }

    return depMinProm;
}

int main() {
    int N;
    cout << "Ingrese la cantidad de empleados: ";
    cin >> N;

    Empleado e[N];

    for (int i = 0; i < N; i++) {
        cout << "Ingrese el nombre del empleado " << i + 1 << ": ";
        cin.ignore();
        getline(cin, e[i].n);
        cout << "Ingrese la CI del empleado " << i + 1 << ": ";
        cin >> e[i].c;
        cout << "Ingrese el departamento del empleado " << i + 1 << ": ";
        cin.ignore();
        getline(cin, e[i].d);
        cout << "Ingrese el salario del empleado " << i + 1 << ": ";
        cin >> e[i].s;
    }

    Empleado maxS = empMaxS(e, N);
    Empleado minS = empMinS(e, N);
    double prom = promSal(e, N);
    string depMaxProm = depMaxS(e, N);
    string depMinProm = depMinS(e, N);

    cout << "\nEmpleado con mayor salario:\n";
    cout << "Nombre: " << maxS.n << endl;
    cout << "CI: " << maxS.c << endl;
    cout << "Departamento: " << maxS.d << endl;
    cout << "Salario: " << maxS.s << endl;

    cout << "\nEmpleado con menor salario:\n";
    cout << "Nombre: " << minS.n << endl;
    cout << "CI: " << minS.c << endl;
    cout << "Departamento: " << minS.d << endl;
    cout << "Salario: " << minS.s << endl;

    cout << "\nPromedio salarial: " << prom << endl;

    cout << "\nDepartamento con mayor salario en promedio: " << depMaxProm << endl;

    cout << "\nDepartamento con menor salario en promedio: " << depMinProm << endl;

    return 0;
}

