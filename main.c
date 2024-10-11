#include "Restaurante.h"

int main(void)
{
    int codigo = 0;
    Funcionario *tabelaHash[TAMANHODATAB];

    for (int i = 0; i < TAMANHODATAB; i++)
    {
        tabelaHash[i] = NULL;
    }

    Prato *raiz = NULL;
    menu(&raiz, &codigo, tabelaHash);

    return 0;
}