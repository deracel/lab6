#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

int main(){
    tlist* list = create();
    input(list);
    return 0;
}


void input(tlist* list){
    char s;
    while((s = getchar()) != EOF){
        if (s != '\n')
            pushBack(list, s);
        if (s == '\n'){
            razdel(list->head);
            output(list->head);
            delete(&list);
            list = create();
        }
    }
    delete(&list);
}

