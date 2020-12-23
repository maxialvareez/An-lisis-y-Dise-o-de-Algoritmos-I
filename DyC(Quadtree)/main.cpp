#include <iostream>
/* Quadtree es una forma de dividir las matrices ralas(matrices que tienen en su mayoría un mismo valor, normalmente 0), en submatrices, almacenando las direcciones y los valores en dos
arreglos, uno de direcciones y otro de valores. Dentro de los arreglos, un valor positivo indica una matriz que vuelvo a particionar y representa el indice dentro del mismo arreglo de
particiones, es decir, la posición dentro del mismo arreglo, mientras que un valo negativo, indica el indice en el arreglo de valores, es decir en el otro arreglo, donde esta almacenada
la información, mientras que un cero, indica la región de ceros conocidos.*/

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
