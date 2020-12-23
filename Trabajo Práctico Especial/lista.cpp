#include "Lista.h"
#include <cstddef>
#include <stdlib.h>
#include <iostream>
using namespace std;
template<typename T>
Lista<T>::Lista()
{
    Primero=NULL;
}
template<typename T>
Lista<T>::~Lista()
{
    EliminarLista();
}

template<typename T>
void Lista<T>::agregarElementos(Nodo * & ListaElementos,const T palabra,const float costo)
{

    if((ListaElementos==NULL)||((ListaElementos->Elemento)>(palabra)))
    {
        Nodo*aux=new Nodo;
        aux->Elemento=palabra;
        aux->costo=costo;
        aux->sig=ListaElementos;
        ListaElementos=aux;
    }
    else if((ListaElementos->Elemento)<(palabra))
    {
        agregarElementos(ListaElementos->sig,palabra,costo);
    }
}

template<typename T>
float Lista<T>::getCosto()
{
    float a;
    a = Primero->costo;
    return a;
}

template<typename T>
T Lista<T>::getElemento()
{
    T a;
    a = Primero->Elemento;
    return a;
}

template<typename T>
void Lista<T>::agregarElementos(const T palabra,const float costo)
{
    agregarElementos(Primero, palabra, costo);
}

template<typename T>
int Lista<T>::CantidadELementos()
{

    int contador;
    if(Primero==NULL)
        contador=0;
    else
    {
        contador=0;
        Nodo*Aux=Primero;
        while(Aux!=NULL)
        {
            contador++;
            Aux=Aux->sig;
        }
    }
    return contador;
}

template<typename T>
void Lista<T>::EliminarLista(Nodo*& ListaElementos)
{
    if (ListaElementos->sig=NULL)
        delete  ListaElementos;
    else
        ListaElementos= ListaElementos->sig;
}
template<typename T>
void Lista<T>::EliminarLista()
{
    EliminarLista(Primero);
}

template <typename T>
void Lista<T>::Iterar()  //0(1)
{
    if(aux==NULL) //0(1)
        aux=Primero; //0(1)
    Nodo*aux2; //0(1)
    aux2=Primero; //0(1)
    if(aux2->sig!=NULL)  //0(1)
    {
        aux2=aux2->sig; //0(1)
        Primero=aux2; //0(1)
    }
    else //0(1)
        Primero=NULL; //0(1)
}

template <typename T>
T Lista<T>::consultarElemento(Nodo *& ListaElementos, int posicion)
{
    if(ListaElementos != NULL)
    {
        if(posicion == 0)
        {
            return ListaElementos->Elemento;
        }
        else
        {

            return consultarElemento(ListaElementos->sig, posicion-1);
        }
    }
}

template <typename T>
T Lista<T>::consultarElemento(int posicion)
{
    return consultarElemento(Primero,posicion);
}

template <typename T>
void Lista<T>::ImprimirLista(Nodo *& ListaElementos)
{
    if (ListaElementos != NULL)
    {
        ImprimirLista(ListaElementos->sig);
    }
}



template <typename T>
void Lista<T>::ImprimirLista()
{
    ImprimirLista(Primero);
}

template class Lista<std::string>;
