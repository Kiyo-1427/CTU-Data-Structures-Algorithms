#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    char KyTu;
    struct Node *Next;
};
typedef struct Node *Cau;

void chenKyTu(char c, Cau *pd)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = (*pd);
    p->KyTu = c;
    p->Next = NULL;
    while (last->Next != NULL)
    {
        last = last->Next;
    }
    last->Next = p;
}

int main()
{
    struct Node *p;
    Cau d = (struct Node *)malloc(sizeof(struct Node));
    d->Next = NULL;
    chenKyTu('A', &d);
    chenKyTu('B', &d);
    p = d;
    printf("%c%c", p->Next->KyTu, p->Next->Next->KyTu);
    return 0;
}
