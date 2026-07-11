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

void copyEvenNumbers(List L1, List *pL2)
{
    // Bước 1: Làm rỗng danh sách kết quả
    makenullList(pL2);

    int i;
    // Bước 2: Duyệt qua danh sách L1
    for (i = 0; i < L1.Last; i++)
    {

        // Bước 3: Nếu là số chẵn
        if (L1.Elements[i] % 2 == 0)
        {

            // Bước 4: Chèn giá trị đó vào VỊ TRÍ CUỐI CÙNG của pL2
            insertList(L1.Elements[i], pL2->Last + 1, pL2);
        }
    }
}