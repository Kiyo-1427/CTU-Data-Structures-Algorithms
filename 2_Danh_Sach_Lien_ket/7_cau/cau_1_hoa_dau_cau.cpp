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

void chuanhoa(Cau *pd){
    struct Node* p = (*pd)->Next;
    int is_first = 1; // Cờ đánh dấu: 1 là đầu từ, 0 là thân từ
    
    while(p != NULL) {
        if(p->KyTu == ' ') {
            is_first = 1; // Gặp khoảng trắng thì bật cờ để chữ tiếp theo viết hoa
        } else {
            // Nếu là chữ cái đầu từ -> Chuyển thành HOA
            if(is_first == 1) {
                if(p->KyTu >= 'a' && p->KyTu <= 'z') {
                    p->KyTu -= 32;
                }
                is_first = 0; // Xử lý xong chữ đầu, hạ cờ để các chữ sau viết thường
            } 
            // Nếu là chữ cái thân từ -> Chuyển thành thường
            else {
                if(p->KyTu >= 'A' && p->KyTu <= 'Z') {
                    p->KyTu += 32;
                }
            }
        }
        p = p->Next; // Tiến tới ký tự tiếp theo
    }
}



int main() {
    // 1. Khởi tạo câu rỗng (có nút Header)
    Cau d = (struct Node*)malloc(sizeof(struct Node));
    d->Next = NULL;
    struct Node* last = d;

    // 2. Nhập trực tiếp từ bàn phím
    printf("Nhap chuoi (Nhan Enter de ket thuc): ");
    char c;
    while (scanf("%c", &c) && c != '\n') {
        struct Node* t = (struct Node*)malloc(sizeof(struct Node));
        t->KyTu = c;
        t->Next = NULL;
        last->Next = t;
        last = t;
    }

    // 3. Gọi hàm xử lý
    chuanhoa(&d);

    // 4. In kết quả ra xem thử
    printf("Ket qua sau chuan hoa: ");
    struct Node* p = d->Next;
    while (p != NULL) {
        printf("%c", p->KyTu);
        p = p->Next;
    }
    printf("\n");

    return 0;
}

