#ifndef PILA_H
#define PILA_H

enum NodoP
{
  NDP_ELEMENTO,
  NDP_SIGUIENTE
};

enum Pila
{
  PL_TOP,
};

void *crearPila();

void apilar(void *pila, void *elemento);

void *desapilar(void *pila);

void *tope(void *pila);

#endif /*PILA_H*/