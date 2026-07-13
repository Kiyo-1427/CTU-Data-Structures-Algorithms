#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef int ElementType;
typedef struct Node
{
    ElementType Element;
    struct Node *Next;
};

typedef Node *Position;
typedef Position List;

void addFirst(ElementType x, List *pL)
{
    Position p = (Position)malloc(sizeof(struct Node));
    p->Element = x;
    p->Next = (*pL)->Next;
    (*pL)->Next = p;
}
