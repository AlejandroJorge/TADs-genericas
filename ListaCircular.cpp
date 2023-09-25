#include "ListaCircular.h"

void *crearListaC()
{
  void **lista = new void *[3];
  lista[LC_CABEZA] = nullptr;
  lista[LC_COLA] = nullptr;
  lista[LC_LONGITUD] = new int(0);
  return lista;
}

void *crearNodoLC(void *elemento)
{
  void **nodo = new void *[2];
  nodo[NLC_ELEMENTO] = elemento;
  nodo[NLC_SIGUIENTE] = nullptr;
  return nodo;
}

void agregarElementoLC(void *lista, void *elemento)
{
  void **nuevoNodo = (void **)crearNodoLC(elemento);
  void **auxLista = (void **)lista;
  void **auxNodoFinal = (void **)auxLista[LC_COLA];
  if (auxNodoFinal == nullptr)
  {
    auxLista[LC_CABEZA] = nuevoNodo;
    auxLista[LC_COLA] = nuevoNodo;
    nuevoNodo[NLC_SIGUIENTE] = nuevoNodo;
  }
  else
  {
    auxLista[LC_COLA] = nuevoNodo;
    auxNodoFinal[NLC_SIGUIENTE] = nuevoNodo;
    nuevoNodo[NLC_SIGUIENTE] = auxLista[LC_CABEZA];
  }
  ++*(int *)auxLista[LC_LONGITUD];
}

void mostrarListaC(void *lista, void mostrar(void *elemento))
{
  void **auxLista = (void **)lista;
  void **auxNodo = (void **)auxLista[LC_CABEZA];
  int len = *(int *)auxLista[LC_LONGITUD];
  for (int i = 0; i < len; i++)
  {
    mostrar(auxNodo[NLC_ELEMENTO]);
    auxNodo = (void **)auxNodo[NLC_SIGUIENTE];
  }
}
