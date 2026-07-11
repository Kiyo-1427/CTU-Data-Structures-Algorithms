#include <stdio.h>
#include <math.h>
#define Maxlength 20
typedef int ElementType;
typedef int Position;
typedef struct
{
    ElementType Elements[Maxlength];
    int Last;
} List;
void makenullList(List *pL)
{
    (*pL).Last = 0;
}

int fullList(List L)
{
    return L.Last == Maxlength;
}

int emptyList(List L)
{
    return L.Last == 0;
}

Position first(List L)
{
    return 1;
}

Position endList(List L)
{
    return L.Last + 1;
}

Position next(Position P, List L)
{
    return P + 1;
}

Position previous(Position P, List L)
{
    return P - 1;
}

ElementType retrieve(Position P, List L)
{
    return L.Elements[P - 1];
}

void insertList(ElementType x, Position p, List *pL)
{
    if (fullList(*pL))
        printf("Danh sach day");
    else if ((p < 1) || (p > pL->Last + 1))
        printf("Vi tri khong hop le");
    else
    {
        Position q;
        for (q = pL->Last; q >= p; q--)
            pL->Elements[q] = pL->Elements[q - 1];
        pL->Elements[p - 1] = x;
        pL->Last++;
    }
}

// Ham xoa phan tu
void deleteList(Position P, List *L)
{
    if ((P > L->Last) || (P < 1))
        printf("\nVi tri khong hop le !!!");
    else if (emptyList(*L))
        printf("\nDanh sach rong !");
    else
    {
        Position i;
        for (i = P; i < L->Last; i++)
        {
            L->Elements[i - 1] = L->Elements[i];
        }
        L->Last--;
    }
}

// Tim vi tri dau tien chua x
Position locate(ElementType x, List L)
{
    Position p = first(L);
    int f = 0;
    while (p != endList(L) && f == 0)
    {
        if (retrieve(p, L) == x)
            f = 1;
        else
            p = next(p, L);
    }
    return p;
}
int main()
{
    List L1, L2, L3;
    makenullList(&L1);
    makenullList(&L2);
    makenullList(&L3);
    int i, j, n1, n2;
    ElementType x;
    scanf("%d", &n1);
    for (i = 0; i < n1; i++)
    {
        scanf("%d", &x);
        if (locate(x, L1) == endList(L1))
        {
            insertList(x, L1.Last + 1, &L1);
            insertList(x, L3.Last + 1, &L3);
        }
    }
    scanf("%d", &n2);
    for (i = 0; i < n2; i++)
    {
        scanf("%d", &x);
        if (locate(x, L2) == endList(L2))
        {
            insertList(x, L2.Last + 1, &L2);
        }
    }
    for (i = 0; i < L2.Last; i++)
    {
        if (locate(L2.Elements[i], L3) == endList(L3))
        {
            insertList(L2.Elements[i], L3.Last + 1, &L3);
        }
    }
    for (i = 0; i < L1.Last; i++)
    {
        printf("%d ", L1.Elements[i]);
    }
    printf("\n");
    for (i = 0; i < L2.Last; i++)
    {
        printf("%d ", L2.Elements[i]);
    }
    printf("\n");
    for (i = 0; i < L3.Last; i++)
    {
        printf("%d ", L3.Elements[i]);
    }
    return 0;
}
