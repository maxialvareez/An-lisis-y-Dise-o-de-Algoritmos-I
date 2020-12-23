#include <cstddef>
#include "Arbin.h"
#include <string>
#include<iostream>
using namespace std;

template <typename T>
Arbin<T>::Arbin()
{
    arbol = NULL;
}

template <typename T>
void Arbin<T>::destruirArbol(NodoArbin *arbol)
{
    if (arbol!=NULL)
    {
        destruirArbol(arbol->izq);
        destruirArbol(arbol->der);
        delete arbol;
    }
}

template <typename T>
Arbin<T>::~Arbin()
{
    destruirArbol(arbol);
}


template <typename T>
void Arbin<T>::agregarElemento(NodoArbin *&arbol,const T &elem)
{
    if(arbol==NULL)
    {
        NodoArbin * aux = new NodoArbin;
        aux->elemento = elem;
        aux->izq = NULL;
        aux->der = NULL;
        arbol = aux;
    }
    else if (arbol->elemento > elem){
        agregarElemento(arbol->izq, elem);
    }
    else if (arbol->elemento < elem){
        agregarElemento(arbol->der, elem);
    }
}

template <typename T>
void Arbin<T>::agregarElemento(const T &elem)
{
    agregarElemento(arbol,elem);
}

template <typename T>
bool Arbin<T>::perteneceElemento(NodoArbin *&arbol, const T & elem, float & costo)
{
    if(arbol!=NULL)
    {
        costo++;
        if(arbol->elemento == elem)
        {
            return true;
        }
        else if(arbol->elemento > elem)
        {
            return perteneceElemento(arbol->izq,elem,costo);
        }
        else
        {
            return perteneceElemento(arbol->der,elem,costo);
        }
    }

    else
    {
        return false;
    }
}


template <typename T>
bool Arbin<T>::perteneceElemento(const T &elem, float & costo)
{
    return perteneceElemento(arbol,elem,costo);
}

template <typename T>
unsigned int Arbin<T>::cantElementos(NodoArbin*arbol,int & contador)
{
    if(arbol!= NULL)
    {
        contador++;
        cantElementos(arbol->izq,contador);
        cantElementos(arbol->der,contador);
        return contador;
    }
    else
    {
        return contador;
    }
}

template <typename T>
unsigned int Arbin<T>::cantElementos()
{
    int contador = 0;
    return cantElementos(arbol,contador);
}

template <typename T>
bool Arbin<T>::estaVacia()
{
    if (arbol!=NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}

template <typename T>
void Arbin<T>::inOrden(NodoArbin *arbol)
{
    if(arbol!= NULL)
    {
        cout << (arbol->elemento) <<endl;
        inOrden(arbol->izq);
        inOrden(arbol->der);
    }
}

template <typename T>
void Arbin<T>::inOrden()
{
    if(arbol == NULL)
        cout<<"El arbol esta vacio"<<endl;
    else
        inOrden(arbol);
}

template class Arbin<std::string>;

