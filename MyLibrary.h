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
    int len;
    Elist *head;
} list;

list *inputStr(list *str);

list *modernization(list *str);

void MyFree(list *str);

void MyPrint(list *str);

#endif //LAB6_MYLIBRARY_H
