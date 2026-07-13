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

void hien(List L)
{
    Position p = L->Next;
    for (; p != NULL; p = p->Next)
    {
        printf("%d ", p->Element);
    }
    printf("\n");
}
void addfirst(ElementType x, List *pL)
{
    Position t = (Position)malloc(sizeof(struct Node));
    t->Element = x;
    t->Next = (*pL)->Next;
    (*pL)->Next = t;
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
void nhap(List *pL)
{
    int n, i;
    makenullList(pL);
    ElementType x;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if (member(x, *pL) == 0)
        {
            addfirst(x, pL);
        }
    }
}

List hop(List pL1, List pL2)
{
    List kq;
    makenullList(&kq);
    Position p = (pL1)->Next;
    Position q = (pL2)->Next;
    for (; p != NULL; p = p->Next)
    {
        append(p->Element, &kq);
    }
    for (; q != NULL; q = q->Next)
    {
        if (member(q->Element, kq) == 0)
        {
            append(q->Element, &kq);
        }
    }
    return kq;
}

int main()
{

    List L1, L2, unionlist;
    nhap(&L1);
    nhap(&L2);
    unionlist = hop(L1, L2);
    hien(L1);
    hien(L2);
    hien(unionlist);

    return 0;
}
