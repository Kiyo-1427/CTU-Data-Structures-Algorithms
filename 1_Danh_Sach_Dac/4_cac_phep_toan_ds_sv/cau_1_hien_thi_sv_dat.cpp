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

void hienthiDat(DanhSach L)
{
    int i;
    float tong;
    for (i = 0; i < L.n; i++)
    {
        // Tính tổng điểm của sinh viên thứ i
        tong = L.A[i].DiemLT + L.A[i].DiemTH1 + L.A[i].DiemTH2;

        // Kiểm tra điều kiện ĐẠT (tổng điểm >= 4.0)
        if (tong >= 4.0)
        {
            // In ra theo đúng định dạng mẫu của hệ thống: MSSV - HoTen - DiemLT - DiemTH1 - DiemTH2 - Tong
            printf("%s - %s - %.2f - %.2f - %.2f - %.2f\n", L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2, tong);
        }
    }
}