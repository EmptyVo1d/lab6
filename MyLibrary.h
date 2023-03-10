//
// Created by evgen on 04.02.2023.
//

#ifndef LAB6_MYLIBRARY_H
#define LAB6_MYLIBRARY_H
typedef struct Elist {
    char element;
    struct Elist *next;
} Elist;
typedef struct list {
    Elist *head;
} list;

list *inputStr(list *str);

int areEqual(Elist* w1, Elist* w2);

void modernize(list* str);

void MyFree(list *str);

void MyPrint(list *str);

void deleteSpaces(list* str);

#endif //LAB6_MYLIBRARY_H
