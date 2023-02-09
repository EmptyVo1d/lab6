#include <stdio.h>
#include <stdlib.h>
#include "MyLibrary.h"

void MyFree(list *str) {
    Elist *base = str->head;
    Elist *temp = NULL;
    while (base != NULL) {
        temp = base->next;
        free(base);
        base = temp;
    }
    if (temp != NULL)
        free(temp);
    if (str != NULL)
        free(str);
}