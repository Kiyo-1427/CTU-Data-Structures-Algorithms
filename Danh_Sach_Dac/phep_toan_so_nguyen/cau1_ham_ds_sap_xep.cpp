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
void makeNull_List(List *L)
{
    L->Last = 0;
}
// hàm kiểm tra danh sách rỗng
int Empty_List(List L)
{
    return (L.Last == 0);
}

// hàm kiểm tra danh sách đầy
int Full_List(List L)
{
    return (L.Last == Maxlength);
}

// hàm trả về vị trí phần tử đầu tiên trong danh sách
Position FirstList(List L)
{
    return 1;
}

// hàm trả về vị trí cuối cùng của phần tử trong danh sách
Position EndList(List L)
{
    return L.Last + 1;
}

// hàm trả về vị trí phần tử kế tiếp phàn tử P trng danh sách L
Position Next(Position P, List L)
{
    return P + 1;
}

// hàm trả về vị trí phàn tử trước vị trí P trong danh sách L
Position Previous(Position P, List L)
{
    return P - 1;
}

// hàm trả về nội dung phần tử tại vị trí P trong danh sách L
ElementType Retrieve(Position P, List L)
{
    return L.Elements[P - 1];
}

// thêm phần tử có nội dung X vào vị trí P trong danh sách L
void Insert_List(ElementType X, Position P, List *L)
{
    int i = 0;
    if (L->Last == Maxlength)
        printf("\ndanh sach da day !!!");
    else if ((P < 1) || (P > L->Last + 1))
        printf("\n vi tri khong hop le !!!");
    else
    {
        for (i = L->Last; i >= P; i--)
            L->Elements[i] = L->Elements[i - 1];
        L->Last++;
        L->Elements[P - 1] = X;
    }
}

// xóa phần tử tại vị trí p trong danh sách
void Delete_List(Position P, List *L)
{
    if ((P > L->Last) || (P < 1))
        printf("\nvi tri khng hop le !!!");
    else if (Empty_List(*L))
        printf("\ndanh sach rong !");
    else
    {
        Position i;
        for (i = P; i < L->Last; i++)
        {
            L->Elements[i - 1] = L->Elements[i];
        }
        L->Last--;
    }
}

// in danh sách L ra màn hình
void Print_List(List L)
{
    Position P;
    P = FirstList(L);
    printf("\nbat dau in danh sach");
    while (P != EndList(L))
    {
        printf("\n%d", Retrieve(P, L));
        P = Next(P, L);
    }
    printf("\nket thuc in danh sach");
}

// nhập danh sách từ bàn phím
void Read_List(List *L)
{
    int i, N;
    ElementType X;
    makeNull_List(L);
    printf("\nnhap vao so phan tu trong danh sach");
    scanf("%d", &N);
    fflush(stdin);
    for (i = 1; i <= N; i++)
    {
        printf("\nphan tu thu %d la", i);
        scanf("%d", &X);
        fflush(stdin);
        Insert_List(X, EndList(*L), L);
    }
}
// hàm tìm về phần tử đầu tiên có nọi dung X trong danh sách L nếu không tìm thấy, hàm trả về vị trí EndList
Position Locate(ElementType X, List L)
{
    Position P;
    int found = 0;
    P = FirstList(L);
    while ((P != EndList(L)) && (found == 0))
    {
        if (Retrieve(P, L) == X)
            found = 1;
        else
            P = Next(P, L);
    }
    return P;
}

/*
Hãy viết hàm sắp xếp danh sách
Tên hàm (function name): sort()
Tham số (parameters):
pL - con trỏ kiểu List
Kiểu trả về: Không
for example
test:
List L;
int i;
L.Last = 0;
for(i=5;i>=1;i--){
    L.Elements[5-i] = 2*i;
}
L.Last = 5;
sort(&L);

for(i=0;i<L.Last;i++){
    printf("%d ",L.Elements[i]);
}
Result:
2 4 6 8 10
*/
// =================================================================
// PHẦN 2: CODE CỦA HÀO CA
// =================================================================
void sort(List *pL)
{
    Position p, q;
    ElementType temp; // Đã sửa từ Elememts thành ElementType chuẩn chỉnh

    // Vị trí đầu tiên luôn là 1. Vị trí kề cuối chính là pL->Last - 1
    for (p = 1; p < pL->Last; p++)
    {

        // q chạy từ p + 1 đến phần tử cuối cùng là pL->Last
        for (q = p + 1; q <= pL->Last; q++)
        {

            // So sánh trực tiếp phần tử trong mảng (vị trí p tương ứng chỉ số p-1)
            if (pL->Elements[p - 1] > pL->Elements[q - 1])
            {
                temp = pL->Elements[p - 1];
                pL->Elements[p - 1] = pL->Elements[q - 1];
                pL->Elements[q - 1] = temp;
            }
        }
    }
}
int main()
{
    List L;
    int i;
    L.Last = 0;

    for (i = 5; i >= 1; i--)
    {
        L.Elements[5 - i] = 2 * i;
    }
    L.Last = 5;

    sort(&L);

    for (i = 0; i < L.Last; i++)
    {
        printf("%d ", L.Elements[i]);
    }

    return 0;
}