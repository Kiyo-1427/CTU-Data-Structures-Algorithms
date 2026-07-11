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

Position locate(ElementType x, List L)
{
    int i;
    for (i = 0; i < L.Last; i++)
    {
        if (L.Elements[i] == x)
        {
            return i + 1;
        }
    }
    return L.Last + 1;
}

void deleteList(Position p, List *pL)
{
    // Bước 1: Kiểm tra vị trí xóa có hợp lệ không
    // Vị trí xóa phải từ 1 đến pL->Last (không thể xóa ô trống ngoài biên)
    if (p >= 1 && p <= pL->Last)
    {

        Position i;
        // Bước 2: Vòng lặp dồn hàng sang trái
        // Ta bắt đầu chạy từ vị trí p (chỉ số mảng là p-1) cho đến sát nút cuối cùng
        for (i = p - 1; i < pL->Last - 1; i++)
        {
            pL->Elements[i] = pL->Elements[i + 1]; // Ô sau đè lên ô trước
        }

        // Bước 3: Giảm số lượng phần tử của danh sách đi 1
        pL->Last--;
    }
}

void removeAll(ElementType x, List *pL)
{
    Position p = locate(x, *pL); // Nhớ truyền *pL vì locate đòi cái hộp thật
    while (p != pL->Last + 1)
    {
        deleteList(p, pL);
        // CẬP NHẬT LẠI P: Tiếp tục tìm xem còn thằng x nào nữa không
        p = locate(x, *pL);
    }
}
