#include <iostream>

using namespace std;

void MaxYMin(int inicio, int fin, int a[], int & Min, int & Max){
    if (inicio<=fin){
        int mitad=(inicio+fin)/2;

        MaxYMin(inicio,mitad-1,a,Min,Max); //Divide y conquista, como Merge, va para la izq.
        MaxYMin(mitad+1,fin,a,Min,Max); //Derecha.

        if (a[mitad]<Min)   //Reemplaza minimos y maximos
            Min=a[mitad];
        if (a[mitad]>Max)
            Max=a[mitad];

    }
}


int main()
{
    int inicio=0;
    int fin=10;
    int arreglo[10];

    cout << "Ingrese los elementos del arreglo" << endl;

    for (int i=inicio;i<fin;i++){
        cin >> arreglo[i];
    }

    int Min = arreglo[(inicio+fin)/2];
    int Max = arreglo[(inicio+fin)/2];

    MaxYMin(inicio,fin,arreglo,Min,Max);

    cout << "El maximo elemento del arreglo es " << Max <<endl;
    cout << "El minimo elemento del arreglo es " << Min <<endl;

    return 0;
}
