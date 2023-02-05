#include <stdio.h>
#include "MyLibrary.h"
void MyPrint(list *str){
    Elist *el = str -> head;
    printf("\"");
    while (el -> element != '\0') {
        printf("%c", (char)el -> element);
        el = el -> next;
    }
    printf("\"\n");
}