#include <stdio.h>
#include <stdlib.h>
#include "MyLibrary.h"

list *inputStr(list *str){
    Elist *el = (Elist *) malloc(sizeof(Elist));
    str->head = el;
    str->len = 0;
    char point;
    while ((point = getchar())^EOF) {
        if (point == '\n') break;
        str->len++;
        el->element = point;
        Elist *newEl = (Elist *) malloc(sizeof(Elist));
        el->next = newEl;
        el = newEl;
    }
    el->element = '\0';
    el->next = NULL;
    return str;
}