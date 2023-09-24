#ifndef COLA_H
#define COLA_H

enum Cola
{
  CL_CABEZA,
  CL_COLA
};

enum NodoC
{
  NDC_ELEMENTO,
  NDC_SIGUIENTE
};

void *crearCola();

void encolar(void *cola, void *elemento);

void *desencolar(void *cola);

#endif /*COLA_H*/