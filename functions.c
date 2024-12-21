#include <stdlib.h>
#include <stdio.h>
#include "lib.h"

tlist* create(){
    tlist* tmp = (tlist*)malloc(sizeof(tlist));
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;
    return tmp;
}

void delete(tlist** list){
    tnode* tmp = (*list)->head;
    tnode* next = NULL;
    while (tmp){
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    free(*list);
    (*list) = NULL;
}

void output(tnode* head){
    tnode* temp = head;
    printf("resoult: '");
    while (temp != NULL) {
        printf("%c", temp->value);
        temp = temp->next;
        /*if (temp != NULL)
            printf("-");*/
    }
    printf("'\n\n");
}


void pushBack(tlist* list, char s){
    tnode* tmp = (tnode*)malloc(sizeof(tnode));
    if (tmp == NULL)
        exit(1);
    tmp->value = s;
    tmp->next = NULL;
    tmp->prev = list->tail;
    if (list->tail)
        list->tail->next = tmp;
    list->tail = tmp;
    
    if (list->head == NULL)
        list->head = tmp;
    list->size++;
}


void slovo(tnode* begin, tnode* end){
    if (begin == end) 
        return;
    tnode* i = begin;
    while (i != end) {
        tnode* j = i->next;
        while (j != end) {
            if (i->value > j->value) {
                char temp = i->value;
                i->value = j->value;
                j->value = temp;
            }
            j = j->next;
        }
        i = i->next;
    }
}

void razdel(tnode* head) {
    tnode* cur = head;  
    while (cur != NULL) {
        tnode* start = cur;

        while (cur != NULL && cur->value != ' ') {
            cur = cur->next;
        }
        if (start != NULL) {
            slovo(start, cur);
        }
        if (cur != NULL) {
            cur = cur->next;
        }
    }
}
