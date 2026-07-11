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
void dsRong(DanhSach *pL)
{
    pL->n = 0;
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

DanhSach chepKhongDat(DanhSach L)
{
    int i;
    DanhSach kq;
    float tong;
    /*// Hứng danh sách rỗng do hàm dsRong() TRẢ VỀ
    kq = dsRong();
    */
    dsRong(&kq);
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