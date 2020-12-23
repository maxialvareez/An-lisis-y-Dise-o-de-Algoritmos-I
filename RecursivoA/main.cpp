#include <iostream>
#include <string>

using namespace std;

void reversa (float n, int arreglo[], int i);

int main()
{
float n = 54321;
int arreglo[5];
int i = 0;
for (int i = 0; i<5;i++){
    arreglo[i] = 0;
}
reversa(n,arreglo, i);
}

void reversa (float n, int arreglo[], int i){
    if (n<10){
        int aux2 = n;
        for (int i = 0;i<4;i++)
            cout << arreglo[i];
            cout << aux2;
    } else {
        n = n/10;
        int entero = n;
        float aux = (n-entero)*10;
        arreglo[i] = aux;
        reversa(n,arreglo,i+1);
    }
    }

