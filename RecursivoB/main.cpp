#include <iostream>

using namespace std;
void binario (int n, int arreglo[], int i);

int main()
{
    int i = 0;
    int n = 35;
    int arreglo[6];
    for (int j=0;j<6;j++){
        arreglo[j] = 0;
    }
    binario(n,arreglo,i);
}

void binario (int n, int arreglo[], int i)
{
    if (n <=1)
    {
        arreglo[i] = n;
        for (int j = 0;j<6;j++)
        {
            cout << arreglo[j];
        }
    }
    else
    {
        if (n%2 == 1)
        {
            arreglo[i] = 1;
        }
        else
        {
            if (n%2 == 0)
            {
                arreglo[i] = 0;
            }
        }
        binario(n/2,arreglo,i+1);
    }
}

