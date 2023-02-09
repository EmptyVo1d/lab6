#include "MyLibrary.h"
#include <stdlib.h>
#include <stdio.h>


int areEqual(Elist* w1, Elist* w2) {
    Elist* c1 = w1;
    Elist* c2 = w2;
    while ((c1 != NULL && c1->element != ' ') && (c2 != NULL && c2->element != ' ')) {
        if (c1->element != c2->element) return 0;
        c1 = c1->next;
        c2 = c2->next;
    }
    if ((c1 == NULL || c1->element == ' ') && (c2 == NULL || c2->element == ' '))
        return 1;
    return 0;
}


void modernize(list* str) {
    size_t counter = 1;

    Elist* nH = calloc(1, sizeof(Elist));
    nH->next = str->head;
    nH->element = ' ';
    str->head = nH;

    Elist* start = str->head;

    Elist* cur = str->head->next;
    while (cur != NULL) {
        if (cur->element == ' ') {
            if (areEqual(start->next, cur->next))
                counter++;
            else {
                if (counter == 1)
                    start = cur;
                else {
                    Elist* next = cur->next;

                    Elist* cur2 = start->next;
                    while (cur2 != cur->next) {
                        Elist* n = cur2->next;
                        free(cur2);
                        cur2 = next;
                    }

                    start->next = next;
                    counter = 1;
                }
            }
        }
        cur = cur->next;
    }
}
