#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    double he_so;
    int bac;
} DonThuc;

struct Node
{
    DonThuc e;
    struct Node *Next;
};
typedef struct Node *Position;
typedef Position DaThuc;

DaThuc khoitao()
{
    DaThuc L = (struct Node *)malloc(sizeof(struct Node));
    L->Next = NULL;
    return L;
}

void chenDonThuc(DonThuc e, DaThuc *pD)
{
    // Tạo một con trỏ chạy trỏ vào nút Header (nút giả)
    struct Node *p = *pD;

    // 1. Tìm vị trí thích hợp để chèn (giữ nguyên bậc giảm dần)
    while (p->Next != NULL && p->Next->e.bac > e.bac)
    {
        p = p->Next;
    }

    // 2. Nếu trùng bậc -> Cộng dồn hệ số
    if (p->Next != NULL && p->Next->e.bac == e.bac)
    {
        p->Next->e.he_so += e.he_so;
    }
    // 3. Nếu không trùng bậc -> Chèn nút mới vào sau p
    else
    {
        struct Node *t = (struct Node *)malloc(sizeof(struct Node));
        t->e = e;
        t->Next = p->Next;
        p->Next = t;
    }
}

// lỗi vô hạn

void inDaThuc(DaThuc d)
{
    Position p = d->Next;
    while (p != NULL)
    {
        printf("%.3fX^%d", p->e.he_so, p->e.bac);
        if (p->Next != NULL)
        {
            printf(" + ");
        }
        p = p->Next;
    }
}

DaThuc nhapDaThuc()
{
    DaThuc d = khoitao();
    int n, i;
    DonThuc e;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%lf %d", &e.he_so, &e.bac);
        chenDonThuc(e, &d);
    }
    return d;
}
int main()
{
    DaThuc d1 = nhapDaThuc();
    inDaThuc(d1);
    return 0;
}