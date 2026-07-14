#include <stdio.h>
#include <string.h> // Bắt buộc phải có để dùng hàm strcmp
struct SinhVien
{
    char MSSV[10];
    char HoTen[50];
    float DiemLT, DiemTH1, DiemTH2;
};
typedef int ElementType;
typedef int Position;

typedef struct
{
    SinhVien A[40];
    int n;
} DanhSach;

DanhSach dsRong()
{
    DanhSach kq;
    kq.n = 0;
    return kq;
}
void chenCuoi(struct SinhVien s, DanhSach *pL)
{
    if (pL->n < 40)
    {
        pL->A[pL->n] = s;
        pL->n++;
    }
    else
    {
        printf("Loi! Danh sach day!");
    }
}

Position tim(char ch[], DanhSach L)
{
    int i;
    for (i = 0; i < L.n; i++)
    {
        if (strcmp(ch, L.A->MSSV) == 0)
        {
            return i + 1;
        }
    }
    return L.n + 1;
}

void xoaSinhVien(char x[], DanhSach *pL)
{
    Position p = tim(x, *pL);
    if (p != pL->n + 1)
    {
        xoaTai(p, pL);
    }
}

DanhSach chepKhongDat(DanhSach L)
{
    DanhSach kq;
    int i;
    float tong;
    for (i = 0; i < L.n; i++)
    {
        tong = L.A[i].DiemLT + L.A[i].DiemTH1 + L.A[i].DiemTH2;
        if (tong < 4.0)
        {
            chenCuoi(L.A[i], &kq);
        }
    }
    return kq;
}

int ktRong(DanhSach L)
{
    return L.n == 0;
}

void hienthi(DanhSach L)
{
    float tong;
    int i;
    for (i = 0; i < L.n; i++)
    {
        tong = L.A[i].DiemLT + L.A[i].DiemTH1 + L.A[i].DiemTH2;
        printf("%s - %s - %.2f - %.2f - %.2f - %.2f\n", L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2, tong);
    }
}

int xoaTai(int p, DanhSach *pL)
{
    int i;
    if (p <= 40 && p >= 1)
    {
        for (i = p - 1; i < pL->n - 1; i++)
        {
            pL->A[i] = pL->A[i + 1];
        }
        pL->n--;
        return 1;
    }
    else
    {
        return 0;
    }
}

void hienthiDat(DanhSach L)
{
    float tong;
    int i;
    for (i = 0; i < L.n; i++)
    {
        tong = L.A[i].DiemLT + L.A[i].DiemTH1 + L.A[i].DiemTH2;
        if (tong >= 4.0)
        {
            printf("%s - %s - %.2f - %.2f - %.2f - %.2f\n", L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2, tong);
        }
    }
}

int tim(char x[], DanhSach L)
{
    int i;
    for (i = 0; i < L.n; i++)
    {
        if (strcmp(L.A[i].MSSV, x) == 0)
        {
            return i + 1;
        }
    }
    return L.n + 1;
}

DanhSach nhap()
{
    DanhSach kq = dsRong();
    struct SinhVien s;
    int n, i;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%s", s.MSSV);

        scanf(" %[^\r\n]", s.HoTen);

        scanf("%f %f %f", &s.DiemLT, &s.DiemTH1, &s.DiemTH2);

        if (tim(s.MSSV, kq) == kq.n + 1)
        {
            chenCuoi(s, &kq);
        }
    }
    return kq;
}