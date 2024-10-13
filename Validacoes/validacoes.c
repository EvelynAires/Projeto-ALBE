#include "validacoes.h"

int integerValidation()
{

    int input;
    do
    {
        if ((scanf(" %d", &input)) != 1)
        {
            printf("Permitido apenas numeros\n");
            printf("Digite novamente: ");
            while (getchar() != '\n')
                ;
        }
        else
        {
            printf("\n-----------------------------\n");
            return input;
        }
    } while (1);
}

int stringValidation(char *nome)
{
    int i;
    for (i = 0; nome[i]; i++)
    {
        if (!isalpha(nome[i]) && nome[i] != ' ')
        {
            printf("O nome deve conter apenas letras.\n");
            return 1;
        }
    }
    return 0;
}