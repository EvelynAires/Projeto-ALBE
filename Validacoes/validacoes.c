#include "validacoes.h"

int integerValidation() {
    char input[100];
    int isNumber = 0;

    do {
        fgets(input, 100, stdin);

        isNumber = 1;
        for (int i = 0; i < strlen(input) - 1; i++) {
            if (!isdigit(input[i])) {
                isNumber = 0;
                break;
            }
        }
        if (isNumber) {
            return atoi(input);
        } else {
            printf("Permitido apenas numeros\n");
            printf("Tente novamente: ");
        }

    } while (!isNumber);

    return 0;
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