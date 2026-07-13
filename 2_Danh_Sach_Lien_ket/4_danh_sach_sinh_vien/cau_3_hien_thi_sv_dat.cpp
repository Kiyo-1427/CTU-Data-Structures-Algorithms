#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct Student
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

typedef struct Node *Position;
typedef Position List;

List getList()
{
    List Header; // Chỉ cần khai báo con trỏ cấp 1 bình thường

    // Xin cấp phát bộ nhớ cho Header
    Header = (struct Node *)malloc(sizeof(struct Node));

    // Khóa đuôi an toàn
    Header->Next = NULL;

    // Trả cái toa tàu vừa chế tạo xong ra cho bên ngoài xài
    return Header;
}
struct Node *locate(char ID[], List L)
{
    Position p = L->Next;
    for (; p != NULL; p = p->Next)
    {
        if (strcmp(p->Element.ID, ID) == 0)
        {
            return p;
        }
    }
    return NULL;
}

int append(Student s, List *pL)
{
    // ĐÃ SỬA 4: Kiểm tra trước, an toàn rồi mới tốn tiền mua toa tàu (malloc)
    if (locate(s.ID, *pL) == NULL)
    {
        Position t = (Position)malloc(sizeof(struct Node));
        t->Element = s;
        t->Next = NULL;

        Position last = (*pL);
        while (last->Next != NULL)
        {
            last = last->Next;
        }
        last->Next = t;
        return 1;
    }
    else
    {
        return 0;
    }
}

List readList()
{
    int n, i;
    Student s;
    char st[50];
    List L = getList(); // Khởi tạo danh sách rỗng
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf(" "); // skip some characters
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
    // Duyệt qua danh sách L và hiển thị giá trị lên màn hình
    /*Khi hiển thị thì tính luôn điểm tống hợp với điểm tổng hợp là trung bình cộng của R1, R2, R3*/
    Position p = L->Next;
    int i = 1;
    while (p != NULL)
    {
        // Tính điểm tổng hợp (chia cho 3.0 để ép kiểu float)
        float avg = (p->Element.R1 + p->Element.R2 + p->Element.R3) / 3.0;

        // In chuẩn chỉnh từng khoảng trắng theo mẫu test case
        printf("%2d - %10s - %50s - %.3f - %.3f - %.3f - %.3f\n",
               i, p->Element.ID, p->Element.Name, p->Element.R1, p->Element.R2, p->Element.R3, avg);

        i++;         // Tăng số thứ tự
        p = p->Next; // Tiến tới sinh viên tiếp theo
    }
}

void showPassedList(List L)
{
    float tb;
    struct Node *p = L->Next;
    int i = 1;
    while (p != NULL)
    {
        tb = (p->Element.R1 + p->Element.R2 + p->Element.R3) / 3.0;
        if (tb >= 4.0)
        {
            printf("%2d - %10s - %50s - %.3f - %.3f - %.3f - %.3f\n",
                   i, p->Element.ID, p->Element.Name, p->Element.R1, p->Element.R2, p->Element.R3, tb);

            i++;
        }
        p = p->Next;
    }
    printf("%d students in total\n", i - 1);
}

int main()
{
    List L = readList();
    printList(L);
    showPassedList(L);
    return 0;
}