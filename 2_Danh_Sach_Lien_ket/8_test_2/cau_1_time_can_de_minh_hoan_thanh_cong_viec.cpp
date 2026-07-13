#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

typedef int ElemtType;
struct Node
{
    ElemtType Element;
    struct Node *Next;
};
typedef struct Node *Position;
typedef Position List;

void makenullList(List *Heafer)
{
    (*Heafer) = (struct Node *)malloc(sizeof(struct Node));
    (*Heafer)->Next = NULL;
}

void append(ElemtType x, List *pL)
{
    Position p = (*pL);
    Position t = (Position)malloc(sizeof(struct Node));
    t->Element = x;
    t->Next = NULL;
    while (p->Next != NULL)
    {
        p = p->Next;
    }
    p->Next = t;
}

void readlist(int n, List *pL)
{
    int i;
    ElemtType x;
    makenullList(pL);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        append(x, pL);
    }
}

void deleteList(List *pL)
{
    if ((*pL)->Next == NULL)
        return;               // Bảo vệ an toàn nếu DS rỗng
    Position t = (*pL)->Next; // Trỏ vào phần tử đầu thật sự
    (*pL)->Next = t->Next;    // Cắt xích, nối tắt qua phần tử tiếp theo
    free(t);                  // Giải phóng vùng nhớ
}

int timethuchien(List *pL1, List *pL2)
{
    Position p = (*pL1);
    int s = 0;
    Position q = (*pL2);
    while (p->Next != NULL && q->Next != NULL)
    {
        if (p->Next->Element == q->Next->Element)
        {
            deleteList(pL1);
            deleteList(pL2);
            s++;
        }
        else
        {
            ElemtType val = p->Next->Element; // Lấy giá trị của công việc đầu tiên thật sự
            deleteList(pL1);                  // Xóa nó khỏi đầu danh sách
            append(val, pL1);                 // Chèn lại vào cuối danh sách
            s++;
        }
    }
    return s;
}

int main()
{
    int n, timelam;
    List L1, L2;
    scanf("%d", &n);
    readlist(n, &L1);
    readlist(n, &L2);
    timelam = timethuchien(&L1, &L2);
    printf("%d", timelam);
    return 0;
}
