#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H

enum NodoLC
{
  NLC_ELEMENTO,
  NLC_SIGUIENTE
};

enum ListaC
{
  LC_CABEZA,
  LC_COLA,
  LC_LONGITUD
};

void *crearListaC();

void agregarElementoLC(void *lista, void *elemento);

void agregarElementoOrdenadoLC(void *lista, void *elemento, int comparar(void *a, void *b));

void mostrarListaC(void *lista, void mostrar(void *elemento));

void unirListasC(void *listaPrincipal, void *&listaAgregada);

#endif /*LISTACIRCULAR_H*/