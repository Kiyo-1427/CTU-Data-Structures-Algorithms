#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    char KyTu;
    struct Node *Next;
};
typedef struct Node *Cau;

int sotu(Cau d)
{
    struct Node *p = d->Next;
    int t = 0;
    int trong_tu = 0;
    while (p != NULL)
    {
        if (p->KyTu == ' ')
        {
            trong_tu = 0;
        }
        else
        {
            if (trong_tu == 0)
            {
                t++;
                trong_tu = 1;
            }
        }
        p = p->Next;
    }
    return t;
}

int main()
{
    // 1. Khởi tạo câu rỗng
    Cau d = (struct Node *)malloc(sizeof(struct Node));
    d->Next = NULL;
    struct Node *last = d;

    // 2. Nhập chuỗi từ bàn phím
    printf("Nhap cau can dem (Nhan Enter de ket thuc):\n");
    char c;
    while (scanf("%c", &c) && c != '\n')
    {
        struct Node *t = (struct Node *)malloc(sizeof(struct Node));
        t->KyTu = c;
        t->Next = NULL;
        last->Next = t;
        last = t;
    }

    // 3. Gọi hàm đếm số từ và in kết quả
    int ket_qua = sotu(d);
    printf("-----------------------------------\n");
    printf("So tu dem duoc trong cau la: %d\n", ket_qua);

    return 0;
}
