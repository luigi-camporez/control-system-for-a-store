#include "ListaEncadeada.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_SIZE 1024

int estaVazia(NoLista** l){
	return (*l==NULL);
}

void ordenarListaEncadeada(NoLista **l) {
    NoLista *i, *j;
    char temp[MAX_STR_SIZE];
	int temp2;

    // Loop externo para percorrer a lista
    for (i = *l; i != NULL && i->prox != NULL; i = i->prox) {
        // Loop interno para comparar os nós subsequentes
        for (j = i->prox; j != NULL; j = j->prox) {
            if (strcmp(i->info.nome, j->info.nome) > 0) {
                // Trocar os valores dos nós
                strcpy(temp, i->info.nome);
				temp2=i->info.id;
                strcpy(i->info.nome, j->info.nome);
				i->info.id=j->info.id;
                strcpy(j->info.nome, temp);
				j->info.id=temp2;
            }
        }
    }
}

void insereOrdenado(NoLista** l, Cliente v){
	NoLista* novo = malloc(sizeof(NoLista));
	if(novo!=NULL){
		novo->info = v;
		novo->prox = *l;	
		*l = novo;
		ordenarListaEncadeada(l);
	}
	else{
		printf("--Não foi possível alocar espaço!");
		exit(1);
	}
}

void imprimeElementos(NoLista **l) {
	NoLista *p;
	printf("\n----------Clientes Registrados----------");
	printf("\n\n(ID - Nome)\n");
	for (p = *l; p != NULL; p = p->prox) {
		printf("\n%d - %s", p->info.id, p->info.nome);
	}
	printf("\n----------------------------------------\n");
}

void removerCliente(NoLista **l, char *str){
	NoLista *aux, *remover = NULL;
	if(strcmp((*l)->info.nome, str)==0){
		remover = *l;
		*l = remover->prox;
		printf("\n--Cliente removido com sucesso!");
	}
	else{//Elemento não está no início
		aux = *l;
		while(aux->prox && strcmp(aux->prox->info.nome, str)!=0)
			aux=aux->prox;
		if(aux->prox){//Se (aux->prox) existe, então a quebra do loop while se deu pois encontrou-se o elemento a ser removido
			remover = aux->prox;
			aux->prox = remover->prox;
			printf("\n--Cliente removido com sucesso!");
			free(remover);
		}else{
			printf("\n--Cliente nao encontrado");
		}		
	}
}