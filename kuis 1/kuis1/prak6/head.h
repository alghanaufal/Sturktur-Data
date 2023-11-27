#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct{
    char type[50];
	char name[50];
	int price;
}menu;

typedef struct{
	char name[50];
}swap;

typedef struct elmt* elmntsdir;
typedef struct elmt{
	menu container;
	elmntsdir next;
}elements;

typedef struct{
	elements* first;
}list;

void createList(list *L);
int countElement(list L);
void addFirst(menu input, list *L);
void addAfter(elements* prev, menu input, list *L);
void addLast(menu input, list *L);
void print(list L1, list L2);
void swaps(list *L1, list *L2, swap name1, swap name2);
void tukar(list *L1, list *L2, char wo[], char type[]);
int counttype(list L, char type[]);