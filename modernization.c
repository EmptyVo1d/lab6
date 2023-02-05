#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MyLibrary.h"

list *modernization(list *str) {
    Elist *el;
    Elist *elNext;
    Elist *start;
    Elist *Wstart;
    Elist *Sstart;
    int len = 0;
    int size = 0;

    el = str->head;
    Sstart = el;
    elNext = str->head->next;
    while (el != NULL) {
        char *word = calloc(size + 1, sizeof(char));
        int i = 0;
        if (el->element == '\0') {
            break;
        }
        if (el->element != ' ') {
            while (el->element != ' ') {
                if (el->element == '\0') {
                    break;
                }
                len++;
                size++;
                word = realloc(word, size + 1);
                word[size - 1] = el->element;
                word[size] = '\0';
                if (el->next != NULL) el = el->next;
            }
            Wstart = el;
            while (el->element == ' ') {
                if (el->element == '\0') {
                    break;
                }
                el = el->next;
            }
            int col = 0;
            if (el->element == '\0') {
                break;
            }
            while (word[i] == el->element) {
                col++;
                i++;
                el = el->next;
            }
            if (col != strlen(word)) Sstart = Wstart;
            if (col == strlen(word)) {
                Sstart->next = el;
            }
            if (el->next != NULL) el = el->next;
        }
        size = 0;
        free(word);
    }
    return str;
}