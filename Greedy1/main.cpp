#include <iostream>

using namespace std;

void greedy(int monedas[], int total);

int main()
{
    // Ordenar el arreglo de monedas de mayor a menor para que vayan cabiendo la minima cantidad de monedas posibles.
    int monedas[5] = {100, 25, 10, 5, 1};
    int total = 289;
    greedy(monedas,total);
}

void greedy(int monedas[], int total){
    int resultado[5];
        for (int k=0;k<=4;k++){
            resultado[k] = 0;
        }
        for (int i= 0; i<=4; i++){
            while (total >= monedas[i]){
                total = total-monedas[i];
                resultado[i] = resultado[i]+1;
        }
        }
        for (int j=0;j<=4;j++){
            cout << resultado[j] << endl;
        }
}
