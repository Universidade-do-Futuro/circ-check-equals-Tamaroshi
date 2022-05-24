#ifndef TCIRCULAR_LINKED_LIST_H
#define TCIRCLAR_LINKED_LIST_H
#include <stdbool.h>
   
typedef struct linked_list TCircularList;
/**
 * Cria uma uma instância válida de TCircularList
 * @return TCircularList*
 * */
TCircularList* TCircularList_create();
/**
 * Insere um inteiro no fim da lista.
 * @param TCircularList* ponteiro da lista
 * @param int informação a ser inserida
 * @return _Bool (se deu certo ou não)
 * */
_Bool TCircularList_insert_end(TCircularList*, int);
/**
 * Remove o nó após n passos na lista circular a partir do início.
 * @param TCircularList* ponteiro para a primeira lista
 * @param TCircularList* ponteiro para a segunda lista 
 * @return bool indicando se as listas são iguais ou não.
 * */
bool TCircularList_equals(TCircularList*, TCircularList*);
/**
 * Imprime uma lista circular.
 * @param TCircularList* ponteiro para a primeira lista
 * */
void TCircularList_print(TCircularList*);

#endif
