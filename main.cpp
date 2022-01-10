/******Descripcion del tema*********
 * 
 * Metodo de ordenamiento por incersion
**************/
/*********Librerias******/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
/*********Usings************/
using namespace std;
/**********Prototipos****************/
void randomNumbers();
void insertionMethod();
void imprimir();
/********Variables globales**********/
const int length = 500;
int *numeros = new int[0];
/*************Funcion Main**********/
int main(int argc, char const *argv[])
{
    /****Variables locales****/
    randomNumbers();
    insertionMethod();
    imprimir();
    cout << "Tiempo de ejecucion: " << clock() << "ms" << endl;
    getch();
    return 0;
}
/****************Metodos o funciones************/
void randomNumbers()
{
    // Rand es un metodo de cstdlib (en c++), y stdlib.h (en c), se divide entre 100 para que de un numero entre 0 y 100, y se le suma para que de entre 1 y 100.
    // length = rand() % 1000 + 1;
    *&numeros = new int[length];
    cout << "Arreglo desordenado: ";
    for (int i = 0; i < length; i++)
    {
        *&numeros[i] = rand() % 100;
        cout << *&numeros[i] << ",";
    }
    cout << endl;
}
void insertionMethod()
{
    int numDerecha = 0, numIzquierda = 0;
    for (int i = 0; i < length; i++)
    {
        numDerecha = *&numeros[i];
        for (int j = i - 1; j >= 0; j--)
        {
            numIzquierda = *&numeros[j];
            if (numDerecha > numIzquierda)
            {
                *&numeros[j + 1] = numIzquierda;
                *&numeros[j] = numDerecha;
                numDerecha = *&numeros[j];
            }
        }
    }
}
void imprimir()
{
    cout << "Arreglo ordenado: ";
    for (int i = 0; i < length; i++)
    {
        cout << *&numeros[i] << ",";
    }
    cout << endl;
}