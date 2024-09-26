#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Prato Prato;

void menu(Prato **raiz);

void pratos(Prato **raiz);

Prato *criarABin(int codigo, char nome[]);

Prato *inserirPrato(Prato *raiz, int codigo, char nome[]);

void exibirPratos(Prato *raiz);

Prato *buscarPrato(Prato *raiz, int codigo);

Prato *encontrarMinimo(Prato *raiz);

Prato *deletarPrato(Prato *raiz, int codigo);

void alterarPrato(Prato *raiz, int codigo);

void liberarMemoria(Prato *raiz);