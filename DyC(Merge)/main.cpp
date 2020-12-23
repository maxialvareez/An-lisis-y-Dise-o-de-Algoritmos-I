#include <iostream>

using namespace std;

void mergesort(int a[], int inicio, int fin);
void Merge(int a[], int inicio, int mitad, int fin);

int main()
{
int a[10];
int k;
for (int i=0;i<10;i++){
    cin >> k;
    a[i] = k;
}
int inicio = 0;
int fin = 9;
mergesort(a,inicio,fin);
for (int k = 0; k<10;k++){
    cout << a[k] << "||";
}
}

void mergesort(int a[], int inicio, int fin){
    if (inicio < fin){
            int mitad = (inicio + fin)/2;
            mergesort(a,inicio,mitad); // Primera mitad
            mergesort(a,mitad+1,fin); // Segunda mitad
            Merge(a,inicio,mitad,fin); // Merge
    }
}


void Merge(int a[], int inicio, int mitad, int fin)
{
    int q = inicio;
    int w = inicio;
    int e = mitad+1;
    int b[10];
    while ((q<= mitad) && (e<=fin)) // Mientras que los indices de las mitades no se pasen de esas mitades
    {
        if (a[q]<=a[e]) // Compara el primero elemento de la primer mitad con el primero de la segunda mitad.
        {
            b[w] = a[q];
            q++;
        }
        else
        {
            b[w] = a[e]; // Si es m�s grande el segundo, coloca el segundo.
            e++;
        }
        w++;
    }
    if (q>mitad)
        for (int i = e; i<=fin; i++) // Si se pasa de la mitad, todos los que quedaron de la otra mitad que no se pasaron, se pasan automaticamente.
        {
            b[w] = a[i];
            w++;
        }
    else
        for (int i=q; i<=mitad; i++) // Lo contrario.
        {
            b[w] = a[i];
            w++;
        }
    for (int l=inicio; l<=fin; l++) // Se copia el arreglo b, que era el auxiliar, en el original que es a.
        a[l] = b[l];
}
