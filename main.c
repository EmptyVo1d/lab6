#include <stdio.h>
#include <stdlib.h>
#include "MyLibrary.h"

int main() {
    list *str = (list*) malloc(sizeof(list));
    str = inputStr(str);
    MyPrint(str);
    str = modernization(str);
    MyPrint(str);
    MyFree(str);
    return 0;
}
