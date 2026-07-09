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