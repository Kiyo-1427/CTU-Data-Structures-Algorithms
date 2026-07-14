#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char ID[10];
    char Name[50];
    float R1, R2, R3;
} Student;

struct Node
{
    Student Element;
    struct Node *Next;
};
typedef struct Node *List;

struct Node *locate(char ID[10], List L)
{
    struct Node *p = L;
    while (p->Next != NULL)
    {
        if (strcmp(ID, p->Next->Element.ID) == 0)
        {
            return p;
        }
        p = p->Next;
    }
    return p; // ĐÃ SỬA: Trả về p (nút cuối/nút Header) thay vì NULL để chống crash khi DS rỗng
}

List getList()
{
    List Header;
    Header = (struct Node *)malloc(sizeof(struct Node));
    Header->Next = NULL;
    return Header;
}

int append(Student s, List *pL)
{
    struct Node *p = locate(s.ID, *pL);

    if (p->Next != NULL)
    {
        return 0;
    }
    else
    {
        struct Node *t = (struct Node *)malloc(sizeof(struct Node));
        t->Element = s;
        t->Next = NULL;
        p->Next = t;
        return 1;
    }
}

List readList()
{
    int n, i;
    Student s;
    char st[50];
    List L = getList();
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf(" ");
        fgets(st, 10, stdin);
        if (st[strlen(st) - 1] == '\n')
            st[strlen(st) - 1] = '\0';
        strcpy(s.ID, st);
        fgets(st, 50, stdin);
        if (st[strlen(st) - 1] == '\n')
            st[strlen(st) - 1] = '\0';
        strcpy(s.Name, st);
        scanf("%f%f%f", &s.R1, &s.R2, &s.R3);

        if (append(s, &L) == 0)
        {
            printf("%s exists\n", s.ID);
        }
    }
    return L;
}

void printList(List L)
{
    float tb;
    int i = 1;
    struct Node *p = L;
    while (p->Next != NULL)
    {
        tb = (p->Next->Element.R1 + p->Next->Element.R2 + p->Next->Element.R3) / 3.0;
        // ĐÃ SỬA: Thay %2s thành %2d cho đúng định dạng kiểu int của biến i
        printf("%2d - %10s - %50s - %.3f - %.3f - %.3f - %.3f\n", i, p->Next->Element.ID,
               p->Next->Element.Name, p->Next->Element.R1, p->Next->Element.R2,
               p->Next->Element.R3, tb);
        i++;
        p = p->Next;
    }
}

void showPassedList(List L)
{
    float tb;
    int i = 1;
    struct Node *p = L;
    while (p->Next != NULL)
    {
        tb = (p->Next->Element.R1 + p->Next->Element.R2 + p->Next->Element.R3) / 3.0;
        if (tb >= 4.0)
        {

            printf("%2d - %10s - %50s - %.3f - %.3f - %.3f - %.3f\n", i, p->Next->Element.ID,
                   p->Next->Element.Name, p->Next->Element.R1, p->Next->Element.R2,
                   p->Next->Element.R3, tb);
            i++;
        }
        p = p->Next;
    }
    printf("%d students in total", i - 1);
}

List getFailedList(List L)
{
    List kq = getList();
    float tb;
    struct Node *p = L;
    while (p->Next != NULL)
    {
        tb = (p->Next->Element.R1 + p->Next->Element.R2 + p->Next->Element.R3) / 3.0;
        if (tb < 4.0)
        {
            append(p->Next->Element, &kq);
        }
        p = p->Next;
    }
    return kq;
}

int main()
{
    List L = readList();
    printList(L);
    List L1 = getFailedList(L);
    printList(L1);
    return 0;
}