// arquivo main

#include "base.h"

// tamanho_maximo = 10
// buffer = 64

int main()
{
    size_t current = 0;
    int indice;

    char item[64];
    char tipo[20];
    int quantidade;

    no *mochila = (no *)malloc(sizeof(no) * tamanho_maximo); // criando a lista
    if (mochila == NULL)
    {
        puts("Erro na locacao");
        exit(1);
    }

    int escolha;
    do
    {
        puts("\n====================");
        puts("1 - navegar pela mochila");
        puts("2 - inserir item");
        puts("3 - remover item");
        puts("4 - procurar item");
        puts("5 - sair da mochila");

        escolha = Ler_int("Sua escolha: ", sizeof(int));

        switch (escolha)
        {
        case 1:
            travel(mochila, current);
            break;

        case 2:
            insert(mochila, &current, item, tipo, &quantidade);
            break;

        case 3:
            remover(mochila, &current, item);
            break;

        case 4:
            indice = search(mochila, current, item);
            if (indice != -1)
                printf("Item encontrado na %d posicao", indice + 1);
            break;

        default:
            puts("Saindo...");
            break;
        }
    } while (escolha > 0 && escolha < 5);

    // liberando a memoria
    for (size_t i = 0; i < current; i++)
        free(mochila[i].item);
    free(mochila);
    return 0;
}
