#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include "Lista.h"
#include "Arbin.h"

struct Registro
{
    float costo;
    int raiz;
};

using namespace std;
void InicMatriz(Registro **&Matriz,int Fila, int Col);
void CargarDiagonal(Registro **&Matriz,int Fila,int Col,Lista<string> ListaElementos);
void Rellenar(Registro **&Matriz, int g,int Fila, int Col);
void Imp(Registro **&Matriz,int Fila,int Col);
float CostoTotal(Registro **&Matriz,int g,int i, int j, int Fila, int Col);
float costoMin(Registro **&Matriz, int i, int j, int Fila, int Col);
float StringToNumber(const string& numberAsString);
void SepararString(string &str, string resultado[]);
void cargar_coleccion(string path, string resultado[], Lista<string> &ListaElementos);
void buscarpalabraArbol(string pathBusqueda, string pathResultado, Arbin<string> arbol, int & tamanio);
void llenarArbol(Arbin<string> &arbol, Registro **&Matriz, Lista<string>& ListaElementos, int aux, int col,string posicion);

int main()
{
    string posicion;
    int tamanio;
    int a;
    int aux = 0;
    int Fila;
    int Col;
    Lista<string> ListaElementos;
    Arbin<string> arbol;
    string resultado[2];
    string str;
    cout << "Digite 1 o 2 dependiendo el archivo de claves que desee cargar" << endl;
    cin >> a;
    if (a == 1)
    {
        Col = 10;
        Fila = 10;
        Registro **Matriz;
        InicMatriz(Matriz,Fila,Col);
        cout << "~~~~ Lista ~~~~" << endl;
        cout << endl;
        cargar_coleccion("Datasets\\Claves_1.txt",resultado, ListaElementos);
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "~~~~ Matriz ~~~~" << endl;
        cout << endl;
        CargarDiagonal(Matriz,Fila,Col,ListaElementos);
        for (int g = 1; g<=Col-1; g++)
        {
            Rellenar(Matriz,g,Fila,Col);
        }
        Imp(Matriz,Fila,Col);
        Col = Col-1;
        llenarArbol(arbol, Matriz,ListaElementos,aux,Col,posicion);
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "~~~~~~ Arbol Optimo ~~~~~~" << endl;
        cout << endl;
        arbol.inOrden();
        buscarpalabraArbol("Datasets/Busqueda_1.txt", "Datasets/Resultado_Arbin1.txt", arbol, tamanio);
    }
    if (a == 2)
    {
        Col = 37;
        Fila = 37;
        Registro **Matriz;
        InicMatriz(Matriz,Fila,Col);
        cout << "~~~~ Lista ~~~~" << endl;
        cout << endl;
        cargar_coleccion("Datasets\\Claves_2.txt",resultado, ListaElementos);
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "~~~~ Matriz ~~~~" << endl;
        cout << endl;
        CargarDiagonal(Matriz,Fila,Col,ListaElementos);
        for (int g = 1; g<=Col-1; g++)
        {
            Rellenar(Matriz,g,Fila,Col);
        }
        Imp(Matriz,Fila,Col);
        Col = Col-1;
        llenarArbol(arbol, Matriz,ListaElementos,aux,Col,posicion);
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "~~~~~~ Arbol Optimo ~~~~~~" << endl;
        cout << endl;
        arbol.inOrden();
        buscarpalabraArbol("Datasets/Busqueda_2.txt", "Datasets/Resultado_Arbin2.txt", arbol, tamanio);
    }
    return 0;
}

void cargar_coleccion(string path, string resultado[], Lista<string> &ListaElementos)
{
    ifstream origen(path.c_str());
    if (!origen.is_open())
        cout << "No se pudo abrir el archivo: " << path << endl;
    else
    {
        while (!origen.eof())
        {
            string palabra;
            origen >> palabra;
            cout << palabra << endl;
            SepararString(palabra,resultado);
             ListaElementos.agregarElementos(resultado[0],StringToNumber(resultado[1]));


        }
        ListaElementos.ImprimirLista();
    }
}

