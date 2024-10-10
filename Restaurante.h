#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Prato Prato;

typedef struct pedido Pedido;

int integerValidation();

int stringValidation(char *nome);

void menu(Prato **raiz, int *codigo);

void pratos(Prato **raiz, int *codigo);

Prato *criarABin(int codigo, char nome[], float preco);

Prato *inserirPrato(Prato *raiz, int codigo, char nome[], float preco);

void exibirPratos(Prato *raiz);

Prato *buscarPrato(Prato *raiz, char *nome);

Prato *encontrarMinimo(Prato *raiz);

Prato *deletarPrato(Prato *raiz, char *nome);

void alterarPrato(Prato **raiz, char *nome);

void liberarMemoria(Prato *raiz);

int verificarExis(Prato *raiz, char *nome);