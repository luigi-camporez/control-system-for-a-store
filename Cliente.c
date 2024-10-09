#include "Cliente.h"

int idCliente;

void setIdCliente(int maiorId){
	idCliente = maiorId+1;
}

Cliente *criarCliente() {
	Cliente *novoCliente = (Cliente *)malloc(sizeof(Cliente));
	if (novoCliente != NULL) {
		printf("\nDigite o nome do cliente:\n");
		fgets(novoCliente->nome, MAX_STR_SIZE, stdin);
		novoCliente->nome[strcspn(novoCliente->nome, "\n")] = 0;
		novoCliente->id = idCliente;
		idCliente++;
		printf("\n--Cliente cadastrado com sucesso!");
		return novoCliente;
	}else{
		printf("--Ouve um erro ao alocar memoria!");
		return NULL;
  }
}



