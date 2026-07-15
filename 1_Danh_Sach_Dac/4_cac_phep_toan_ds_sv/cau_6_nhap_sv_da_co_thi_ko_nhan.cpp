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

// Hàm tìm sinh viên theo MSSV.
// Trả về vị trí (chỉ số i) nếu tìm thấy, nếu không thấy trả về -1
int tim(char maSV[], DanhSach L)
{
    int i;
    for (i = 0; i < L.n; i++)
    {
        if (strcmp(L.A[i].MSSV, maSV) == 0)
        {
            return i;
        }
    }
    return -1;
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

DanhSach nhap()
{
    DanhSach L;
    /* vì đề bài cho là Khởi tạo và trả về 1 danh sách rỗng - dsRong()
    L = dsRong();
    */
    dsRong(&L);
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        struct SinhVien s; // Tạo một biến sinh viên tạm thời để hứng dữ liệu

        // 1. Nhập thông tin cho sinh viên tạm thời s từ bàn phím
        scanf("%s", s.MSSV);       //%s là chuỗi nó là 1 cái mảng nên không cần &
        scanf(" %[^\n]", s.HoTen); // Mẹo đọc chuỗi có khoảng trắng (Họ tên)
        scanf("%f %f %f", &s.DiemLT, &s.DiemTH1, &s.DiemTH2);

        if (tim(s.MSSV, L) == L.n+1)
        {
            chenCuoi(s, &L);
        }
    }
    return L;
}

void hienthi(DanhSach L){
    float tong;
    int i;
    for(i = 0; i< L.n;i++){
        tong = L.A[i].DiemLT + L.A[i].DiemTH1 + L.A[i].DiemTH2;
        printf("%s - %s - %.2f - %.2f - %.2f - %.2f\n",L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2, tong);
    }
}
