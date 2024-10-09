#include "Cliente.h"

typedef struct nolista {
  Cliente info;
  struct nolista *prox;
}NoLista;

int estaVazia(NoLista** l);
void insereOrdenado(NoLista** l, Cliente v);
void imprimeElementos(NoLista **l);
void ordenarListaEncadeada(NoLista **l);
void removerCliente(NoLista **l, char *str);
