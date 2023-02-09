#include <stdio.h>
#include <stdlib.h>
#include "MyLibrary.h"

list *inputStr(list *str){
    Elist *el = (Elist *) malloc(sizeof(Elist));
    str->head = el;
    char point;
    while ((point = getchar())) {
        if (point == '\n') break;
        el->element = point;
        Elist *newEl = (Elist *) malloc(sizeof(Elist));
        el->next = newEl;
        el = newEl;
    }
    el->element = '\0';
    el->next = NULL;
    el = NULL;
    return str;
}