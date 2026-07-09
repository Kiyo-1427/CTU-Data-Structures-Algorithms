#include <stdio.h>

// ============================================================================
// PHẦN 1: KHAI BÁO ẢO (DUMMY DATA) ĐỂ VS CODE KHÔNG BÁO LỖI ĐỎ
// (Chỉ để lừa trình biên dịch, không cần quan tâm phần này)
// ============================================================================
typedef int ElementType;
typedef int Position;
typedef struct
{
    ElementType Elements[100];
    Position Last;
} List;

// Khai báo nguyên mẫu các hàm cơ bản
Position locate(ElementType X, List L);
Position endList(List L);
void insertList(ElementType X, Position P, List *L);

// ============================================================================
// 🌟 TRICK 1: LỌC TRÙNG NGAY LÚC NHẬP DỮ LIỆU (Remove Duplicates on Input)
// Dùng khi: Đề bắt nhập danh sách nhưng các phần tử không được trùng nhau.
// Logic: Dùng hàm locate() dò trước, nếu == endList (không thấy) thì mới insert.
// ============================================================================
void trick_LocTrung_NhapDuLieu()
{
    List L1;
    int n1, x, i; // Khai báo biến ảo

    // ĐOẠN CODE COPY ĐỂ XÀI:
    for (i = 0; i < n1; i++)
    {
        scanf("%d", &x);
        if (locate(x, L1) == endList(L1))
        {
            insertList(x, L1.Last + 1, &L1);
        }
    }
}

// ============================================================================
// 🌟 TRICK 2: TÌM GIAO CỦA 2 DANH SÁCH (Intersection of 2 Lists)
// Dùng khi: Đề bắt tìm các phần tử chung của L1 và L2, nhét vào L3.
// Logic: Duyệt L1, lấy từng phần tử locate() trong L2. Nếu != endList -> nhét vào L3.
// ============================================================================
void trick_TimGiao_2_DanhSach()
{
    List L1, L2, L3;
    int i; // Khai báo biến ảo

    // ĐOẠN CODE COPY ĐỂ XÀI:
    for (i = 0; i < L1.Last; i++)
    {
        if (locate(L1.Elements[i], L2) != endList(L2))
        {
            insertList(L1.Elements[i], L3.Last + 1, &L3);
        }
    }
}