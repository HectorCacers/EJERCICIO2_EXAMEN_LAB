// ejercicio2 de examen laboratorio.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

class Pregunta {
public:
    string especificacion;
};

class BancoDePreguntas {
public:
    vector<Pregunta> preguntas;
    int cantidad;

    BancoDePreguntas(int cant) {
        cantidad = cant;
        preguntas.resize(cantidad);
        preguntas[0].especificacion = "cuanto es 8+8?";
        preguntas[1].especificacion = "cuanto es 9*7?";
        preguntas[2].especificacion = "cuanto es 12+50?";
        preguntas[3].especificacion = "cuanto es 24/6?";
        preguntas[4].especificacion = "cuanto es 17+60+72?";
        preguntas[5].especificacion = "cuanto es 50-6?";
        preguntas[6].especificacion = "cual es el valor de pi?";
        preguntas[7].especificacion = "cual es la raiz cuadrada de 9?";
        preguntas[8].especificacion = "cuánto es 150*40?";
        preguntas[9].especificacion = "cuánto es 600-430?";
    }
};

class Examen {
public:
    string asignatura;
    vector<Pregunta> preguntas;
    int puntaje;
    int cantidad;

    void crearExamen(int cantPreguntas, BancoDePreguntas banco) {
        if (cantPreguntas < 3 || cantPreguntas > banco.cantidad) {
            cout << "La cantidad de preguntas debe ser mayor o igual a 3 y menor o igual que " << banco.cantidad << endl;
            return;
        }

        preguntas.clear();

        // Seleccionar preguntas aleatorias sin repetición
        vector<int> indices(banco.cantidad);
        for (int i = 0; i < banco.cantidad; i++) {
            indices[i] = i;
        }
        random_shuffle(indices.begin(), indices.end());
        for (int i = 0; i < cantPreguntas; i++) {
            preguntas.push_back(banco.preguntas[indices[i]]);
        }

        cantidad = cantPreguntas;
        puntaje = 15 + 5 * cantidad;
    }

    void imprimirExamen() {
        cout << "---" << asignatura << "---  ";
        cout << puntaje << " puntos" << "\n";
        cout << "Cantidad de preguntas: " << cantidad << "\n";

        for (int i = 0; i < cantidad; i++) {
            cout << i + 1 << ") " << preguntas[i].especificacion << "   ";
            cout << puntaje / cantidad << " puntos" << "\n";

            cout << "---------------------------------" << "\n";
        }
    }
};

int main() {
    srand(time(0));

    BancoDePreguntas banco(10);
    Examen examen;

    examen.asignatura = "Matemáticas";
    examen.crearExamen(3, banco);
    examen.imprimirExamen();

    return 0;
}
