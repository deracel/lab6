typedef struct Str{
    char value;
    struct Str* next;
    struct Str* prev;
}tnode;

typedef struct Dlink{
    int size;
    tnode* head;
    tnode* tail;
}tlist;

void input(tlist*);
tlist* create();
void sorting (tlist*);
void pushBack (tlist*, char);
void delete (tlist**);
void push(tnode**);
void output(tnode*);
void razdel(tnode*);
void slovo(tnode*, tnode*);
