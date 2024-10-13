#include "Restaurante.h"
#include "validacoes.h"

int main(void)
{
    int codigo = 0;
    int pin, op;
    char nome[20];

    Prato *raiz = NULL;
    Funcionario *tabelaHash[TAMANHODATAB];

    for (int i = 0; i < TAMANHODATAB; i++)
    {
        tabelaHash[i] = NULL;
    }

    do
    {
        printf("------------------------------- \n");
        printf("      Bem-Vindo(a)!\n");
        printf("1 - Cadastro de funcionarios \n");
        printf("2 - Pedidos \n");
        printf("3 - Estoque \n");
        printf("4 - Menu de pratos \n");
        printf("5 - Registrar ponto \n");
        printf("6 - Sair \n");
        printf("------------------------------- \n");
        printf("Escolha uma opcao: ");
        op = integerValidation();

        switch (op)
        {
        case 1:
            menuFuncionarios(tabelaHash);
            break;
        case 2:
            printf("Funcionalidade de pedidos ainda nao implementada.\n");
            break;
        case 3:
            printf("Funcionalidade de estoque ainda nao implementada.\n");
            break;
        case 4:
            pratos(&raiz, &codigo);
            break;
        case 5:
            do
            {
                printf("Nome: \n");
                scanf(" %[^\n]", nome);
            } while (stringValidation(nome));

            printf("PIN: \n");
            pin = integerValidation();
            baterPonto(tabelaHash, pin, nome);
            break;
        case 6:
            printf("Saindo...\n");
            liberarABin(raiz);
            liberarHash(tabelaHash);
            break;
        default:
            printf("Opcao invalida!\n");
        }
    } while (op != 7);

    return 0;
}
