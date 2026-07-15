#include <stdio.h>
#include <string.h>
#define MaxLength 100

typedef char ElementType;

typedef struct
{
    ElementType Data[MaxLength];
    ElementType Top;
} Stack;

void makenullStack(Stack *pS)
{
    pS->Top = MaxLength;
}

int emptyStack(Stack S)
{
    return S.Top == MaxLength;
}

ElementType top(Stack S)
{
    return S.Data[S.Top];
}

void pop(Stack *pS)
{
    pS->Top++;
}

void push(ElementType x, Stack *pS)
{
    pS->Top--;
    pS->Data[pS->Top] = x;
}

int ktChuoi()
{
    Stack S;
    makenullStack(&S);
    char c[100];
    scanf(" %[^\r\n]", c);
    int n = strlen(c);
    int i;

    for (i = 0; i < n; i++)
    { // Đã sửa: i < n để tránh nuốt ký tự '\0'
        if (c[i] == '(')
        {
            push('(', &S);
        }
        else if (c[i] == ')')
        {
            if (emptyStack(S) == 0)
            {
                pop(&S); // Khớp cặp ngoặc mở-đóng thì xóa bớt '(' khỏi Stack
            }
            else
            {
                return 0; // Gặp ngoặc đóng ')' mà Stack rỗng -> Thừa ngoặc đóng -> Sai!
            }
        }
        // Các ký tự khác như chữ, số, dấu cách... thì bỏ qua, không làm gì cả
    }

    // Cuối cùng, nếu Stack rỗng hoàn toàn thì chuỗi mới đúng
    return emptyStack(S);
}

int main()
{
    int kq = ktChuoi();
    if (kq)
    {
        printf("Chuoi ngoac dung");
    }
    else
    {
        printf("Chuoi ngoac khong dung");
    }
    return 0;
}
