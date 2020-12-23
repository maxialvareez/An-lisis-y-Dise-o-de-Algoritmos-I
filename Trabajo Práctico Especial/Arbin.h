#ifndef ARBIN_H_INCLUDED
#define ARBIN_H_INCLUDED

template <typename T>
class Arbin
{
public:
    Arbin();
    ~Arbin();
    void agregarElemento(const T &elem);
    bool perteneceElemento(const T &elem, float & costo);
    unsigned int cantElementos();
    bool estaVacia();
    void inOrden();
    void destruirArbol();

private:
    struct NodoArbin
    {
        T elemento;
        NodoArbin *izq;
        NodoArbin *der;
    };
    NodoArbin *arbol;
    void agregarElemento(NodoArbin * & arbol,const T & elem);
    bool perteneceElemento(NodoArbin *&arbol, const T & elem, float & costo);
    unsigned int cantElementos(NodoArbin *arbol,int &contador);
    void inOrden(NodoArbin *arbol);
    void destruirArbol(NodoArbin *arbol);

};

#endif

