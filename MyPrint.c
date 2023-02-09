#include <stdio.h>
#include "MyLibrary.h"

void MyPrint(list *str){
    Elist *el = str->head;
    printf("\"");
    while (el != NULL) {
        printf("%c", el -> element);
        el = el->next;
    }
    printf("\"\n");
}