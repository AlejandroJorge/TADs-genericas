#include "Lista.h"

void *crearLista()
{
  void **lista = new void *[3];
  lista[LI_CABEZA] = nullptr;
  lista[LI_LONGITUD] = new int(0);
  lista[LI_COLA] = nullptr;
  return lista;
}

void *crearNodo(void *elemento)
{
  void **nodo = new void *[2];
  nodo[ND_ELEMENTO] = elemento;
  nodo[ND_SIGUIENTE] = nullptr;
  return nodo;
}

void agregarElemento(void *lista, void *elemento)
{
  void **auxLista = (void **)lista;
  void **auxNodo = (void **)auxLista[LI_COLA];

  void **nuevoNodo = (void **)crearNodo(elemento);

  if (auxNodo == nullptr)
  {
    auxLista[LI_CABEZA] = nuevoNodo;
    auxLista[LI_COLA] = nuevoNodo;
  }
  else
  {
    auxNodo[ND_SIGUIENTE] = nuevoNodo;
    auxLista[LI_COLA] = nuevoNodo;
  }

  ++*(int *)auxLista[LI_LONGITUD];
}

void agregarElementoOrdenado(void *lista, void *elemento, int comparar(void *a, void *b))
{
  void **auxLista = (void **)lista;
  void **auxNodo = (void **)auxLista[LI_CABEZA];

  void **nuevoNodo = (void **)crearNodo(elemento);

  if (auxNodo == nullptr)
  {
    auxLista[LI_CABEZA] = nuevoNodo;
    auxLista[LI_COLA] = nuevoNodo;
  }
  else
  {
    void **prevNodo = nullptr;
    while (auxNodo)
    {
      if (comparar(auxNodo[ND_ELEMENTO], nuevoNodo[ND_ELEMENTO]) > 0)
        break;
      prevNodo = auxNodo;
      auxNodo = (void **)auxNodo[ND_SIGUIENTE];
    }

    nuevoNodo[ND_SIGUIENTE] = auxNodo;

    if (prevNodo == nullptr)
      auxLista[LI_CABEZA] = nuevoNodo;
    else
      prevNodo[ND_SIGUIENTE] = nuevoNodo;

    if (auxNodo == nullptr)
      auxLista[LI_COLA] = nuevoNodo;
  }

  ++*(int *)auxLista[LI_LONGITUD];
}

void mostrarLista(void *lista, void mostrar(void *elemento))
{
  void **auxLista = (void **)lista;
  void **auxNodo = (void **)auxLista[LI_CABEZA];
  while (auxNodo)
  {
    mostrar(auxNodo[ND_ELEMENTO]);
    auxNodo = (void **)auxNodo[ND_SIGUIENTE];
  }
}

void unirListas(void *listaPrincipal, void *&listaAgregada)
{
  void **auxLPrincipal = (void **)listaPrincipal;
  void **auxLAgregada = (void **)listaAgregada;

  void **cola = (void **)auxLPrincipal[LI_COLA];

  *(int *)auxLPrincipal[LI_LONGITUD] += *(int *)auxLAgregada[LI_LONGITUD];

  if (cola != nullptr)
    cola[ND_SIGUIENTE] = auxLAgregada[LI_CABEZA];
  else
    auxLPrincipal[LI_CABEZA] = auxLAgregada[LI_CABEZA];

  delete auxLAgregada;
}