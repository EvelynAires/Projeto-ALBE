#include "Restaurante.h"

struct Prato
{
    int codigo;
    float preco;
    char nome[50];
    struct Prato *esquerda;
    struct Prato *direita;
};

struct Funcionario
{
    char nome[100];
    char funcao[100];
    int pin;
    char status[20];

    struct Funcionario *proximo;
};
struct Pedido
{
    char descricao[250];
    int quantidade;
    Pedido *proximo;
};

struct Fila
{
    Pedido *frente;
    Pedido *tras;
};

Prato *criarABin(int codigo, char nome[], float preco)
{
    Prato *novo = (Prato *)malloc(sizeof(Prato));
    if (novo == NULL)
    {
        printf("Problema na alocacao.\n");
        exit(1);
    }
    novo->codigo = codigo;
    novo->preco = preco;
    strcpy(novo->nome, nome);
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

Prato *inserirPrato(Prato *raiz, int codigo, char nome[], float preco)
{
    if (raiz == NULL)
    {
        return criarABin(codigo, nome, preco);
    }

    if (strcmp(nome, raiz->nome) < 0)
    {
        raiz->esquerda = inserirPrato(raiz->esquerda, codigo, nome, preco);
    }
    else if (strcmp(nome, raiz->nome) > 0)
    {
        raiz->direita = inserirPrato(raiz->direita, codigo, nome, preco);
    }
    return raiz;
}

void exibirPratos(Prato *raiz)
{
    if (raiz != NULL)
    {
        exibirPratos(raiz->esquerda);
        printf(" Prato: %s (Codigo %d)\n Preco: R$%.2f\n", raiz->nome, raiz->codigo, raiz->preco);
        printf("----------------------------------\n");
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

void buscarPratos(Prato *raiz, char *nome, int *encontrados)
{
    if (raiz == NULL)
    {
        return;
    }

    if (strstr(raiz->nome, nome) != NULL)
    {
        printf("Prato encontrado: %s, Codigo: %d, Preco: R$%.2f\n", raiz->nome, raiz->codigo, raiz->preco);
        (*encontrados)++;
    }

    buscarPratos(raiz->esquerda, nome, encontrados);
    buscarPratos(raiz->direita, nome, encontrados);
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
            printf("Prato deletado!\n");
            return temp;
        }
        else if (raiz->direita == NULL)
        {
            Prato *temp = raiz->esquerda;
            free(raiz);
            printf("Prato deletado!\n");
            return temp;
        }

        Prato *temp = encontrarMinimo(raiz->direita);
        strcpy(raiz->nome, temp->nome);
        raiz->codigo = temp->codigo;
        raiz->direita = deletarPrato(raiz->direita, temp->nome);
    }
    return raiz;
}

void alterarPrato(Prato **raiz, char *nome)
{
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

    printf("Prato encontrado: %s\n Preco: %.2f\n (Codigo: %d)\n", prato->nome, prato->preco, prato->codigo);

    char novoNome[50];
    float preco;
    int valid, op;
    int cod = 0;
    printf("O que deseja alterar? \n");
    printf(" 1 - Nome\n");
    printf(" 2 - Preco\n");
    op = integerValidation();
    switch (op)
    {
    case 1:
        do
        {
            printf("Digite o novo nome do prato: ");
            scanf(" %[^\n]", novoNome);
            getchar();
        } while (stringValidation(novoNome));
        preco = prato->preco;
        cod = prato->codigo;
        *raiz = deletarPrato(*raiz, nome);
        *raiz = inserirPrato(*raiz, cod, novoNome, preco);
        break;
    case 2:
        do
        {
            printf("Digite o preco: \n");
            valid = scanf(" %f", &preco);
            while (getchar() != '\n')
                ;
            if (valid == 0)
            {
                printf("Por favor, insira um numero valido para o preco.\n");
            }
        } while (valid == 0);
        cod = prato->codigo;
        *raiz = deletarPrato(*raiz, nome);
        *raiz = inserirPrato(*raiz, cod, prato->nome, preco);
        break;
    default:
        printf("Opcao invalida!\n");
        break;
    }

    printf("Prato alterado e reposicionado na arvore!\n");
}

void pratos(Prato **raiz, int *codigo)
{
    int opcao, valid;
    float preco;
    char nome[50];
    int encontrados = 0;

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
                scanf(" %[^\n]", nome);
            } while (stringValidation(nome));
            do
            {
                printf("Digite o preco: \n");
                valid = scanf(" %f", &preco);
                while (getchar() != '\n')
                    ;
                if (valid == 0)
                {
                    printf("Por favor, insira um numero valido para o preco.\n");
                }
            } while (valid == 0);
            if (verificarExis(*raiz, nome))
            {
                printf("O prato ja existe!\n");
            }
            else
            {
                (*codigo)++;
                *raiz = inserirPrato(*raiz, *codigo, nome, preco);
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
                scanf(" %[^\n]", nome);
            } while (stringValidation(nome));
            getchar();
            buscarPratos(*raiz, nome, &encontrados);
            if (encontrados == 0)
            {
                printf("Nenhum prato encontrado.\n");
            }
            getchar();
            break;
        case 4:
            do
            {
                printf("Digite o nome do prato a ser deletado: ");
                getchar();
                scanf(" %[^\n]", nome);
            } while (stringValidation(nome));
            getchar();
            *raiz = deletarPrato(*raiz, nome);
            break;
        case 5:
            do
            {
                printf("Digite o nome do prato: ");
                scanf("%[^\n]", nome);
            } while (stringValidation(nome));
            getchar();
            alterarPrato(raiz, nome);
            break;
        default:
            printf("Opcao invalida!\n");
        }
    } while (opcao != 6);
    printf("Voltando ao menu principal...\n");
}

