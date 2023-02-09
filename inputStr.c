#include <stdio.h>
#include <stdlib.h>
#include "MyLibrary.h"

list *inputStr(list *str){
    Elist *el = calloc(1, sizeof(Elist));
    str->head = el;
    char point;
    while (point = getchar()) {
        if (point == '\n') break;
        el->element = point;
        Elist *newEl = calloc(1, sizeof(Elist));
        el->next = newEl;
        el = newEl;
    }
    el->element = ' ';
    el->next = NULL;
    return str;
}
