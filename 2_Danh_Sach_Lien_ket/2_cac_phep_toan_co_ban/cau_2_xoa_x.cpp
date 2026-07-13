#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef int ElementType;
typedef struct Node{
    ElementType Element;
    struct Node* Next;
};
typedef struct Node* Position;
typedef Position List;

void deleteList(Position p, List *pL){
    Position t;
    if (p->Next != NULL){
        t = p->Next;
        p->Next = p->Next->Next;
        free(t);
    }

}