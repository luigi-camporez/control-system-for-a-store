#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_SIZE 1024

typedef struct{
  char nome[MAX_STR_SIZE];
  int id;
}Cliente;

Cliente *criarCliente();
void setIdCliente(int maiorId);