#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node {
    ElementType Data;
    struct Node *Next;
} Node;

typedef struct {
    Node *Front;
    Node *Rear;
} Queue;

// Khởi tạo hàng đợi rỗng
void makenullQueue(Queue *pQ) {
    pQ->Front = NULL;
    pQ->Rear = NULL;
}

// Kiểm tra rỗng
int emptyQueue(Queue Q) {
    return Q.Front == NULL;
}

// Thêm vào hàng đợi (E)
void enQueue(ElementType x, Queue *pQ) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->Data = x;
    newNode->Next = NULL;

    if (emptyQueue(*pQ)) {
        pQ->Front = newNode;
        pQ->Rear = newNode;
    } else {
        pQ->Rear->Next = newNode;
        pQ->Rear = newNode;
    }
}

// Xóa khỏi hàng đợi (D)
void deQueue(Queue *pQ) {
    if (!emptyQueue(*pQ)) { 
        Node *temp = pQ->Front;
        pQ->Front = pQ->Front->Next;
        free(temp); 
        if (pQ->Front == NULL) {
            pQ->Rear = NULL;
        }
    }
}

// Hàm đếm số lượng phần tử an toàn (không làm hỏng hàng đợi)
int soluong(Queue Q) {
    int count = 0;
    Node *p = Q.Front; 
    while (p != NULL) {
        count++;
        p = p->Next;
    }
    return count;
}

int main() {
    int n;
    scanf("%d", &n); // Đọc số lượng thao tác N

    Queue Q;
    makenullQueue(&Q);

    for (int i = 0; i < n; i++) {
        char op;
        // Khoảng trắng trước %c cực kỳ quan trọng để bỏ qua phím Enter/Space
        scanf(" %c", &op); 

        if (op == 'E') {
            int x;
            scanf("%d", &x); 
            enQueue(x, &Q);
            printf("%d\n", soluong(Q)); 
        } 
        else if (op == 'D') {
            if (emptyQueue(Q)) {
                // Rỗng thì in -1 và số lượng (chắc chắn là 0)
                printf("-1 0\n"); 
            } else {
                int val = Q.Front->Data;
                deQueue(&Q);
                printf("%d %d\n", val, soluong(Q));
            }
        }
    }

    return 0;
}