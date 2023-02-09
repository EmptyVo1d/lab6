#include <stdlib.h>
#include "MyLibrary.h"
#include <stdio.h>

int main() {
    list *str = (list*) malloc(sizeof(list));
    str = inputStr(str);
    deleteSpaces(str);
    MyPrint(str);
    modernize(str);
    deleteSpaces(str);
    MyPrint(str);
    MyFree(str);
    return 0;
}
