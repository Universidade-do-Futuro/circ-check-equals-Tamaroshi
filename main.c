#include "TCircularList.h"
#include <stdio.h>
/**
* Reads a circular list on the format: first integer means the number of elements.
* Then reads the remainer of elements and insert into a circular list
* @return TCircularList*
*/
 TCircularList* readList()
 {
  int size, i, number;
  TCircularList* lista1 = TCircularList_create();
  scanf("%d", &size);
  for(i = 0; i < size; i++){
    scanf("%d", &number); 
    TCircularList_insert_end(lista1, number);
  }
  return lista1;
}

int main(){
  TCircularList* lista1 = readList();
  TCircularList* lista2 = readList();
  printf("%d", TCircularList_equals(lista1, lista2));
  return 0;
}
