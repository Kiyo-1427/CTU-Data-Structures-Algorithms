#include <stdio.h>
#include <string.h>

struct SinhVien
{
    char MSSV[10];
    char HoTen[50];
    float DiemLT, DiemTH1, DiemTH2;
};

typedef struct
{
    struct SinhVien A[40];
    int n;
} DanhSach;

void dsRong(DanhSach *pL)
{
    pL->n = 0;
}

void nhap(DanhSach *pL)
{
    int n, i;
    scanf("%d", &n);
    pL->n = n;
    for (i = 0; i < n; i++)
    {
        // Đã bổ sung A[i]
        scanf("%s", pL->A[i].MSSV);
        scanf(" %[^\r\n]", pL->A[i].HoTen);
        scanf("%f %f %f", &pL->A[i].DiemLT, &pL->A[i].DiemTH1, &pL->A[i].DiemTH2);
    }
}

void in(DanhSach L)
{
    int i;
    for (i = 0; i < L.n; i++)
    {
        printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2);
    }
}

void chepDat(DanhSach L, DanhSach *pL)
{
    float tong;
    int i;
    for (i = 0; i < L.n; i++)
    {
        tong = L.A[i].DiemLT + L.A[i].DiemTH1 + L.A[i].DiemTH2;
        if (tong >= 4.0)
        {
            pL->A[pL->n] = L.A[i];
            pL->n++;
        }
    }
}

int main()
{
    DanhSach L;
    DanhSach kq;

    dsRong(&L);
    dsRong(&kq);

    nhap(&L);
    in(L);

    chepDat(L, &kq);

    if (kq.n > 0)
    {
        printf("Sinh vien DAT\n");
        in(kq);
    }

    return 0;
}