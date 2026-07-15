#include<stdio.h>
#define MaxLength 100

typedef char ElementType;

typedef struct {
    ElementType Data[MaxLength];
    ElementType Top;
}Stack;

void makenullStack(Stack *pS){
    pS->Top=MaxLength;
}


int emptyStack(Stack S){
    return S.Top==MaxLength;
}

ElementType top(Stack S){
    return S.Data[S.Top];
}


void pop(Stack *pS){
    pS->Top++;
}


void push(ElementType x, Stack *pS){
    pS->Top--;
    pS->Data[pS->Top]=x;
}

void inThaplucphan(int n) {
    Stack S;
    makenullStack(&S); // Khởi tạo ngăn xếp rỗng
    
    // Bắt lỗi trường hợp số nhập vào là 0
    if (n == 0) {
        printf("0");
        return;
    }
    
    // Bước 1: Chia liên tục cho 16, ép kiểu sang ký tự rồi nạp vào Stack
    while (n > 0) {
        int du = n % 16;
        char kytu;
        
        if (du < 10) {
            kytu = du + '0';       // Biến số 0-9 thành ký tự '0'-'9'
        } else {
            kytu = du - 10 + 'A';  // Biến số 10-15 thành ký tự 'A'-'F'
        }
        
        push(kytu, &S);            // Đẩy trực tiếp KÝ TỰ vào Stack
        n /= 16;
    }
    
    // Bước 2: Rút từng ký tự từ đỉnh Stack ra và in lên màn hình
    while (emptyStack(S) == 0) {
        printf("%c", top(S));      // Dùng %c vì ElementType là char
        pop(&S);
    }
}


/* Mẹo: 'A' có mã ASCII là 65. giaTri - 10 + 65 sẽ ra đúng ký tự cần in!
            printf("%c", du - 10 + 'A'); // In chữ A -> F
            */


int main (){
    int n;
scanf("%d",&n);
inThaplucphan(n);
    return 0;
}


