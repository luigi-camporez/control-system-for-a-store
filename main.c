#include "ListaEncadeada.h"
#include "ListaCabECauda.h"
#include "Scanner.h"
#include <string.h>
#include "Produto.h"
#include <stdio.h>

#define MAX_STR_SIZE 1024

int main(int argc, char *argv[]){
	
	int opcao, id, quantidade, qtVendida;//Variaveis basicas para o funcionamento do menu e suas funcoes
	
	char nome[MAX_STR_SIZE], descricao[MAX_STR_SIZE];//Variaveis para insercao
	
	char V = 186; //Tabela ASCII
	
	NoLista *li = NULL;
	
	Cliente* novo = NULL;
	
	ListaCabECauda *listaProdutos = criarListaCabECauda();
	
	//-----------------------------------------------------------------------------------------------------------Arquivos
	
	FILE* ArqClientes = fopen("clientes.txt", "r");
	FILE* ArqProdutos = fopen("produtos.txt", "r");
	
	int tempId=0, maiorId=0, maiorId2=0, tempEstoq=0;
	
	char tempNome[MAX_STR_SIZE], tempDesc[MAX_STR_SIZE];
	
	if(ArqClientes!=NULL){		
		while(fscanf(ArqClientes,"%d - %[^\n]", &tempId, tempNome)==2){//Leitura do arquivo de clientes	
			Cliente *novoCliente = (Cliente *)malloc(sizeof(Cliente));
			if (novoCliente != NULL) {
				novoCliente->id = tempId;
				strcpy(novoCliente->nome, tempNome);
				insereOrdenado(&li, *novoCliente); //Insere o cliente criado com base no arquivo para a lista encadeada
				if(maiorId < tempId)
					maiorId = tempId;
			}else{
				printf("--Ouve um erro ao alocar memoria!");
				return 0;
			}
		}
		setIdCliente(maiorId); // Envia o maior ID lido na arquivo para fazer a insercao dos novos clientes corretamente
	}else{
		printf("\nNao foi possivel abrir o arquivo");
		return 0;
	}

	fclose(ArqClientes);
	//------------------------------------------------------------------------------------------------------------------
	
	if(ArqProdutos!=NULL){
		while(fscanf(ArqProdutos,"ID: %d, Nome: %[^,], Descricao: %[^,], Estoque: %d\n", &tempId, tempNome, tempDesc, &tempEstoq)==4){
			
			Produto* novoProduto = (Produto*)malloc(sizeof(Produto));
			
			if(novoProduto){
				novoProduto->id = tempId;
				strcpy(novoProduto->nome, tempNome);
				strcpy(novoProduto->descricao, tempDesc);
				novoProduto->quantidade = tempEstoq;
				adicionarProduto(listaProdutos, novoProduto);
				if(maiorId2 < tempId)
					maiorId2 = tempId;
			}else{
				printf("--Ouve um erro ao alocar memoria!");
				return 0;
			}			
		}
		setIdProduto(maiorId2);
	}else{
		printf("\nNao foi possivel abrir o arquivo");
		return 0;
	}
	
	fclose(ArqProdutos);
	
	do{
	//------------------------IMPRESSAO DO MENU--------------------------------	
		printf("\n\n%c", 201);
		for(int i = 0; i<15; i++)
			printf("%c", 205);
		printf(" MENU ");
		for(int i = 0; i<15; i++)
			printf("%c", 205);
		printf("%c\n", 187);
		printf("%c 1 - Cadastrar novo cliente         %c\n", V, V);
		printf("%c 2 - Remover Cliente                %c\n", V, V);
		printf("%c 3 - Imprimir lista de clientes     %c\n", V, V);
		printf("%c 4 - Cadastrar novo produto         %c\n", V, V);
		printf("%c 5 - Remover Produtos               %c\n", V, V);
		printf("%c 6 - Imprimir lista de produtos     %c\n", V, V);
		printf("%c 7 - Editar descricao dos produtos  %c\n", V, V);
		printf("%c 8 - Registrar venda                %c\n", V, V);
		printf("%c 9 - Sair                           %c\n", V, V);
		printf("%c Escolha uma opcao:                 %c\n", V, V);
		printf("%c", 200);
		for(int i = 0; i<36; i++)
			printf("%c", 205);
		printf("%c\n", 188);

	//-------------------------------------------------------------------------
	opcao = intscanner();
		switch(opcao){
			case 1:	
				novo = criarCliente();
				insereOrdenado(&li, *novo);
				
				break;
			case 2:
				if(!estaVazia(&li)){
					printf("\nDigite o nome do cliente a ser removido\n");
					fgets(nome, MAX_STR_SIZE, stdin);
					nome[strcspn(nome, "\n")] = 0;
					removerCliente(&li, nome);	
				}else{printf("\n--Nao ha clientes registrados");}				
				break;	
					
			case 3:
				if(!estaVazia(&li)){
					imprimeElementos(&li);
				}else{printf("\n--Nao ha clientes registrados");}		
				break;
				
			case 4:
				printf("Digite o nome do produto: ");
				fgets(nome, MAX_STR_SIZE, stdin);
				nome[strcspn(nome, "\n")] = 0;
				
				printf("Digite a descricao do produto: ");
				fgets(descricao, MAX_STR_SIZE, stdin);
				descricao[strcspn(descricao, "\n")] = 0;
				
				printf("Digite a quantidade em estoque: \n");
				quantidade = intscanner();
				
				Produto *novoProduto = criarProduto(nome, descricao, quantidade);
				adicionarProduto(listaProdutos, novoProduto);
				
				printf("--Produto cadastrado com sucesso!\n");
				break;

			case 5:
				if(!estaVaziaCC(listaProdutos)){
					printf("Digite o ID do produto a remover: \n");
					id = intscanner();
					removerProduto(listaProdutos, id);
				}else{printf("\n--Nao ha produtos registrados");}
					
				break;

			case 6:
				if(!estaVaziaCC(listaProdutos)){
					listarProdutos(listaProdutos);
				}else{printf("\n--Nao ha produtos registrados");}
				break;

			case 7:
				if(!estaVaziaCC(listaProdutos)){
					printf("Digite o ID do produto a editar: \n");
					id = intscanner();
				
					printf("Digite o novo nome do produto: ");	
					fgets(nome, MAX_STR_SIZE, stdin);
					nome[strcspn(nome, "\n")] = 0;
				
					printf("Digite a nova descricao do produto: ");	
					fgets(descricao, MAX_STR_SIZE, stdin);
					descricao[strcspn(descricao, "\n")] = 0;
				
					printf("Digite a nova quantidade em estoque: \n");
					quantidade = intscanner();
				
					editarProduto(listaProdutos, id, nome, descricao, quantidade);
				}else{printf("\n--Nao ha produtos registrados");}
				break;

			case 8:
				if(!estaVaziaCC(listaProdutos)){
					printf("Digite o ID do produto para registrar a venda: ");
					id = intscanner();
					printf("Digite a quantidade vendida: ");
					qtVendida = intscanner();
					registrarVenda(listaProdutos, id, qtVendida);
				}else{printf("\n--Nao ha produtos registrados");}
				break;
					
			case 9:
				
				ArqClientes = fopen("clientes.txt", "w");
				for (NoLista* p = li; p != NULL; p = p->prox) {
					fprintf(ArqClientes, "%d - %s\n", p->info.id, p->info.nome);
				}
				
				ArqProdutos = fopen("produtos.txt", "w");
				for (noProduto* p = listaProdutos->cabeca; p !=NULL; p = p->proximo) {
					fprintf(ArqProdutos, "ID: %d, Nome: %s, Descricao: %s, Estoque: %d\n", p->produto->id, p->produto->nome, p->produto->descricao, p->produto->quantidade);
				}
				
				printf("--Saindo do programa.\n");
				fclose(ArqClientes);
				fclose(ArqProdutos);
				break;	
					
			default:
				if(opcao!=9)
					printf("--Opcao invalida. Tente novamente.\n");
		}
	}while(opcao!=9);
				
	destruirListaCabECauda(listaProdutos);		
		
	return 0;
}