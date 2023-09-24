#include "Pila.h"

void *crearPila()
{
  void **pila = new void *[1];
  pila[PL_TOP] = nullptr;
  return pila;
}

void *crearNodoPila(void *elemento, void *sig)
{
  void **nodoPila = new void *[2];
  nodoPila[NDP_ELEMENTO] = elemento;
  nodoPila[NDP_SIGUIENTE] = sig;
  return nodoPila;
}

void apilar(void *pila, void *elemento)
{
  void **auxPila = (void **)pila;
  void **tope = (void **)auxPila[PL_TOP];
  void **nuevoNodo = (void **)crearNodoPila(elemento, tope);
  auxPila[PL_TOP] = nuevoNodo;
}

void *desapilar(void *pila)
{
  void **auxPila = (void **)pila;
  void **tope = (void **)auxPila[PL_TOP];
  void *elemento = tope[NDP_ELEMENTO];
  auxPila[PL_TOP] = tope[NDP_SIGUIENTE];
  delete tope;

  return elemento;
}

void *tope(void *pila)
{
  void **auxPila = (void **)pila;
  void **tope = (void **)auxPila[PL_TOP];
  void *elemento = tope[NDP_ELEMENTO];
  return elemento;
}