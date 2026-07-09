#include <stdio.h>
#include <conio.h>
#define Maxlength 100
typedef int ElementType;
typedef int Position;
typedef struct
{
    ElementType Elements[Maxlength];
    Position Last;
} List;

// tạo danh sách rỗng
void makenullList(List *pL)
{
    pL->Last = 0;
}
// thêm phần tử có nội dung X vào vị trí P trong danh sách L
void insertList(ElementType X, Position P, List *L)
{
    int i = 0;
    if (L->Last == Maxlength)
        printf("\ndanh sach da day !!!");
    else if ((P < 1) || (P > L->Last + 1))
        printf("\n vi tri khong hop le !!!");
    else
    {
        for (i = L->Last; i >= P; i--)
            L->Elements[i] = L->Elements[i - 1];
        L->Last++;
        L->Elements[P - 1] = X;
    }
}
void readList(List *pL)
{
    makenullList(pL);
    int i, n;
    ElementType x;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        insertList(x, i + 1, pL);
    }
}
