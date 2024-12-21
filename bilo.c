#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

int main(){
    dlink* link = create();
    input(link);
    /*output(link->head);*/

    /*delete(&link);*/

    return 0;
}

dlink* create(){
    dlink* tmp = (dlink*)malloc(sizeof(dlink));
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;
    return tmp;
}

void input(dlink* link){
    char s;
    while((s = getchar()) != EOF){
        pushBack(link, s);
        if (s == '\n'){
            sorting(link);
            /*output(link->head);*/
            delete(&link);
            link = create();
        }
    }
    delete(&link);
}



void delete(dlink** link){
    txt* tmp = (*link)->head;
    txt* next = NULL;
    while (tmp){
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    free(*link);
    (*link) = NULL;
}


void sorting(dlink* link){
    dlink* word = create();
    int len = 0;
    while ((link->head->value != ' ') /*&& (link->head->value != '\n')*/){
        word->head = link->head;
        pushFront(word, link->head->value);
        printf("%c\n", word->head->value);
        word->head = link->head->next;
        link->head = link->head->next;
        len++;
        /*printf("%d %c\n", len, word->head->value);*/
        /*word->head = word->head->next;*/
    }

    output(word->head);
        
    //тут написать цикл, в котором я сортирую элементы
    //тут написать цикл, в котором я вставляю элементы

    printf("out\n");
    /*output(word->head);*/
}

void output(txt* head){
    while ((head != NULL) && head->value != '\n'){
        printf("%c-", head->value);
        head = head->next;
    }   
    printf("\n\n");
}


void pushBack(dlink* link, char s){
    txt* tmp = (txt*)malloc(sizeof(txt));
    if (tmp == NULL)
        exit(1);
    tmp->value = s;
    tmp->next = NULL;
    tmp->prev = link->tail;
    if (link->tail)
        link->tail->next = tmp;
    link->tail = tmp;
    
    if (link->head == NULL)
        link->head = tmp;
    link->size++;
}

void pushFront(dlink* dup, char d){
    txt* tmp = (txt*)malloc(sizeof(txt));
    if (tmp == NULL)
        exit(1);
    tmp->value = d;
    tmp->next = dup->head;
    tmp->prev = NULL;
    if (dup->head)
        dup->head->prev = tmp;
    dup->head = tmp;

    if (dup->tail == NULL)
        dup->tail = tmp;
    dup->size++;
}
