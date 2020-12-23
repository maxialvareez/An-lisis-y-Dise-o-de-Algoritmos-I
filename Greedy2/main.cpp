#include <iostream>

using namespace std;
void mochila(float elementos[], float peso);

int main()
{
    float elementos[3] = {15,10,18}; // Lo que se tendria que hacer aca es buscar un metodo de ordenamiento más eficiente posible debido a que depende de este por la complejidad.
    // Peso de los elementos (x,y,z), dividirlo y ordenarlo ponderado de mayor a menor para que ocupe con lo más beneficioso primero.
    float peso = 20;
    mochila(elementos,peso);

}


void mochila(float elementos[], float peso){
    float resultado[3];
    for (int i=0; i<=2;i++){
        resultado[i]=0;
    }
    for (int j=0;j<=3;j++){
        if (peso >= 0){
        if (elementos[j] > peso){
            resultado[j] = peso/elementos[j];
        } else {
            resultado[j] = 1;
    }
        peso = peso - (resultado[j]*elementos[j]);
    }
    }
    for (int k = 0; k<=2;k++){
        cout << resultado[k] << endl;
    }

}
