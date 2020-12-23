#ifndef LISTA_H
#define LISTA_H
/*Una lista es una secuencia de cero o más elementos, los cuales pueden ser agregados, eliminados y
accedidos de manera flexible */
template<typename T>

class Lista
{
public:
    Lista();
    ~Lista();
    int CantidadELementos();
    float getCosto();
    T getElemento();
    void ImprimirLista();
    void EliminarLista();
    void agregarElementos(const T palabra,const float costo);
    T consultarElemento(int posicion);
    void Iterar();
private:
    struct Nodo
    {
        T Elemento;
        float costo;
        Nodo*sig;
    };
    Nodo*Primero;
    Nodo*aux;
    void EliminarLista(Nodo *& ListaElementos);
    void agregarElementos(Nodo*& ListaElementos,const T palabra,const float costo);
    T consultarElemento(Nodo *& ListaElementos, int posicion);
    void ImprimirLista(Nodo *& ListaElementos);

};

#endif // LISTA_H