void liberarABin(Prato *raiz)
{
    if (raiz != NULL)
    {
        liberarABin(raiz->esquerda);
        liberarABin(raiz->direita);
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

void menuFuncionarios(Funcionario **Funcionario)
{

    char nome[20];
    char funcao[20];
    int pin;

    while (1)
    {

        printf("1 - Registrar funcionario \n");
        printf("2 - Deletar funcionario \n");
        printf("3 - Mostrar funcionarios \n");
        printf("4 - Modificar dados \n");
        printf("5 - Retornar ao menu principal \n");

        int op = 0;
        op = integerValidation();

        switch (op)
        {
        case 1:
            do
            {
                printf("Nome: ");
                scanf(" %[^\n]", nome);
                getchar();
            } while (stringValidation(nome));

            do
            {
                printf("Funcao: ");
                scanf(" %[^\n]", funcao);
                getchar();
            } while (stringValidation(funcao));

            printf("Pin: \n");
            pin = integerValidation();

            inserirFuncionario(Funcionario, nome, funcao, pin);
            break;

        case 2:
            printf("PIN: \n");
            pin = integerValidation();

            do
            {
                printf("Nome: ");
                scanf(" %[^\n]", nome);
                getchar();
            } while (stringValidation(nome));

            deletarFuncionario(Funcionario, pin, nome);
            break;

        case 3:
            exibirTodosFuncionarios(Funcionario);
            break;

        case 4:
            printf("PIN: \n");
            pin = integerValidation();

            do
            {
                printf("Nome: ");
                scanf(" %[^\n]", nome);
                getchar();
            } while (stringValidation(nome));

            modificarFuncionario(Funcionario, pin, nome);
            break;
        case 5:
            return;

            break;
        default:
            printf("Insercao invalida\n");

            break;
        }
    }
}

int funcaoHash(int pin)
{
    float constante = 0.618033f;

    float multip = pin * constante;

    float pFracionaria = multip - (int)multip;

    int indice = (int)(pFracionaria * TAMANHODATAB);

    return indice;
}

void inserirFuncionario(Funcionario **tabelaHash, char *nome, char *funcao, int pin)
{
    Funcionario *novoFuncionario = (Funcionario *)malloc(sizeof(Funcionario));
    if (novoFuncionario == NULL)
    {
        printf("Problema na realocacao.\n");
        exit(1);
    }

    strcpy(novoFuncionario->nome, nome);
    strcpy(novoFuncionario->funcao, funcao);

    novoFuncionario->pin = pin;

    strcpy(novoFuncionario->status, "OFF");

    novoFuncionario->proximo = NULL;

    int indice = funcaoHash(pin);

    if (tabelaHash[indice] == NULL)
    {
        tabelaHash[indice] = novoFuncionario;
    }
    else
    {
        Funcionario *atual = tabelaHash[indice];

        while (atual->proximo != NULL)
        {
            atual = atual->proximo;
        }
        atual->proximo = novoFuncionario;
    }
}

void deletarFuncionario(Funcionario **tabelaHash, int pinInformado, char *nomeInformado)
{
    int indice = funcaoHash(pinInformado);

    Funcionario *atual = tabelaHash[indice];
    Funcionario *anterior = NULL;

    while (atual != NULL)
    {
        if (atual->pin == pinInformado && strcmp(atual->nome, nomeInformado) == 0)
        {
            if (anterior == NULL)
            {
                tabelaHash[indice] = atual->proximo;
            }
            else
            {
                anterior->proximo = atual->proximo;
            }

            free(atual);
            printf("Funcionario %s removido com sucesso!\n", nomeInformado);
            return;
        }

        anterior = atual;
        atual = atual->proximo;
    }

    printf("Funcionario com PIN ou nome incorreto.\n");
}

void baterPonto(Funcionario **tabelaHash, int pinInformado, char *nomeInformado)
{
    int indice = funcaoHash(pinInformado);

    Funcionario *atual = tabelaHash[indice];

    while (atual != NULL)
    {
        if (atual->pin == pinInformado && strcmp(atual->nome, nomeInformado) == 0)
        {
            if (strcmp(atual->status, "OFF") == 0)
            {
                strcpy(atual->status, "ON");
            }
            else
            {
                strcpy(atual->status, "OFF");
            }

            printf("Ponto %s registrado com sucesso para %s!\n", atual->status, atual->nome);
            return;
        }
        atual = atual->proximo;
    }

    printf("PIN ou nome incorreto\n");
}

void exibirTodosFuncionarios(Funcionario **tabelaHash)
{
    for (int i = 0; i < TAMANHODATAB; i++)
    {
        Funcionario *atual = tabelaHash[i];

        if (atual == NULL)
        {
            continue;
        }
        while (atual != NULL)
        {
            printf("Nome: %s\n", atual->nome);
            printf("Funcao: %s\n", atual->funcao);
            printf("Status: %s\n", atual->status);
            printf("-----------------------\n");
            atual = atual->proximo;
        }
    }
}

void modificarFuncionario(Funcionario **tabelaHash, int pin, char *nomeInformado)
{
    int indice = funcaoHash(pin);

    Funcionario *atual = tabelaHash[indice];

    while (atual != NULL)
    {
        if (atual->pin == pin && strcmp(nomeInformado, atual->nome) == 0)
        {

            printf("Nome atual: %s\n ", atual->nome);
            do
            {
                printf("Modifique o nome:: ");
                scanf(" %[^\n]", atual->nome);
                getchar();
            } while (stringValidation(atual->nome));

            printf("Funcao: %s\n  ", atual->funcao);
            do
            {
                printf("Modifique a funcao: ");
                scanf(" %[^\n]", atual->funcao);
                getchar();
            } while (stringValidation(atual->funcao));

            return;
        }
        atual = atual->proximo;
    }

    printf("Funcionario nao encontrado.\n");
}

void liberarHash(Funcionario **tabelaHash)
{
    for (int i = 0; i < TAMANHODATAB; i++)
    {
        Funcionario *atual = tabelaHash[i];
        while (atual != NULL)
        {
            Funcionario *proximo = atual->proximo;
            free(atual);
            atual = proximo;
        }
    }
}

Fila *criarFila()
{
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    if (fila)
    {
        fila->frente = NULL;
        fila->tras = NULL;
    }
    return fila;
}

void liberarFila(Fila *fila)
{
    while (fila->frente != NULL)
    {
        removerPedido(fila);
    }
    free(fila);
}

void inserirPedido(Fila *fila, char *nomePrato, int quantidade)
{
    Pedido *novoPedido = (Pedido *)malloc(sizeof(Pedido));
    if (!novoPedido)
    {
        printf("Problema na alocacao.\n");
        return;
    }
    strcpy(novoPedido->descricao, nomePrato);
    novoPedido->quantidade = quantidade;
    novoPedido->proximo = NULL;

    if (fila->tras == NULL)
    {
        fila->frente = novoPedido;
    }
    else
    {
        fila->tras->proximo = novoPedido;
    }
    fila->tras = novoPedido;
    printf("Pedido inserido: %s (Quantidade: %d)\n", nomePrato, quantidade);
}

void removerPedido(Fila *fila)
{
    if (fila->frente == NULL)
    {
        printf("A fila esta vazia. Nenhum pedido para remover.\n");
        return;
    }

    Pedido *temp = fila->frente;
    fila->frente = fila->frente->proximo;

    if (fila->frente == NULL)
    {
        fila->tras = NULL;
    }

    free(temp);
}

void exibirFila(Fila *fila)
{
    if (fila->frente == NULL)
    {
        printf("A fila esta vazia.\n");
        return;
    }

    Pedido *atual = fila->frente;
    while (atual != NULL)
    {
        printf("\n-------------------\nPedido: %s (Quantidade: %d)\n -------------------\n", atual->descricao, atual->quantidade);
        atual = atual->proximo;
    }
}

void menuPedidos(Fila *fila)
{
    int opcao;
    char descricao[50];
    int quantidade;

    do
    {
        printf("\n=== Menu Pedidos ===\n");
        printf("1 - Adicionar pedido\n");
        printf("2 - Remover primeiro pedido\n");
        printf("3 - Ver fila de pedidos\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        opcao = integerValidation();
        getchar();

        switch (opcao)
        {
        case 1:
            printf("\n----------------------------------------\n");
            printf("Digite a descricao do pedido, inclua detalhes especificos\n");
            printf("como o nome do prato, se o cliente deseja ou nao determinados tipos de temperos\n");
            printf("e especifique o modo de preparo.\n");
            printf("\n----------------------------------------\n Descricao: ");
            fgets(descricao, sizeof(descricao), stdin);

            printf("Quantidade: ");
            quantidade = integerValidation();

            inserirPedido(fila, descricao, quantidade);
            break;
        case 2:
            removerPedido(fila);
            printf("Primeiro pedido removido!\n");
            break;
        case 3:
            exibirFila(fila);
            break;
        case 4:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 4);
}