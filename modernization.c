#include <stdio.h>
#include <stdlib.h>
#include "MyLibrary.h"

list *modernization(list *str) {

    Elist *previous;
    Elist *current;
    Elist *fromto_structure;
    Elist *word_structure;
    Elist *upto_structure;

    if (str->head != NULL) {
        previous = str->head;
        current = str->head;
    }
    else {
        printf("Error: head element is NULL");
        return str;
    }

    int size_word = 0;
    int num_match = 0;
    int flag = 0;
    int flag_ft = 0;
    int flag_act = 0;
    int flag_n = 0;

    while (current != NULL) {

        char *word = malloc((size_word + 1) * sizeof(char));
        if (word == NULL) {
            printf("error allocating memory");
            exit(-1);
        }
        word[0] = '\0';

        if (current->element == '\0') break;

        if (current->element != ' ') {

            flag_n = 1;

            fromto_structure = previous;
            word_structure = previous;

            while (current->element != ' ') {

                if (current->element == '\0') break;

                size_word++;

                word = realloc(word, size_word + 1);
                word[size_word - 1] = current->element;
                word[size_word] = '\0';
                if (current->next != NULL) {
                    previous = current;
                    current = current->next;
                }

            }

            // получим отрезок для удаления

            while (!flag) {

                word_structure = previous;
                while (current->element == ' ') {
                    if (current->element == '\0') break;
                    previous = current;
                    current = current->next;
                }



                for (int i = 0; word[i] == current->element; i++) {
                    num_match++;
                    if (size_word == 1) {
                        previous = current;
                        current = current->next;
                        break;
                    }
                    else if (current->next->element == '\0') break;

                    else {
                        previous = current;
                        current = current->next;
                    }

                }

                if ((current->element != ' ' ) && (current->element != '\0') && (current->next->element != '\0')) {
                    break;
                }
                if (current->next != NULL) { if ((size_word == 1) && (current->next->element == '\0')) {break;}}


                if (num_match == size_word) {
                    flag_act = 1;//
                    flag_ft = 1;
                    word_structure = previous;
                    if (size_word == 1) upto_structure = previous;
                    else { upto_structure = current; }
                }
                else {
                    flag = 1;
                }

                num_match = 0;
                flag_ft = 0;

            }
            //удалить определенный отрезок
            if (flag_act == 1) {
                if (fromto_structure == str->head) {
                    str->head = upto_structure->next;
                }
                else if (fromto_structure->next == str->head) {
                    str->head = upto_structure->next;
                }

                fromto_structure->next = upto_structure->next;
            }

        }

        if ((flag_act == 0) && (flag_n == 1)) {
            previous = word_structure;
            current = previous->next;
        }
        else if (flag_n == 0) {
            previous =current;
            current = current->next;
        }
        if (word != NULL) free(word);
        size_word = 0;
        num_match = 0;
        flag = 0;
        flag_ft = 0;
        flag_act = 0;
        flag_n = 0;
    }

    return str;
}