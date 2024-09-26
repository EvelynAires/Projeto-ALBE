#include "Restaurante.h"
struct Prato
{
    int codigo;
    char nome[50];
    struct Prato *esquerda;
    struct Prato *direita;
};

void menu(Prato **raiz)
{
    int op;
    do
    {
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

        switch (op)
        {
        case 5:
            pratos(raiz);
            break;
        case 7:
            liberarMemoria(*raiz);
            printf("Saindo...\n");
            break;
        default:
            printf("Tente outra opcao!\n");
        }
    } while (op != 7);
}

Prato *criarABin(int codigo, char nome[])
{
    Prato *novo = (Prato *)malloc(sizeof(Prato));
    novo->codigo = codigo;
    strcpy(novo->nome, nome);
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

Prato *inserirPrato(Prato *raiz, int codigo, char nome[])
{
    if (raiz == NULL)
    {
        return criarABin(codigo, nome);
    }
    if (codigo < raiz->codigo)
    {
        raiz->esquerda = inserirPrato(raiz->esquerda, codigo, nome);
    }
    else if (codigo > raiz->codigo)
    {
        raiz->direita = inserirPrato(raiz->direita, codigo, nome);
    }
    return raiz;
}

void exibirPratos(Prato *raiz)
{
    if (raiz != NULL)
    {
        exibirPratos(raiz->esquerda);
        printf("Prato: %s, Codigo: %d\n", raiz->nome, raiz->codigo);
        exibirPratos(raiz->direita);
    }
}

Prato *buscarPrato(Prato *raiz, int codigo)
{
    if (raiz == NULL || raiz->codigo == codigo)
    {
        return raiz;
    }
    if (codigo < raiz->codigo)
    {
        return buscarPrato(raiz->esquerda, codigo);
    }
    else
    {
        return buscarPrato(raiz->direita, codigo);
    }
}

Prato *encontrarMinimo(Prato *raiz)
{
    while (raiz->esquerda != NULL)
        raiz = raiz->esquerda;
    return raiz;
}

Prato *deletarPrato(Prato *raiz, int codigo)
{
    if (raiz == NULL)
    {
        return raiz;
    }
    if (codigo < raiz->codigo)
    {
        raiz->esquerda = deletarPrato(raiz->esquerda, codigo);
    }
    else if (codigo > raiz->codigo)
    {
        raiz->direita = deletarPrato(raiz->direita, codigo);
    }
    else
    {
        if (raiz->esquerda == NULL)
        {
            Prato *temp = raiz->direita;
            free(raiz);
            return temp;
        }
        else if (raiz->direita == NULL)
        {
            Prato *temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        Prato *temp = encontrarMinimo(raiz->direita);
        raiz->codigo = temp->codigo;
        strcpy(raiz->nome, temp->nome);
        raiz->direita = deletarPrato(raiz->direita, temp->codigo);
    }
    return raiz;
}

void alterarPrato(Prato *raiz, int codigo)
{
    if (raiz == NULL)
    {
        printf("Prato com codigo %d não encontrado.\n", codigo);
        return;
    }

    if (codigo < raiz->codigo)
    {
        alterarPrato(raiz->esquerda, codigo);
    }
    else if (codigo > raiz->codigo)
    {
        alterarPrato(raiz->direita, codigo);
    }
    else
    {
        printf("Prato encontrado: %s (Codigo: %d)\n", raiz->nome, raiz->codigo);

        char novoNome[50];
        printf("Digite o novo nome do prato: ");
        getchar();
        scanf("%[^\n]", novoNome);

        strcpy(raiz->nome, novoNome);
        printf("ALTERADO!\n");
    }
}

void pratos(Prato **raiz)
{
    int opcao, codigo;
    char nome[50];
    do
    {
        printf("\n---- Menu de Pratos ----\n");
        printf("1 - Criar um novo prato\n");
        printf("2 - Exibir todos os pratos\n");
        printf("3 - Buscar um prato\n");
        printf("4 - Deletar um prato\n");
        printf("5 - Alterar dados de um prato\n");
        printf("6 - Voltar ao menu principal\n");
        printf("------------------------\n");
        printf("Escolha uma opcao: \n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o codigo do prato: ");
            scanf("%d", &codigo);
            printf("Digite o nome do prato: ");
            getchar();
            scanf("%[^\n]", nome);
            *raiz = inserirPrato(*raiz, codigo, nome);
            printf("Prato inserido com sucesso!\n");
            break;
        case 2:
            printf("\nLista de pratos:\n");
            if (*raiz == NULL)
            {
                printf("Parece que ainda não há pratos...\n");
            }
            else
            {
                exibirPratos(*raiz);
            }
            break;
        case 3:
            printf("Digite o codigo do prato a ser buscado: ");
            scanf("%d", &codigo);
            Prato *prato = buscarPrato(*raiz, codigo);
            if (prato != NULL)
            {
                printf("Prato encontrado: %s, Codigo: %d\n", prato->nome, prato->codigo);
            }
            else
            {
                printf("Prato nao encontrado!\n");
            }
            break;
        case 4:
            printf("Digite o codigo do prato a ser deletado: ");
            scanf("%d", &codigo);
            *raiz = deletarPrato(*raiz, codigo);
            printf("Prato deletado com sucesso!\n");
            break;
        case 5:
            printf("Digite o codigo do prato: \n");
            scanf("%d", &codigo);
            alterarPrato(*raiz, codigo);
            break;
        default:
            printf("Opcao invalida!\n");
        }
    } while (opcao != 6);
    printf("Voltando ao menu principal...\n");
}

void liberarMemoria(Prato *raiz)
{
    if (raiz != NULL)
    {
        liberarMemoria(raiz->esquerda);
        liberarMemoria(raiz->direita);
        free(raiz);
    }
}
