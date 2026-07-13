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

void hienthi(Cau d) {
    // Bắt đầu từ toa đầu tiên chứa dữ liệu (bỏ qua Header)
    struct Node* p = d->Next; 
    
    // Duyệt qua từng ký tự cho đến cuối câu
    while (p != NULL) {
        printf("%c", p->KyTu);
        p = p->Next; // Chuyển sang ký tự tiếp theo
    }
    
    // Kết thúc việc hiển thị bằng 1 ký tự xuống dòng theo đúng yêu cầu đề bài
    printf("\n");
}
int main(){
struct Node* t;
Cau d = (struct Node*)malloc(sizeof(struct Node));
d->Next=NULL;

t = (struct Node*)malloc(sizeof(struct Node));
t->KyTu='e';
t->Next=d->Next;
d->Next=t;		
hienthi(d);
    return 0;
}