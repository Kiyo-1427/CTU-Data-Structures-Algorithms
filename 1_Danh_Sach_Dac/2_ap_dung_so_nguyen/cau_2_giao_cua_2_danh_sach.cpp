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
    List L1, L2, L3;
    makenullList(&L1);
    makenullList(&L2);
    makenullList(&L3);

    int n1, n2, i;
    ElementType x;

    // ==========================================
    // 1. NHẬP L1 (Kết hợp lọc trùng)
    // ==========================================
    scanf("%d", &n1);
    for (i = 0; i < n1; i++)
    {
        scanf("%d", &x);

        // ĐÂY CHÍNH LÀ PHÉP LỌC TRÙNG:
        // Nếu tìm x trong L1 mà kết quả trả về bằng cọc biên giới (KHÔNG TÌM THẤY)
        if (locate(x, L1) == endList(L1))
        {
            insertList(x, L1.Last + 1, &L1); // Thì mới chèn vào!
        }
    }

    // ==========================================
    // 2. NHẬP L2 (Kết hợp lọc trùng)
    // ==========================================
    scanf("%d", &n2);
    for (i = 0; i < n2; i++)
    {
        scanf("%d", &x);

        // SỬA L1 THÀNH L2 Ở DÒNG NÀY:
        // Tìm x trong L2, nếu không có thì chèn vào L2
        if (locate(x, L2) == endList(L2))
        {
            insertList(x, L2.Last + 1, &L2);
        }
    }

    // ==========================================
    // 3. TÌM TẬP HỢP GIAO (L3 = L1 Giao L2)
    // ==========================================
    for (i = 0; i < L1.Last; i++)
    {
        // Lấy từng thằng của L1, dùng hàm locate đem đi dò trong L2
        // Nếu kết quả trả về KHÁC cọc biên giới (endList) -> Tức là TÌM THẤY!
        if (locate(L1.Elements[i], L2) != endList(L2))
        {

            // Tìm thấy thì nhét nó vào đuôi danh sách L3
            insertList(L1.Elements[i], L3.Last + 1, &L3);
        }
    }

    // ==========================================
    // 4. IN KẾT QUẢ RA MÀN HÌNH
    // ==========================================
    for (i = 0; i < L1.Last; i++)
    {
        printf("%d ", L1.Elements[i]);
    }
    printf("\n");

    for (i = 0; i < L2.Last; i++)
    {
        printf("%d ", L2.Elements[i]);
    }
    printf("\n");

    for (i = 0; i < L3.Last; i++)
    {
        printf("%d ", L3.Elements[i]);
    }
    printf("\n");

    return 0;
}
