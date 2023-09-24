#include "ArbolBinario.h"
#include <iostream>
using namespace std;

void *crearArbol()
{
  void *arbol = nullptr;
  return arbol;
}

void *crearNodoArbol(void *elemento)
{
  void **nodo = new void *[3];
  nodo[AB_ELEMENTO] = elemento;
  nodo[AB_DERECHA] = nullptr;
  nodo[AB_IZQUIERDA] = nullptr;
  return nodo;
}

void agregarElementoArbol(void *&arbol, void *elemento, int comparar(void *a, void *b))
{
  if (arbol == nullptr)
  {
    void **nuevoNodo = (void **)crearNodoArbol(elemento);
    arbol = nuevoNodo;
    return;
  }
  void **nodoActual = (void **)arbol;
  int comparacion = comparar(elemento, nodoActual[AB_ELEMENTO]);
  if (comparacion > 0)
  {
    if (nodoActual[AB_DERECHA] == nullptr)
      nodoActual[AB_DERECHA] = crearNodoArbol(elemento);
    else
      agregarElementoArbol(nodoActual[AB_DERECHA], elemento, comparar);
  }
  else
  {
    if (nodoActual[AB_IZQUIERDA] == nullptr)
      nodoActual[AB_IZQUIERDA] = crearNodoArbol(elemento);
    else
      agregarElementoArbol(nodoActual[AB_IZQUIERDA], elemento, comparar);
  }
}

void recorrerOrden(void *arbol, void operacion(void *elemento))
{
  if (arbol == nullptr)
    return;
  void **aux = (void **)arbol;
  recorrerOrden(aux[AB_IZQUIERDA], operacion);
  operacion(aux[AB_ELEMENTO]);
  recorrerOrden(aux[AB_DERECHA], operacion);
}

void recorrerPreOrden(void *arbol, void operacion(void *elemento))
{
  if (arbol == nullptr)
    return;
  void **aux = (void **)arbol;
  operacion(aux[AB_ELEMENTO]);
  recorrerPreOrden(aux[AB_IZQUIERDA], operacion);
  recorrerPreOrden(aux[AB_DERECHA], operacion);
}

void recorrerPostOrden(void *arbol, void operacion(void *elemento))
{
  if (arbol == nullptr)
    return;
  void **aux = (void **)arbol;
  recorrerPostOrden(aux[AB_IZQUIERDA], operacion);
  recorrerPostOrden(aux[AB_DERECHA], operacion);
  operacion(aux[AB_ELEMENTO]);
}
