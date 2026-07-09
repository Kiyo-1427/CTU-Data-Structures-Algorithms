#include <stdio.h>
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