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

void menu(Prato **raiz, int *codigo, Funcionario **Funcionario)
{
    char nome[20];
    char funcao[20];
    int pin, op;
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
            case 1: 
            menuFuncionarios(Funcionario);
            break;
        case 5:
            pratos(raiz, codigo);
            break;
        case 6:
            printf("Nome: \n");
            scanf(" %[^\n]", nome);

            printf("PIN: \n");
            scanf("%d", &pin);

            baterPonto(Funcionario, pin, nome);
            break;
        case 7:
            liberarABin(*raiz);
            liberarHash(Funcionario);
            printf("Saindo...\n");
            break;
        default:
            printf("Tente outra opcao!\n");
        }
    } while (op != 7);
}

Prato *criarABin(int codigo, char nome[], float preco)
{
    Prato *novo = (Prato *)malloc(sizeof(Prato));
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
        printf("Prato: %s, Codigo: %d Preco: R$%.2f\n", raiz->nome, raiz->codigo, raiz->preco);
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

    printf("Prato encontrado: %s , Preco: %.2f (Codigo: %d)\n", prato->nome, prato->preco, prato->codigo);

    char novoNome[50];
    float preco;
    int valid;

    do
    {
        printf("Digite o novo nome do prato: ");
        scanf(" %[^\n]", novoNome);
        getchar();
    } while (stringValidation(novoNome));
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

    int codigoPrato = prato->codigo;

    *raiz = deletarPrato(*raiz, nome);
    *raiz = inserirPrato(*raiz, codigoPrato, novoNome, preco);

    printf("Prato alterado e reposicionado na arvore!\n");
}

void pratos(Prato **raiz, int *codigo)
{
    int opcao, valid;
    float preco;
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
                printf("O prato já existe!\n");
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
                getchar();
                scanf("%[^\n]", nome);
            } while (stringValidation(nome));
            Prato *prato = buscarPrato(*raiz, nome);
            if (prato != NULL)
            {
                printf("Prato encontrado: %s, Codigo: %d\n, Preco: %.2f\n", prato->nome, prato->codigo, prato->preco);
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
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("Nome: \n");
            scanf(" %[^\n]", nome);

            printf("Funcao: \n");
            scanf(" %[^\n]", funcao);

            printf("Pin: \n");
            scanf("%d", &pin);


            inserirFuncionario(Funcionario, nome, funcao, pin);
            break;

        case 2:
            printf("PIN: \n");
            scanf("%d", &pin);

            printf("Digite o nome: \n");
            scanf(" %[^\n]", nome);

            deletarFuncionario(Funcionario, pin, nome);
            break;

        case 3:
            exibirTodosFuncionarios(Funcionario);
            break;

        case 4:
            printf("PIN: \n");
            scanf("%d", &pin);

            printf("Nome: \n");
            scanf(" %[^\n]", nome);

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

            printf("Nome atual: %s\n Modifique o nome:", atual->nome);
            scanf(" %[^\n]", atual->nome);

            printf("Funcao: %s\n Modifique a funcao: ", atual->funcao);
            scanf(" %[^\n]", atual->funcao);

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