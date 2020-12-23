#include <iostream>

using namespace std;

void QuickSort(int inicio, int fin, int lista[]){
    //Si la sub-lista tiene un solo elemento no hacemos nada.
    if(fin - inicio <= 1)
        return;

    //Si la sub-lista tiene 2 elementos, los comparamos y ubicamos en la posición correcta.
    if(fin-inicio == 2){
      if(lista[inicio]>lista[inicio+1])
    //Lo que hace “swap(a,b)” es: aux=a, a=b, b=aux. Es decir, intercambia (evitando pisar).
        swap(lista[inicio],lista[inicio+1]);
      return;
    }

    //Seleccionamos el pivote y ubicamos los cursores.
    int pivote = fin-1;
    int i=inicio,
        j=fin-2;

    //A esta sub-lista le hacemos el proceso de ordenamiento visto anteriormente.
    while( i < j){
         if(lista[i] >= lista[pivote] && lista[j] < lista[pivote]){
            swap(lista[i],lista[j]);
             i++;j--;
         }else if(lista[i] >= lista[pivote] && lista[j] >= lista[pivote]){
            j--;
        }else if(lista[i] < lista[pivote] && lista[j] < lista[pivote]){
             i++;
         }else{
             i++;
             j--;
         }
     }
     //Si el primer cursor es mayor que el pivote, los cambiamos.
     if(lista[i] > lista[pivote]){
        swap(lista[i],lista[pivote]);
    }

    // Si el segundo cursor no llegó al inicio del intervalo,
    // mandamos a ordenar la sub-lista izquierda.
    if(j > inicio){
        QuickSort(inicio, i+1, lista);
    }

    //Ordenamos la sub-lista derecha.
    QuickSort(i+1, fin, lista);
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

    QuickSort(inicio,fin,arreglo);

    cout << "El arreglo ordenado es ";

    for (int i=inicio;i<fin;i++){
        cout << arreglo[i];
    }

    return 0;
}
