#include <stdio.h>
#include <string.h> // Bắt buộc phải có để dùng hàm strcmp
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
#include <string.h> // Nhớ phải có thư viện này ở đầu file để dùng strcmp

int tim(char x[10], DanhSach L)
{
    int i;
    for (i = 0; i < L.n; i++)
    {
        // 1. Dùng strcmp để so sánh nội dung 2 chuỗi MSSV
        if (strcmp(L.A[i].MSSV, x) == 0)
        {
            // 2. Tìm thấy ở chỉ số mảng i, phải trả về Vị trí là i + 1
            return i + 1;
        }
    }
    // Không tìm thấy, trả về vị trí endList là n + 1
    return L.n + 1;
}
