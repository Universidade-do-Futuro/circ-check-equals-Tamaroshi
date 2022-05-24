#include "TCircularList.h"
#include <stdio.h>
#include <stdlib.h>
#define BEGIN 1
#define END 0

typedef struct no
{
    int info;
    struct no *prox;
}TNo;

struct circular_list
{
    TNo* inicio;
    int qty;
};

TNo* TNo_Fill(int);
int TCircularList_CountNo(TCircularList*);

TCircularList *TCircularList_Create()
{
    TCircularList *novo = malloc(sizeof(TCircularList));
    if(novo != NULL)
        novo->inicio = NULL;
    
    return novo;
}

void TCircularList_Print(TCircularList* lista){
    TNo* aux = lista->inicio;

    do{
        if(aux==NULL) break;
        printf("[%d]->", aux->info);
        aux = aux->prox;
    }while(aux != lista->inicio);
    putchar('\n');
}

_Bool TCircularList_Insert_Begin(TCircularList* lista, int info)
{
    TCircularList_Insert(lista, info, BEGIN);
}

_Bool TCircularList_Insert_End(TCircularList* lista, int info)
{
    TCircularList_Insert(lista, info, END);
}

_Bool TCircularList_Insert(TCircularList* lista, int info, char flag)
{
    TNo *novo = TNo_Fill(info);
    if(novo == NULL)
        return false;

    if(lista->inicio == NULL)
    {
        novo->prox = novo;
        lista->inicio = novo;
    }
    else
    {
        TNo* aux = lista->inicio;
        while (aux->prox !=lista->inicio)
            aux = aux->prox;
        aux->prox = novo;
        novo->prox = lista->inicio;
    }

    if(flag == BEGIN)
        lista->inicio = novo;
    return true;
}

_Bool TCircularList_equals(TCircularList* lista1, TCircularList* lista2)
{
    if(lista1->inicio == NULL && lista2->inicio == NULL) return false;

    int a, b;
    a = TCircularList_CountNo(lista1);
    b = TCircularList_CountNo(lista2);

    if(a != b)
        return false;  

    else
    {
        TNo* aux = lista1->inicio;
        TNo* aux2 = lista2->inicio;
        int flag = 1, count=0, c=0;
        if(aux->info != aux2->info)
        {
            while (aux->info != aux2->info)
            {
                aux2 = aux2->prox;
                if(aux2 == lista2->inicio)
                {
                    flag = 0;
                    return false;
                    break;
                }
            }

            if(flag = 1)
            {
                while (c < a)
                {
                    if(aux->info == aux2->info)
                    {
                        count++;
                        aux = aux->prox;
                        aux2 = aux2->prox;
                    }
                    c++;
                }
            }

            else return false;
            if(count == a) return true;
        }
    }
}

void TCircularList_Scanear(TCircularList* lista)
{
    int size, info;
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &info);
        TCircularList_Insert_End(lista, info);
    }
}   

//Auxiliares

TNo* TNo_Fill(int info)
{
    TNo* novo = malloc(sizeof(TNo));
    if(novo != NULL)
    {
        novo->info = info;
        novo->prox = NULL;
    }

    return novo;
}


int TCircularList_CountNo(TCircularList* lista)
{
    int count=0;
    TNo *aux = lista->inicio;
    do
    {
        count += 1;
        aux = aux->prox;
    } while (aux != lista->inicio);
    return count;
}