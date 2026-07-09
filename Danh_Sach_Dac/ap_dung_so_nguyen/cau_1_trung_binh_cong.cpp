#include <stdio.h>
#include <math.h>
#define Maxlength 20
typedef int ElementType;
typedef int Position;
typedef struct
{
    ElementType Elements[Maxlength];
    int Last;
} List;
void makenullList(List *pL)
{
    (*pL).Last = 0;
}

int fullList(List L)
{
    return L.Last == Maxlength;
}

int emptyList(List L)
{
    return L.Last == 0;
}

Position first(List L)
{
    return 1;
}

Position endList(List L)
{
    return L.Last + 1;
}

Position next(Position P, List L)
{
    return P + 1;
}

Position previous(Position P, List L)
{
    return P - 1;
}

ElementType retrieve(Position P, List L)
{
    return L.Elements[P - 1];
}

void insertList(ElementType x, Position p, List *pL)
{
    if (fullList(*pL))
        printf("Danh sach day");
    else if ((p < 1) || (p > pL->Last + 1))
        printf("Vi tri khong hop le");
    else
    {
        Position q;
        for (q = pL->Last; q >= p; q--)
            pL->Elements[q] = pL->Elements[q - 1];
        pL->Elements[p - 1] = x;
        pL->Last++;
    }
}

// Ham xoa phan tu
void deleteList(Position P, List *L)
{
    if ((P > L->Last) || (P < 1))
        printf("\nVi tri khong hop le !!!");
    else if (emptyList(*L))
        printf("\nDanh sach rong !");
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

// Tim vi tri dau tien chua x
Position locate(ElementType x, List L)
{
    Position p = first(L);
    int f = 0;
    while (p != endList(L) && f == 0)
    {
        if (retrieve(p, L) == x)
            f = 1;
        else
            p = next(p, L);
    }
    return p;
}
int main()
{
    List L;
    makenullList(&L);

    int n, i;
    ElementType x; // Khai báo thêm biến x để hứng giá trị nhập
    float t = 0;   // Biến tổng

    // 1. Nhập số lượng phần tử
    scanf("%d", &n);

    // 2. Vòng lặp nhập dữ liệu và đưa vào danh sách bằng insertList
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);          // Có dấu & chuẩn chỉ
        insertList(x, i + 1, &L); // Dùng hàm có sẵn, vừa chèn vừa tự tăng L.Last
        t += x;                   // Cộng dồn vào tổng
    }

    // 3. Vòng lặp chỉ làm DUY NHẤT nhiệm vụ in danh sách
    for (i = 0; i < L.Last; i++)
    {
        printf("%d ", L.Elements[i]);
    }

    // 4. In kết quả trung bình cộng ở NGOÀI vòng lặp (Định dạng %.3f theo đề bài trước nhé ca)
    printf("\n%.3f\n", t / n);

    return 0;
}
