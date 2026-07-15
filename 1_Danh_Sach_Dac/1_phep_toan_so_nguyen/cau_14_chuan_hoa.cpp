
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

void normalize(List *pL)
{
    int i, j;
    for (i = 0; i < pL->Last; i++)
    {
        for (j = i + 1; j < pL->Last; j++)
        {
            if (pL->Elements[i] == pL->Elements[j])
            {
                // Gọi hàm xóa ở vị trí j + 1
                deleteList(j + 1, pL);

                // TUYỆT KỸ TRÁNH NHẢY CÓC: Lùi j lại 1 bước!
                // Vì danh sách đã co lại và dồn lên, ta phải xét lại chính vị trí j này.
                j--;
            }
        }
    }
}
int main()
{
    List L;
    int i;
    L.Last = 6;
    L.Elements[0] = 0;
    L.Elements[1] = 14;
    L.Elements[2] = 10;
    L.Elements[3] = -100;
    L.Elements[4] = 14;
    L.Elements[5] = 14;
    normalize(&L);
    for (i = 0; i < L.Last; i++)
    {
        printf("%d ", L.Elements[i]);
    }
    return 0;
}