#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
struct Node
{
    ElementType Element;
    struct Node *Next;
};
typedef struct Node *Position;
typedef Position List;
void makenullList(List *Header)
{
    (*Header) = (struct Node *)malloc(sizeof(struct Node));
    (*Header)->Next = NULL;
}
void append(ElementType x, List *pL)
{
    Position t = (Position)malloc(sizeof(struct Node));
    t->Element = x;
    t->Next = NULL;
    Position last = (*pL);
    while (last->Next != NULL)
    {
        last = last->Next;
    }
    last->Next = t;
}

int member(ElementType x, List L)
{
    Position p = L->Next;
    for (; p != NULL; p = p->Next)
    {
        if (p->Element == x)
        {
            return 1;
        }
    }
    return 0;
}

void addfrist(ElementType x, List *pL)
{
    Position t = (Position)malloc(sizeof(struct Node));
    t->Element = x;
    t->Next = (*pL)->Next;
    (*pL)->Next = t;
}
void readlist(List *pL)
{
    int n, i;
    ElementType x;
    makenullList(pL);
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if (member(x, *pL) == 0)
        {
            addfrist(x, pL);
        }
    }
}

List hieutaphop(List L1, List L2)
{
    List kq;
    makenullList(&kq);
    Position p = L1->Next;
    for (; p != NULL; p = p->Next)
    {
        if (member(p->Element, L2) == 0)
        {
            append(p->Element, &kq);
        }
    }
    return kq;
}
void printlist(List L)
{
    Position p = L->Next;
    for (; p != NULL; p = p->Next)
    {
        printf("%d ", p->Element);
    }
    printf("\n");
}

int main()
{
    List L1, L2, hieutap;
    readlist(&L1);
    readlist(&L2);
    hieutap = hieutaphop(L1, L2);
    printlist(L1);
    printlist(L2);
    printlist(hieutap);
    return 0;
}