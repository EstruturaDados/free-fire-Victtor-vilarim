#ifndef BASE_H
#define BASE_H

#define tamanho_maximo 10
#define bufferInt 64

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
    char *item;
    char tipo[20];
    int quantidade;
} no;

int Ler_int(const char *prompt, int tamanho);

void ler(const char *prompt, char *text, int tamanho);

void travel(no *list, size_t current);

void insert(no *list, size_t *current, char *item, char *tipo, int *quantidade);

void remover(no *list, size_t *current, char *value);

int search(no *list, size_t current, char *value);

#endif