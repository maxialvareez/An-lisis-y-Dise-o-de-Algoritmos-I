#include <iostream>

using namespace std;
void monedas(int resultado[3][9], int total, int valores[3]);

int main()
{
    int resultado[3][9];
    for (int l = 0; l<=2;l++){
        for (int m = 0; m<=8;m++){
            resultado[l][m] = 0;
        }
    }
    int valores[3] = {1,4,6};
    int total = 8;
    monedas(resultado,total,valores);

}


void monedas(int resultado[3][9], int total, int valores[3])
{
    for (int k = 0; k<=2; k++){
        resultado[k][0] = 0;
    }

    for (int i = 0; i<=2; i++)
    {
        for (int j = 0; j<=8; j++)
        {
            if ((i == 0) && (j<valores[i]))
            {
                resultado[i][j] = j;
            }
            else if (i == 0)
            {
                resultado[i][j] = 1+ resultado[0][j-valores[0]];
            }
            else if (j<valores[i])
            {
                resultado[i][j] = resultado[i-1][j];
            }
            else if (resultado[i-1][j] < 1+resultado[i][j-valores[i]])
            {
                resultado[i][j] = resultado[i-1][j];
            }
            else if (resultado[i-1][j] > 1+resultado[i][j-valores[i]])
            {
                resultado[i][j] = 1+resultado[i][j-valores[i]];

            }
        }
    }
    for (int s=0;s<=2;s++){
        for (int d=0;d<=8;d++){
            cout << resultado[s][d] << " || ";
        }
        cout << endl;
    }
}

