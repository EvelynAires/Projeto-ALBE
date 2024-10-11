#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAMANHODATAB 50

typedef struct Prato Prato;

typedef struct Funcionario Funcionario;

int integerValidation();

int stringValidation(char *nome);

void menu(Prato **raiz, int *codigo, Funcionario **Funcionario);

void pratos(Prato **raiz, int *codigo);

Prato *criarABin(int codigo, char nome[], float preco);

Prato *inserirPrato(Prato *raiz, int codigo, char nome[], float preco);

void exibirPratos(Prato *raiz);

Prato *buscarPrato(Prato *raiz, char *nome);

Prato *encontrarMinimo(Prato *raiz);

Prato *deletarPrato(Prato *raiz, char *nome);

void alterarPrato(Prato **raiz, char *nome);

void liberarABin(Prato *raiz);

int verificarExis(Prato *raiz, char *nome);

int funcaoHash(int pin);

void inserirFuncionario(Funcionario **tabelaHash,char *nome, char *funcao, int pin);

void deletarFuncionario(Funcionario **tabelaHash,int pinInformado, char *nomeInformado);

void baterPonto(Funcionario **tabelaHash, int pinInformado, char *nomeInformado);

void exibirTodosFuncionarios(Funcionario **tabelaHash);

void modificarFuncionario(Funcionario **tabelaHash, int pin, char *nomeInformado);

void liberarHash(Funcionario **tabelaHash);

void menuFuncionarios(Funcionario **Funcionario);