#include "TCircularList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define END 0
#define BEGIN 1

typedef struct no {
    int info;
    struct no* prox;
}TNo;

TNo* TNo_createNFill(int);
_Bool TCircularList_insert(TCircularList*, int, char);

struct linked_list{
    TNo* inicio;
    int qty;
};

TCircularList* TCircularList_create(){
    TCircularList* nova = malloc(sizeof(TCircularList));
    if(nova!=NULL){
        nova->inicio = NULL;
        nova->qty = 0;
    } return nova;
}

_Bool TCircularList_insert_end(TCircularList* lista, int info){
    return TCircularList_insert(lista, info, END);
}

void TCircularList_print(TCircularList* lista){
    TNo* aux = lista->inicio;

    do{
        if(aux==NULL) break;
        printf("[%d]-> ", aux->info);
        aux = aux->prox;
    }while(aux != lista->inicio);
    putchar('\n');
}

//Auxiliares

TNo* TNo_createNFill(int info){
    TNo* novo = malloc(sizeof(TNo));
    if(novo!=NULL){
        novo->info = info;
        novo->prox = NULL;
    } return novo;
}

_Bool TCircularList_insert(TCircularList* lista, int info, char flag){
    TNo* novo = TNo_createNFill(info);
    if(novo==NULL) return false;
    
    if(lista->inicio == NULL){
        novo->prox = novo;
        lista->inicio = novo;
    }
    else{
        //Procurar o elemento do fim
        TNo* aux = lista->inicio;
        while(aux->prox != lista->inicio)
            aux = aux->prox;
        aux->prox = novo;
        novo->prox = lista->inicio;
    }
    if(flag == BEGIN)
        lista->inicio = novo;
    lista->qty++;
    return true;
}


bool TCircularList_equals(TCircularList* lista1, TCircularList* lista2){
    /**
    Campos existentes na TCircularList {
        qty -> quantidade de elementos na lista
        inicio-> ponteiro para o início da lista
    }
    Campos da TNo{
        int info;
        struct no* prox;
    }
    */
    //Seu código aqui.... 
    return false;
}