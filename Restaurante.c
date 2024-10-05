#include "Restaurante.h"
struct Prato
{
    int codigo;
    char nome[50];
    struct Prato *esquerda;
    struct Prato *direita;
};

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

void menu(Prato **raiz, int *codigo)
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
        op = integerValidation();

        switch (op)
        {
        case 5:
            pratos(raiz, codigo);
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

    if (strcmp(nome, raiz->nome) < 0)
    {
        raiz->esquerda = inserirPrato(raiz->esquerda, codigo, nome);
    }
    else if (strcmp(nome, raiz->nome) > 0)
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

Prato *buscarPrato(Prato *raiz, char *nome)
{
    if (raiz == NULL || strcmp(raiz->nome, nome) == 0)
    {
        return raiz;
    }

    if (strcmp(nome, raiz->nome) < 0)
    {
        return buscarPrato(raiz->esquerda, nome);
    }
    else
    {
        return buscarPrato(raiz->direita, nome);
    }
}

Prato *encontrarMinimo(Prato *raiz)
{
    while (raiz->esquerda != NULL)
        raiz = raiz->esquerda;
    return raiz;
}

Prato *deletarPrato(Prato *raiz, char *nome)
{
    if (raiz == NULL)
    {
        printf("prato nao encontrado :(\n");
        return raiz;
    }

    if (strcmp(nome, raiz->nome) < 0)
    {
        raiz->esquerda = deletarPrato(raiz->esquerda, nome);
    }
    else if (strcmp(nome, raiz->nome) > 0)
    {
        raiz->direita = deletarPrato(raiz->direita, nome);
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
        strcpy(raiz->nome, temp->nome);
        raiz->codigo = temp->codigo;
        raiz->direita = deletarPrato(raiz->direita, temp->nome);
    }
    printf("Prato deletado!\n");
    return raiz;
}

void alterarPrato(Prato **raiz, char *nome){
    if (*raiz == NULL)
    {
        printf("Prato nao encontrado.\n");
        return;
    }

    Prato *prato = buscarPrato(*raiz, nome);

    if (prato == NULL)
    {
        printf("Prato nao encontrado.\n");
        return;
    }

    printf("Prato encontrado: %s (Codigo: %d)\n", prato->nome, prato->codigo);

    char novoNome[50];
    do
    {
        printf("Digite o novo nome do prato: ");
        getchar();
        scanf("%[^\n]", novoNome);
    } while (stringValidation(novoNome));

    int codigoPrato = prato->codigo;

    *raiz = deletarPrato(*raiz, nome);

    *raiz = inserirPrato(*raiz, codigoPrato, novoNome);

    printf("Prato alterado e reposicionado na arvore!\n");
}

void pratos(Prato **raiz, int *codigo)
{
    int opcao;
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
        opcao = integerValidation();

        switch (opcao)
        {
        case 1:
            do
            {
                printf("Digite o nome do prato: ");
                getchar();
                scanf("%[^\n]", nome);
            } while (stringValidation(nome));
            if (verificarExis(*raiz, nome))
            {
                printf("O prato já existe!\n");
            }
            else
            {
                (*codigo)++;
                *raiz = inserirPrato(*raiz, *codigo, nome);
                printf("Prato inserido com sucesso!\n");
            }
            break;
        case 2:
            printf("\nLista de pratos:\n");
            if (*raiz == NULL)
            {
                printf("Parece que ainda nao ha pratos...\n");
            }
            else
            {
                exibirPratos(*raiz);
            }
            break;
        case 3:
            do
            {
                printf("Digite o nome do prato a ser buscado: ");
                getchar();
                scanf("%[^\n]", nome);
            } while (stringValidation(nome));
            Prato *prato = buscarPrato(*raiz, nome);
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
            do
            {
                printf("Digite o nome do prato a ser deletado: ");
                getchar();
                scanf("%[^\n]", nome);
            } while (stringValidation(nome));

            *raiz = deletarPrato(*raiz, nome);
            break;
        case 5:
            do
            {
                printf("Digite o nome do prato: ");
                getchar();
                scanf("%[^\n]", nome);
            } while (stringValidation(nome));
            alterarPrato(raiz, nome);
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

int verificarExis(Prato *raiz, char *nome)
{
    if (raiz == NULL)
    {
        return 0;
    }

    int comparacao = strcmp(raiz->nome, nome);

    if (comparacao == 0)
    {
        return 1;
    }

    if (comparacao > 0)
    {
        return verificarExis(raiz->esquerda, nome);
    }
    else
    {
        return verificarExis(raiz->direita, nome);
    }
}