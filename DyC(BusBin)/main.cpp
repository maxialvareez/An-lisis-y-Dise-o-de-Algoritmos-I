#include <iostream>

using namespace std;

void indice(int arreglo[],int inicio,int fin){
    if (inicio<fin){
        int mitad =(inicio+fin)/2;
        if (mitad == arreglo[mitad]) //Si el numero corresponde con el indice
            cout << "El numero es " << mitad << endl;
        else {
            if (mitad<arreglo[mitad]) // Si el numero es más chico (Arreglo ordenado, de enteros diferentes con posibles negativos)
                indice(arreglo,inicio,mitad-1); // Va para la izq.
            else
                indice (arreglo,mitad+1,fin); // Va para la der.
        }
    }
    else
        cout << "No hay un numero"; // Si no encuentra, no hay numero.
}

int main()
{
    int inicio=1,fin=10;
    int arreglo[10]={-2,-1,0,1,2,3,5,7,8,10};
    indice(arreglo,inicio,fin);
    return 0;
}
