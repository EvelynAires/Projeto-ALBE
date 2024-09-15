#include <stdio.h>

void menu();

int main(void)
{
    menu();

    return 0;
}

void menu()
{
    
    int op;
    printf("------------------------------- \n");
    printf("      Bem-Vindo(a)!\n");
    printf("1 - Cadastro de funcionarios \n");
    printf("2 - Pedidos \n");
    printf("3 - Estoque \n");
    printf("4 - Reservas \n");
    printf("5 - Menu de pratos \n");
    printf("6 - Registrar ponto \n");
    printf("7 - Sair \n");
    printf("------------------------------- \n");
    printf("Escolha uma opcao: ");
    scanf("%d", &op);

}