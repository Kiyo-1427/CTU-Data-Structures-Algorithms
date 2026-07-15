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

int mucUutien(char op){
   if (op=='+' || op=='-')
       return 1;
   else if (op=='*' || op=='/')
       return 2;
}

void chuyenHauto(char trungto[], char hauto[]) {
    Stack S;
    makenullStack(&S);
    
    int i = 0; // Chỉ số để duyệt chuỗi trungto
    int j = 0; // Chỉ số để ghi vào chuỗi hauto
    
    // Duyệt từng ký tự c trong chuỗi trungto cho đến khi kết thúc chuỗi (\0)
    while (trungto[i] != '\0') {
        char c = trungto[i];
        
        // Bỏ qua nếu gặp khoảng trắng
        if (c == ' ') {
            i++;
            continue;
        }
        
        // 1. Nếu c là toán hạng (số hoặc chữ cái)
        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')) {
            hauto[j] = c;
            j++;
        }
        // 2. Nếu c là dấu ngoặc mở '('
        else if (c == '(') {
            push(c, &S);
        }
        // 3. Nếu c là dấu ngoặc đóng ')'
        else if (c == ')') {
            // Rút toán tử từ Stack ra hauto cho đến khi gặp '('
            while (emptyStack(S) == 0 && top(S) != '(') {
                hauto[j] = top(S);
                j++;
                pop(&S);
            }
            // Xóa dấu '(' ra khỏi ngăn xếp (Không đưa vào hauto)
            if (emptyStack(S) == 0 && top(S) == '(') {
                pop(&S); 
            }
        }
        // 4. Nếu c là toán tử (+, -, *, /)
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            // Rút các toán tử có độ ưu tiên >= c ra khỏi Stack
            while (emptyStack(S) == 0 && top(S) != '(' && mucUutien(c) <= mucUutien(top(S))) {
                hauto[j] = top(S);
                j++;
                pop(&S);
            }
            // Đẩy toán tử c hiện tại vào Stack
            push(c, &S);
        }
        
        i++; // Tiến tới ký tự tiếp theo
    }
    
    // 5. Đưa tất cả các toán tử còn sót lại trong Stack vào hauto
    while (emptyStack(S) == 0) {
        hauto[j] = top(S);
        j++;
        pop(&S);
    }
    
    // TỬ HUYỆT: Chốt hạ chuỗi hauto bằng ký tự rỗng để máy tính hiểu đó là kết thúc chuỗi
    hauto[j] = '\0';
}