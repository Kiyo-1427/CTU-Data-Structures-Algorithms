#include <stdio.h>
#include <conio.h>
#define Maxlength 100
typedef int ElementType;
typedef int Position;
typedef struct
{
    ElementType Elements[Maxlength];
    Position Last;
} List;

// tạo danh sách rỗng
void makenullList(List *pL)
{
    pL->Last = 0;
}
// 2. Hàm kiểm tra phần tử x có nằm trong danh sách L hay không
// Trả về 1 nếu tìm thấy, trả về 0 nếu không tìm thấy
int member(ElementType x, List L)
{
    int i;
    for (i = 0; i < L.Last; i++)
    {
        if (L.Elements[i] == x)
        {
            return 1; // Đã tìm thấy
        }
    }
    return 0; // Quét hết mà không thấy
}

// 3. Hàm thêm phần tử x vào cuối danh sách
void insertSet(ElementType x, List *pL)
{
    // Đặt x vào vị trí ngay sau phần tử cuối cùng
    pL->Elements[pL->Last] = x;
    // Tăng số lượng phần tử lên
    pL->Last++;
}

// =======================================================
// HÀM CHÍNH: TÌM TẬP HỢP GIAO (INTERSECTION)
// =======================================================
void intersection(List L1, List L2, List *pL)
{
    int i;

    // Bước 1: Khởi tạo danh sách kết quả (pL) là rỗng
    makenullList(pL);

    // Bước 2: Duyệt qua từng phần tử của danh sách L1
    for (i = 0; i < L1.Last; i++)
    {

        // Bước 3: Kiểm tra xem phần tử hiện tại của L1 có nằm trong L2 không
        if (member(L1.Elements[i], L2) == 1)
        {

            // Nếu có, chèn phần tử đó vào danh sách kết quả pL
            insertSet(L1.Elements[i], pL);
        }
    }
}