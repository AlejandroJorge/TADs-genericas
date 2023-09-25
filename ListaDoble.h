#ifndef LISTADOBLE_H
#define LISTADOBLE_H

enum NodoLD
{
  NLD_ELEMENTO,
  NLD_ANTERIOR,
  NLD_SIGUIENTE
};

enum ListaD
{
  LD_CABEZA,
  LD_COLA,
  LD_LONGITUD
};

void *crearListaD();

void agregarElementoLD(void *lista, void *elemento);

void agregarElementoOrdenadoLD(void *lista, void *elemento, int comparar(void *a, void *b));

void mostrarListaD(void *lista, void mostrar(void *elemento));

void mostrarListaReversaD(void *lista, void mostrar(void *elemento));

void unirListasD(void *listaPrincipal, void *&listaAgregada);

#endif /*LISTADOBLE_H*/