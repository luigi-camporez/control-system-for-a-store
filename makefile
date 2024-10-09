all: compila
compila: main.o Cliente.o Produto.o ListaEncadeada.o ListaCabECauda.o Scanner.o
	gcc main.o Cliente.o Produto.o ListaEncadeada.o ListaCabECauda.o Scanner.o -o prog
main.o: main.c
	gcc -c main.c
Cliente.o: Cliente.c
	gcc -c Cliente.c
Produto.o: Produto.c
	gcc -c Produto.c
ListaEncadeada.o: ListaEncadeada.c
	gcc -c ListaEncadeada.c
ListaCabECauda.o: ListaCabECauda.c
	gcc -c ListaCabECauda.c
Scanner.o: Scanner.c
	gcc -c Scanner.c
clean:
	del main.o Cliente.o Produto.o ListaEncadeada.o ListaCabECauda.o Scanner.o prog.exe