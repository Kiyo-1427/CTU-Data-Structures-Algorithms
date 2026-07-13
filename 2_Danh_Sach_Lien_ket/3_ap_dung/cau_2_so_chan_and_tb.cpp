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
    // Tìm toa cuối cùng để móc vào
    Position last = *pL;
    while (last->Next != NULL)
    {
        last = last->Next;
    }
    last->Next = t;
}
void readlist(List *pL)
{
    int n, i;
    makenullList(pL);
    ElementType x;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        append(x, pL);
    }
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

float tbcong(List L)
{
    float s = 0;
    int n = 0;
    Position p = L->Next;
    for (; p != NULL; p = p->Next)
    {
        s += p->Element;
        n++;
    }
    return s / n;
}

List chepchan(List L)
{
    Position p = L->Next;
    List kq;
    makenullList(&kq);
    for (; p != NULL; p = p->Next)
    {
        if (p->Element % 2 == 0)
        {
            append(p->Element, &kq);
        }
    }
    return kq;
}

int main()
{

    float tb;
    List L, chan;
    readlist(&L);
    chan = chepchan(L);
    tb = tbcong(chan);
    printlist(L);
    printlist(chan);
    printf("%.3f", tb);
    return 0;
}