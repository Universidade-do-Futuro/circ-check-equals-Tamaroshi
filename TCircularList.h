#ifndef TCIRCULARLIST_H
#define TCIRCULARLIST_H
#include <stdbool.h>

typedef struct circular_list TCircularList;

TCircularList *TCircularList_Create();
void TCircularList_Print(TCircularList*);
_Bool TCircularList_Insert_Begin(TCircularList*, int);
_Bool TCircularList_Insert_End(TCircularList*, int);
_Bool TCircularList_Insert(TCircularList*, int, char);
_Bool TCircularList_remove_after_n_steps(TCircularList*, int);
_Bool TCircularList_equals(TCircularList* , TCircularList* );
void TCircularList_Scanear(TCircularList*);
int TCircularList_CountNo(TCircularList*);

#endif