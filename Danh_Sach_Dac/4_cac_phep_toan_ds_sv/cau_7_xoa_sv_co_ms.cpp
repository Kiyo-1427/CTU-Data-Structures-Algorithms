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
    return L.n + 1;
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

int xoaTai(int p, DanhSach *pL)
{
    // 1. Kiểm tra vị trí hợp lệ: p phải từ 1 đến n
    if (p < 1 || p > pL->n)
    {
        return 0; // Trả về 0 (Xóa thất bại)
    }

    int i;
    // 2. Dịch chuyển các phần tử phía sau lên trước để lấp chỗ trống
    // Vị trí p tương ứng với chỉ số p - 1 trong mảng
    for (i = p; i < pL->n; i++)
    {
        pL->A[i - 1] = pL->A[i]; // TUYỆT KỸ: Gán thẳng toàn bộ struct SinhVien cho nhau!
    }

    // 3. Giảm số lượng phần tử của danh sách đi 1
    pL->n--;

    // 4. Báo cáo xóa thành công
    return 1;
}

void xoaSinhVien(char maSV[], DanhSach *pL)
{
    // 1. Gọi p là vị trí của sinh viên có mã số maSV trong danh sách
    int p = tim(maSV, *pL);

    // 2. Nếu p là vị trí hợp lệ (khác vị trí endList là pL->n + 1)
    if (p != pL->n + 1)
    {
        // 3. Xóa sinh viên ở vị trí p trong danh sách
        xoaTai(p, pL);
    }
}
