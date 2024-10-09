#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Produto.h"

int idProduto;

void setIdProduto(int maiorId2){
	idProduto = maiorId2+1;
}

Produto* criarProdutoArq(int id, const char* nome, const char* descricao, int quantidade) {
    Produto* novoProduto = (Produto*)malloc(sizeof(Produto));
    if (novoProduto) {
        novoProduto->id = id;
        strncpy(novoProduto->nome, nome, sizeof(novoProduto->nome));
		novoProduto->nome[strcspn(novoProduto->nome, "\n")] = 0;
        strncpy(novoProduto->descricao, descricao, sizeof(novoProduto->descricao));
		novoProduto->descricao[strcspn(novoProduto->descricao, "\n")] = 0;
        novoProduto->quantidade = quantidade;
    }
    return novoProduto;
}

Produto* criarProduto(const char* nome, const char* descricao, int quantidade) {
    Produto* novoProduto = (Produto*)malloc(sizeof(Produto));
    if (novoProduto) {
        novoProduto->id = idProduto;
        strncpy(novoProduto->nome, nome, sizeof(novoProduto->nome));
		novoProduto->nome[strcspn(novoProduto->nome, "\n")] = 0;
        strncpy(novoProduto->descricao, descricao, sizeof(novoProduto->descricao));
		novoProduto->descricao[strcspn(novoProduto->descricao, "\n")] = 0;
        novoProduto->quantidade = quantidade;
		idProduto++;
    }
    return novoProduto;
}

void imprimirProduto(const Produto* produto) {
    if (produto) {
        printf("ID: %d, Nome: %s, Descricao: %s, Estoque: %d\n",
               produto->id, produto->nome, produto->descricao, produto->quantidade);
    }
}

void destruirProduto(Produto* produto) {
    free(produto);
}