#ifndef LISTA_H
#define LISTA_H

enum Nodo
{
  ND_ELEMENTO,
  ND_SIGUIENTE
};

enum Lista
{
  LI_CABEZA,
  LI_COLA,
  LI_LONGITUD
};

void *crearLista();

void agregarElemento(void *lista, void *elemento);

void agregarElementoOrdenado(void *lista, void *elemento, int comparar(void *a, void *b));

void mostrarLista(void *lista, void mostrar(void *elemento));

void unirListas(void *listaPrincipal, void *&listaAgregada);

#endif /*LISTA_H*/