#include <stdio.h>
#include <stdlib.h>
#include "ListaCabECauda.h"

ListaCabECauda* criarListaCabECauda() {
    ListaCabECauda* lista = (ListaCabECauda*)malloc(sizeof(ListaCabECauda));
    if (lista) {
        lista->cabeca = NULL;
        lista->cauda = NULL;
    }
    return lista;
}

void adicionarProduto(ListaCabECauda* lista, Produto* produto) {
    noProduto* novoNodo = (noProduto*)malloc(sizeof(noProduto));
    if (novoNodo) {
        novoNodo->produto = produto;
        novoNodo->proximo = NULL;
        if (lista->cauda) {
            lista->cauda->proximo = novoNodo;
        } else {
            lista->cabeca = novoNodo;
        }
        lista->cauda = novoNodo;
    }
}

void listarProdutos(ListaCabECauda* lista) {
    noProduto* atual = lista->cabeca;
		printf("\n----------Produtos Registrados----------\n");
    while (atual) {
        imprimirProduto(atual->produto);
        atual = atual->proximo;
    }
		printf("\n----------------------------------------");
}

void removerProduto(ListaCabECauda* lista, int id) {
    noProduto* atual = lista->cabeca;
    noProduto* anterior = NULL;

    while (atual) {
        if (atual->produto->id == id) {
            if (anterior) {
                anterior->proximo = atual->proximo;
            } else {
                lista->cabeca = atual->proximo;
            }
            if (atual == lista->cauda) {
                lista->cauda = anterior;
            }
            destruirProduto(atual->produto);
            free(atual);
            printf("--Produto removido com sucesso.\n");
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    printf("--Produto com ID %d não encontrado.\n", id);
}

Produto* buscarProduto(ListaCabECauda* lista, int id) {
    noProduto* atual = lista->cabeca;
    while (atual) {
        if (atual->produto->id == id) {
            return atual->produto;
        }
        atual = atual->proximo;
    }
    return NULL; 
}

void registrarVenda(ListaCabECauda* lista, int id, int qtVendida) {
    Produto* produto = buscarProduto(lista, id);
    if (produto) {
        if (produto->quantidade >= qtVendida) {
            produto->quantidade -= qtVendida;
            printf("--Venda registrada com sucesso!\n");
            imprimirProduto(produto);
        } else {
            printf("--Estoque insuficiente para a venda. Quantidade disponivel: %d\n", produto->quantidade);
        }
    } else {
        printf("--Produto com ID %d nao encontrado.\n", id);
    }
}

void editarProduto(ListaCabECauda* lista, int id, const char* novoNome, const char* novaDescricao, int novaQt) {
    Produto* produto = buscarProduto(lista, id);
    if (produto) {
        strncpy(produto->nome, novoNome, sizeof(produto->nome));
        strncpy(produto->descricao, novaDescricao, sizeof(produto->descricao));
        produto->quantidade = novaQt;
        printf("--Produto editado com sucesso!\n");
        imprimirProduto(produto);
    } else {
        printf("--Produto com ID %d nao encontrado.\n", id);
    }
}

void destruirListaCabECauda(ListaCabECauda* lista) {
    noProduto* atual = lista->cabeca;
    while (atual) {
        noProduto* proximo = atual->proximo;
        destruirProduto(atual->produto);
        free(atual);
        atual = proximo;
    }
    free(lista);
}

int estaVaziaCC(ListaCabECauda* lista){
	return(lista->cabeca==NULL);
}