#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef int ElementType;
typedef struct Node
{
    ElementType Element;
    struct Node *Next;
};

typedef Node *Position;
typedef Position List;

void deleteList(Position p, List *pL)
{
    Position t;
    if (p->Next != NULL)
    {
        p->Next = t;
        p->Next = p->Next->Next;
        free(t);
    }
    else
    {
        return;
    }
}
Position locate(ElementType x, List L)
{
    Position p = L;
    int count = 0;
    while (p->Next != NULL && count == 0)
    { // phải là p->next trảnh kiểm túi bóng ma p->Next->Element==x
        if (p->Next->Element == x)
        {
            count = 1;
        }
        else
        {
            p = p->Next;
        }
    }
    return p;
}

void removeAll(ElementType x, List *pL)
{
    // Tìm kiếm thằng x đầu tiên trong danh sách
    Position q = locate(x, *pL);

    // Chừng nào q->Next != NULL nghĩa là vẫn BẮT ĐƯỢC thằng x trong danh sách
    while (q->Next != NULL)
    {
        // Xóa luôn thằng x đó đi
        deleteList(q, pL);

        // Sau khi xóa xong, danh sách ngắn lại, ta lại gọi locate
        // để lùng xem còn thằng x nào khác vừa dồn lên không
        q = locate(x, *pL);
    }
}