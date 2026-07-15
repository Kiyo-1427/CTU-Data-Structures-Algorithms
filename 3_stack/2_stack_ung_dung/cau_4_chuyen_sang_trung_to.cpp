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

float tinhGiatri(char c[])
{
    Stack S;
    makenullStack(&S);
    int n = strlen(c);
    int i;
    float t1, t2, tong;

    for (i = 0; i < n; i++)
    {
        // Nếu là khoảng trắng thì bỏ qua (nếu đề có dấu cách giữa các số)
        if (c[i] == ' ')
        {
            continue;
        }

        // Nếu là chữ số từ '0' đến '9'
        if (c[i] >= '0' && c[i] <= '9')
        {
            // Đổi ký tự thành số và nạp vào Stack
            push((float)(c[i] - '0'), &S);
        }
        // Nếu là toán tử
        else if (c[i] == '*' || c[i] == '/' || c[i] == '+' || c[i] == '-')
        {
            // Lấy 2 toán hạng ra (Chú ý thứ tự t1, t2)
            t1 = top(S);
            pop(&S);
            t2 = top(S);
            pop(&S);

            // Xử lý biến 'tong' đang bị bỏ dở của huynh:
            if (c[i] == '+')
            {
                tong = t2 + t1;
            }
            else if (c[i] == '-')
            {
                tong = t2 - t1; // Lấy trái trừ phải
            }
            else if (c[i] == '*')
            {
                tong = t2 * t1;
            }
            else if (c[i] == '/')
            {
                tong = t2 / t1; // Lấy trái chia phải
            }

            // Tính xong thì NẠP kết quả ngược trở lại vào Stack
            push(tong, &S);
        }
    }

    // Kết thúc vòng lặp, giá trị cuối cùng còn sót lại ở đỉnh Stack chính là đáp án
    return top(S);
}