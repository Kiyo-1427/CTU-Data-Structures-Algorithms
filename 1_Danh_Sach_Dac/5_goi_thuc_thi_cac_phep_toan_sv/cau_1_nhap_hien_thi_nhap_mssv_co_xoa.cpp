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
    // BẮT BUỘC PHẢI CÓ DÒNG NÀY ĐỂ CẬP NHẬT SỐ LƯỢNG VÀO DANH SÁCH
    pL->n = n;
    for (i = 0; i < n; i++)
    {
        scanf("%s", pL->A[i].MSSV);
        // Có khoảng trắng đầu tiên và chặn \r\n
        scanf(" %[^\r\n]", pL->A[i].HoTen);
        scanf("%f %f %f", &pL->A[i].DiemLT, &pL->A[i].DiemTH1, &pL->A[i].DiemTH2);
    }
}

int tim(char maSV[], DanhSach L)
{
    int i;
    for (i = 0; i < L.n; i++)
    {
        if (strcmp(L.A[i].MSSV, maSV) == 0)
        {
            return i + 1;
        }
    }
    return L.n + 1;
}

void in(DanhSach L)
{
    int i;
    for (i = 0; i < L.n; i++)
    {
        printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2);
    }
}

void xoa(int p, DanhSach *pL)
{
    int i;
    // pL->n-1 vì thằng ở cuối tối đa, biến sau còn có i+1
    for (i = p - 1; i < pL->n - 1; i++)
    {
        pL->A[i] = pL->A[i + 1];
    }
    pL->n--;
}

int main()
{
    char x[9];
    DanhSach L;
    dsRong(&L);
    nhap(&L);
    scanf("%s", x);
    in(L);
    int p = tim(x, L);
    if (p != L.n + 1)
    {
        printf("Tim thay sinh vien %s. Thong tin sinh vien:\n", x);
        // IN THÔNG TIN NGƯỜI ĐÓ RA TRƯỚC (Vì vị trí p tính từ 1 nên chỉ số mảng là p - 1)
        printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[p - 1].MSSV, L.A[p - 1].HoTen, L.A[p - 1].DiemLT, L.A[p - 1].DiemTH1, L.A[p - 1].DiemTH2);

        // SAU ĐÓ MỚI XÓA (Và không gọi in(L) nữa để khớp với Output của đề)
        xoa(p, &L);
    }
    else
    {
        printf("Khong tim thay sinh vien %s", x);
    }
    return 0;
}