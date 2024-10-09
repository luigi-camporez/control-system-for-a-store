#ifndef LISTACABECAUDA_H
#define LISTACABECAUDA_H
#include "Produto.h"
#include <string.h>

typedef struct noProduto {
    Produto* produto;
    struct noProduto* proximo;
} noProduto;

typedef struct {
    noProduto* cabeca;
    noProduto* cauda;
} ListaCabECauda;

ListaCabECauda* criarListaCabECauda();
void adicionarProduto(ListaCabECauda* lista, Produto* produto);
void listarProdutos(ListaCabECauda* lista);
void removerProduto(ListaCabECauda* lista, int id);
Produto* buscarProduto(ListaCabECauda* lista, int id);
void registrarVenda(ListaCabECauda* lista, int id, int qtVendida);
void editarProduto(ListaCabECauda* lista, int id, const char* novoNome, const char* novaDescricao, int novaQt);
void destruirListaCabECauda(ListaCabECauda* lista);
int estaVaziaCC(ListaCabECauda* lista);

#endif