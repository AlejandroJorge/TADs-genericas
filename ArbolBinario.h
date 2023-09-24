#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

enum Arbol
{
  AB_ELEMENTO,
  AB_IZQUIERDA,
  AB_DERECHA
};

void *crearArbol();

void agregarElementoArbol(void *&arbol, void *elemento, int comparar(void *a, void *b));

void recorrerOrden(void *arbol, void operacion(void *elemento));

void recorrerPreOrden(void *arbol, void operacion(void *elemento));

void recorrerPostOrden(void *arbol, void operacion(void *elemento));

#endif /*ARBOLBINARIO_H*/