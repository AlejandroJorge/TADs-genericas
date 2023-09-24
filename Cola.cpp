#include "Cola.h"

void *crearCola()
{
  void **cola = new void *[2];
  cola[CL_CABEZA] = nullptr;
  cola[CL_COLA] = nullptr;
  return cola;
}

void *crearNodoCola(void *elemento, void *sig)
{
  void **nodoCola = new void *[2];
  nodoCola[NDC_ELEMENTO] = elemento;
  nodoCola[NDC_SIGUIENTE] = sig;

  return nodoCola;
}

void encolar(void *cola, void *elemento)
{
  void **auxCola = (void **)cola;
  void **nuevoNodo = (void **)crearNodoCola(elemento, nullptr);
  void **nodoFinal = (void **)auxCola[CL_COLA];
  if (nodoFinal == nullptr)
  {
    auxCola[CL_CABEZA] = nuevoNodo;
    auxCola[CL_COLA] = nuevoNodo;
  }
  else
    nodoFinal[NDC_SIGUIENTE] = nuevoNodo;
  auxCola[CL_COLA] = nuevoNodo;
}

void *desencolar(void *cola)
{
  void **auxCola = (void **)cola;
  void **primerNodo = (void **)auxCola[CL_CABEZA];
  void *elemento = primerNodo[NDC_ELEMENTO];
  auxCola[CL_CABEZA] = primerNodo[NDC_SIGUIENTE];
  delete primerNodo;

  return elemento;
}