void buscarpalabraArbol(string pathBusqueda, string pathResultado, Arbin<string> arbol, int & tamanio)
{
    float costo = 0;
    ifstream busqueda(pathBusqueda.c_str());
    if (!busqueda.is_open())
        cout << "No se pudo abrir el archivo: " << pathBusqueda << endl;
    else
    {
        ofstream resultado(pathResultado.c_str(), ios::trunc);
        while (!busqueda.eof())
        {
            string palabra;
            busqueda >> palabra;
            resultado << palabra << ", costo arbol: " << costo << ", costo metrica: "<< costo/arbol.cantElementos() << " ." << " Existe = 1 ~ No existe = 0. Resultado: " << arbol.perteneceElemento(palabra,costo) << endl;
        }
    }
}

float StringToNumber(const string& numberAsString)
{
    float valor;

    std::stringstream stream(numberAsString);
    stream >> valor;
    return valor;
}

void SepararString(string &str, string resultado[])
{
    int i = 0;
    string line;
    stringstream  data(str);
    while(getline(data,line,','))
    {
        if (i<2)
        {
            resultado[i] = line;
            i++;
        }
    }

}


void InicMatriz(Registro **&Matriz,int Fila,int Col)
{
    int i,j;
    Matriz = new Registro*[Fila];
    for(i=0; i<Fila; i++)
    {
        Matriz[i]=new Registro[Col];
        for(j=0; j<Col; j++)
        {
            Matriz[i][j].costo = 0;
            Matriz[i][j].raiz = 9;
        }
    }
}
void Imp(Registro**&Matriz,int Fila,int Col)
{
    for(int i=0; i<Fila; i++)
    {
        for(int j=0; j<Col; j++)
        {
            cout << "  ||  " << Matriz[i][j].costo << " // " << Matriz[i][j].raiz;
        }
        cout << "  ||  " <<endl;
    }
}

void CargarDiagonal(Registro**&Matriz,int Fila,int Col,Lista<string> ListaElementos)
{
    int j = 0;
    int a = 0;
    for (int i=0; i<Fila; i++)
    {
        if (j<Col)
        {
            Matriz[i][j].costo = ListaElementos.getCosto();
            Matriz[i][j].raiz = a;
            j++;
            a++;
            if (i< Fila-1)
            {
                ListaElementos.Iterar();
            }
        }
    }
}

float CostoTotal(Registro **&Matriz,int g,int i,int j, int Fila, int Col)
{
    float parcial = 999;
    float prob = 0;        cout << "~~~~ Lista ~~~~" << endl;
        cout << endl;
    float costoaux = 0;
    for (int p = i; p<=j; p++)
    {
        prob += Matriz[p][p].costo;
    }
    for(int k=i; k<=j; k++)
    {
        costoaux = costoMin(Matriz, i,k-1,Fila,Col) + costoMin(Matriz, k+1,j,Fila,Col);
        if (costoaux<parcial)
        {
            parcial = costoaux;
            Matriz[i][j].raiz = k;
        }
    }
    costoaux = parcial + prob;
    return costoaux;
}



float costoMin(Registro **&Matriz, int i, int j, int Fila, int Col)
{
    if((i<= Fila) && (j<= Col))
    {
        if(i>j)
        {
            return 0;
        }
        else
        {
            return Matriz[i][j].costo;
        }
    }
}

void Rellenar(Registro **&Matriz, int g, int Fila, int Col)
{

    int i;
    int j = g;

    for (i=0; i<Fila-1; i++)
    {
        if (j<Col)
        {
            Matriz[i][j].costo = CostoTotal(Matriz,g,i,j,Fila,Col);
            j++;
        }
    }
}

void llenarArbol(Arbin<string> &arbol, Registro **&Matriz, Lista<string> & ListaElementos, int aux, int col,string posicion)
{
    if (col>=aux)
    {
        posicion = ListaElementos.consultarElemento(Matriz[aux][col].raiz);
        arbol.agregarElemento(posicion);
        int k = (Matriz[aux][col].raiz);
            llenarArbol(arbol,Matriz,ListaElementos,aux,k-1,posicion);
            llenarArbol(arbol,Matriz,ListaElementos,k+1,col,posicion);
    }
}

