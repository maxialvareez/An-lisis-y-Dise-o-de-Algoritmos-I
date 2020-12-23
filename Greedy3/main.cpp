#include <iostream>

using namespace std;
void procesador(int tareas[4], int tiempos[4], int resultado[2]);

int main()
{
    int tareas[4] = {10,30,15,50}; //Ordenado por tiempo
    int tiempos[4]= {1,1,2,2};
    int resultado[2];
    procesador(tareas,tiempos,resultado);
}

void procesador(int tareas[4], int tiempos[4], int resultado[2]){
    for (int i = 0; i<=1; i++)
        resultado[i] = 0;
    int aux = 0;
    int k = 0;
    int l = 1;
    for (int j = 0; j<=1;j++){
        while (tiempos[k]==l){
            if (aux < tareas[k]){
                aux = tareas[k];
            }
            k++;
        }
        l++;
        resultado[j] = aux;
    }
    for (int a=0;a<=1;a++){
       cout << resultado[a] << endl;
    }
}


/*
int Planificar_tareas (int p[], int J[], int n)
//retorna la cantidad de elementos (k) de la solución
//factible y la solución en los k primeros elementos J
{ p[0]=0; J[0]=0;
J[1]=1; // la tarea 1 siempre se selecciona
int k=1; // la variable k dice cuántas tareas están ya en la planificación
for (int i=2; i<=n;i++) //tareas restantes tomadas en orden decreciente de g
{ int r=k;
while( (p[J[r]] > p[i]) && (p[J[r]] != r))
r--;
if ((p[J[r]] <= p[i]) && (p[i] > r))
{ for (int q = k; q >= (r+1); q--)
J[q+1] = J[q];
J[r+1] = i;
k++;
}
}
return k;
}
*/
