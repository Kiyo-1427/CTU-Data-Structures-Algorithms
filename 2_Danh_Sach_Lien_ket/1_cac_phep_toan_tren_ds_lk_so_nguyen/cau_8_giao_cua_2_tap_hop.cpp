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

void makenullList(List *header)
{
    (*header) = (Node *)malloc(sizeof(Node));
    (*header)->Next = NULL;
}

void addFirst(ElementType x, List *L)
{
    // vì List bản chất là position mà position là con trỏ nên *L kiểu List là con trỏ cấp 2 cần truy cập thì phải thêm *L
    Position t = (Position)malloc(sizeof(struct Node));
    t->Element = x;
    t->Next = (*L)->Next;
    (*L)->Next = t;
}
int member(ElementType x, List L)
{
    Position p = L->Next;
    for (; p != NULL; p = p->Next)
    {
        if (p->Element == x)
        {
            return 1;
        }
    }
    return 0;
}

void append(ElementType x, List *L)
{
    // 1. Xin đất xây toa mới và nạp dữ liệu luôn
    Position p = (Position)malloc(sizeof(struct Node));
    p->Element = x;
    p->Next = NULL; // KHÓA ĐUÔI NGAY: Toa cuối cùng thì phía sau phải là NULL

    // 2. Phái một thằng culi xuất phát từ Đầu máy xe lửa để đi tìm đuôi tàu
    Position last = *L;

    // Vòng lặp tìm toa cuối: Cứ thằng sau mà khác NULL thì culi tiến lên tiếp
    while (last->Next != NULL)
    {
        last = last->Next;
    }

    // 3. Lúc này culi 'last' đã đứng ở toa cuối cùng thật sự.
    // Tiến hành móc toa mới p vào đuôi nó!
    last->Next = p;
}

List intersection(List L1, List L2)
{
    List kq;
    makenullList(&kq);
    Position p = L1->Next;
    while (p != NULL)
    { // ko được p->next != NULL v thì sẽ quên thằng cuối vì nếu p dc ở vị trí cuối nó chỉ vào khoảng không (NULL) ngay lập tức dừng chưa kịp tính thằng này
        if (member(p->Element, L2))
        {
            append(p->Element, &kq);
        }
        p = p->Next;
    }
    return kq;
}