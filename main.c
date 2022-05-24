#include "TCircularList.h"
#include <stdio.h>


int main()
{
    int x;
    TCircularList* lista1 = TCircularList_Create();
    TCircularList* lista2 = TCircularList_Create();

    TCircularList_Scanear(lista1);
    TCircularList_Scanear(lista2);
    
    bool flag = TCircularList_equals(lista1, lista2);
    if(flag == true)
        printf("1");
    else
        printf("0"); 
    return 0;
}