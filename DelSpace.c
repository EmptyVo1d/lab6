#include "MyLibrary.h"
#include <stdlib.h>
#include <stdio.h>

void deleteSpaces(list* str) {
    while (str->head->element == ' ' || str->head->element == '\t') {
        Elist* next = str->head->next;
        free(str->head);
        str->head = next;
    }

    Elist* cur = str->head;
    while (cur->next != NULL) {
        if ((cur->element == ' ' || cur->element == '\t') && (cur->next->element == ' ' || cur->next->element == '\t')) {
            cur->element = ' ';
            Elist* next = cur->next->next;
            free(cur->next);
            cur->next = next;
        } else cur = cur->next;
    }

    cur = str->head;
    while (cur->next != NULL) {
        if (cur->next->next == NULL && cur->next->element == ' ') {
            free(cur->next);
            cur->next = NULL;
        } else cur = cur->next;
    }
}
