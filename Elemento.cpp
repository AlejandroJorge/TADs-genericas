#include <iostream>
using namespace std;

void *crearElemento(int contenido)
{
  return new int(contenido);
}

void mostrarElemento(void *elemento)
{
  cout << *(int *)elemento << endl;
}

int compararElementos(void *ptrA, void *ptrB)
{
  int a = *(int *)ptrA;
  int b = *(int *)ptrB;
  return a - b;
}