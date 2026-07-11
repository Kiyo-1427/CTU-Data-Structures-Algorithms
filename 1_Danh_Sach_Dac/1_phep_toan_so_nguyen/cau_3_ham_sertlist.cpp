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

// ý tưởng là lùi tất cả thằng từ p đến endlist về 1 vị trí, sau đó cho thằng p vào
void insertList(ElementType x, Position p, List *pL)
{
    // 1. Kiểm tra vị trí p có hợp lệ không (p phải từ 1 đến pL->Last + 1)
    // và danh sách chưa bị đầy (pL->Last < Maxlength) để chèn thằng x vào
    if (p >= 1 && p <= pL->Last + 1 && pL->Last < Maxlength)
    {
        Position i;
        for (i = pL->Last; i >= p; i--)
        {
            pL->Elements[i] == pL->Elements[i - 1];
        }
        pL->Elements[p - 1] = x;
        pL->Last++;
    }
}
int main()
{
    List L;
    int i;
    L.Last = 0;
    for (i = 0; i < 5; i++)
    {
        insertList(i * 2, L.Last + 1, &L);
    }
    for (i = 0; i < L.Last; i++)
    {
        printf("%d ", L.Elements[i]);
    }
    return 0;
}