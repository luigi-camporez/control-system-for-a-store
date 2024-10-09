#ifndef PRODUTO_H
#define PRODUTO_H

#define MAX_STR_SIZE 1024

typedef struct Produto {
    int id;
    char nome[MAX_STR_SIZE];
    char descricao[MAX_STR_SIZE];
    int quantidade;
} Produto;

void setIdProduto(int maiorId2);
Produto* criarProdutoArq(int id, const char* nome, const char* descricao, int quantidade);
Produto* criarProduto(const char* nome, const char* descricao, int quantidade);
void imprimirProduto(const Produto* produto);
void destruirProduto(Produto* produto);

#endif