#include "Scanner.h"
#define MAX_STR_SIZE 1024
long a;
char buf[MAX_STR_SIZE]; // 1KiB
int success; // Indicador de sucesso na conversao

long intscanner(){

    do
    {
        printf("Por favor, insira um numero inteiro: ");
        if (!fgets(buf, MAX_STR_SIZE, stdin))
        {
            // Leitura falhou:
            return -1;
        }

        // Leitura ocorreu, converter para inteiro:
        char *endptr;

        errno = 0; // reset error number
        a = strtol(buf, &endptr, 10);
        if (errno == ERANGE)
        {
            printf("Este numero eh muito grande ou muito pequeno\n");
            success = 0;
        }
        else if (endptr == buf)
        {
            // Nenhum caracter foi lido
            success = 0;
        }
        else if (*endptr && *endptr != '\n')
        {
            // *endptr is neither end of string nor newline,
            // so we didn't convert the *whole* input
            success = 0;
        }
        else
        {
            success = 1;
        }
    }	while (!success); // repeat until we got a valid number
	return a;
}