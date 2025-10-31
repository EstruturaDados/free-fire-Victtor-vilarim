// arquivo para definir as funcoes

#include "base.h"

int Ler_int(const char *prompt, int tamanho)
{
    int valor;
    char buffer[64];
    while (1)
    {
        printf("%s", prompt);
        if (fgets(buffer, tamanho, stdin) == NULL)
        {
            printf("Erro na leitura, tente novamente\n");
            continue;
        }
        if (sscanf(buffer, "%d", &valor) == 1) // converte a string em numero
            return valor;
        puts("Digite um numero valido!");
    }
}

void ler(const char *prompt, char *text, int tamanho)
{
    while (1)
    {
        printf("%s", prompt);
        if (fgets(text, tamanho, stdin) == NULL) // le e verifica se houve erro como: ctrl + c
        {
            printf("Erro de leitura\n");
            break;
        }

        size_t len = strlen(text);
        if (len > 0 && text[len - 1] == '\n') // se tem algo digitado e o ultimo caracter for enter
        {
            text[len - 1] = '\0'; // substitui por fim da string
            break;
        }
        else // limpa o stdin
        {
            int ch;
            int i = 1;
            while ((ch = getchar()) != '\n' && ch != EOF)
                i++;
            printf("Digite %d caracteres a menos\n", i);
        }
    }
}

void travel(no *list, size_t current)
{
    for (size_t i = 0; i < current; i++)
    {
        printf("======item %zu=====\n", i + 1);
        printf("Nome: %s\n", list[i].item);
        printf("Tipo: %s\n", list[i].tipo);
        printf("Voce possui: %d unidades desse item\n", list[i].quantidade);
        puts("====================");
    }
    if (current == 0)
        puts("Sua mochila esta vazia");
    return;
}

void insert(no *list, size_t *current, char *item, char *tipo, int *quantidade)
{
    if (*current < tamanho_maximo)
    {
        puts("\n=====Insercao de itens=====");

        ler("Qual o nome do item? ", item, bufferInt);
        list[*current].item = (char *)malloc(strlen(item) + 1);
        if (list[*current].item == NULL)
        {
            puts("Erro na locacao");
            return;
        }
        strcpy(list[*current].item, item);

        ler("Qual o tipo do item? ", tipo, 20);
        strcpy(list[*current].tipo, tipo);

        *quantidade = Ler_int("Quantos itens possui? ", bufferInt);
        list[*current].quantidade = *quantidade;

        (*current)++; // current eh a quantidade de itens na mochila

        puts("====item adicionado a sua mochila====");
        return;
    }
    else
        puts("Inventario cheio");
    return;
}

void remover(no *list, size_t *current, char *value) // a funcao remove ja existe, mas serve para arquivos
{
    if (*current == 0)
    {
        puts("Sua mochila esta vazia!");
        return;
    }

    puts("\n=====Exclusao de item=====");
    ler("Qual item deseja exluir? ", value, sizeof(value));
    for (size_t i = 0; i < *current; i++)
    {
        if (!strcmp(list[i].item, value))
        {
            free(list[i].item);

            for (size_t j = i; j < *current - 1; j++) // current eh base 1 e i eh base 0
                list[j] = list[j + 1];                // metodo deslocamento

            (*current)--;
            puts("====item removido de sua mochila====");
            return;
        }
    }
    puts("O item nao existe");

    return;
}

int search(no *list, size_t current, char *value)
{
    if (current == 0)
    {
        puts("Sua mochila esta vazia");
        return -1;
    }

    ler("Qual item deseja achar? ", value, bufferInt);
    for (size_t i = 0; i < current; i++)
    {
        if (!strcmp(list[i].item, value))
        {
            printf("Nome: %s\n", list[i].item);
            printf("Tipo: %s\n", list[i].tipo);
            printf("Quantidade: %d\n", list[i].quantidade);
            return i;
        }
    }
    puts("Valor nao encontrado");
    return -1;
}
