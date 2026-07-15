#include <stdio.h>
#define MaxLength 100
typedef struct
{
    int Data[MaxLength];
    int Top;
} NganXep;

void khoitao(NganXep *pS)
{
    pS->Top = MaxLength;
}

int giatriDinh(NganXep S)
{
    return S.Top;
}

int ktRong(NganXep S)
{
    return S.Top == MaxLength;
}

void xoa(NganXep *pS)
{
    if (ktRong(*pS))
    {
        printf("Loi! stack none");
    }
    else
    {
        pS->Top++;
    }
}

int ktDay(NganXep S)
{
    return S.Top == 0;
}

void them(int x, NganXep *pS)
{
    if (ktDay(*pS))
    {
        printf("Loi! stack full");
    }
    else
    {
        pS->Top--;
        pS->Data[pS->Top] = x;
    }
}

void hienthi(NganXep *pS)
{
    int i;
    // ĐÃ SỬA: Chạy từ CHỈ SỐ đỉnh (pS->Dinh) cho đến cuối mảng (SoPhanTu - 1)
    for (i = pS->Top; i < MaxLength; i++)
    {
        printf("%d ", pS->Data[i]); // Thường nhị phân in sát nhau nên đệ bỏ bớt dấu cách
    }
    printf("\n");
}
void doiNhiPhan(int n, NganXep *pS)
{
    khoitao(pS);

    // Xử lý trường hợp đặc biệt: n = 0
    if (n == 0)
    {
        them(0, pS);
        return;
    }

    int du;
    while (n > 0)
    {
        du = n % 2;
        them(du, pS);
        n /= 2;
    }
}
int main()
{

    NganXep S;
    int n;
    scanf("%d", &n);
    doiNhiPhan(n, &S);
    hienthi(&S);

    return 0;
}
