#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct Node {
    ElementType Data;
    struct Node* Next;
} Node;

typedef struct {
    Node* Front;
    Node* Rear;
} Queue;

// Đã sửa tên hàm cho chuẩn
void makenullQueue(Queue *pQ) {
    pQ->Front = NULL;
    pQ->Rear = NULL;
}

int emptyQueue(Queue Q) {
    return Q.Front == NULL; 
}

void enQueue(ElementType x, Queue *pQ) {
    Node* newNode = (Node*)malloc(sizeof(Node));
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

void deQueue(Queue *pQ) {
    if (emptyQueue(*pQ)) {
        printf("Hang doi rong!\n");
    } else {
        Node* temp = pQ->Front;
        pQ->Front = pQ->Front->Next;
        free(temp);
        if (pQ->Front == NULL) {
            pQ->Rear = NULL;
        }
    }
}

void readQueue(ElementType n, Queue *pQ) {
    makenullQueue(pQ);
    int i;
    ElementType x;
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        enQueue(x, pQ);
    }
}

int timeQueue(Queue *pQ1, Queue *pQ2) {
    int t = 0;
    ElementType x;
    
    // SỬA LỖI 1: Phải lặp khi Q1 CHƯA RỖNG (== 0)
    while (emptyQueue(*pQ1) == 0) {
        if (pQ1->Front->Data == pQ2->Front->Data) {
            deQueue(pQ1);
            deQueue(pQ2);
            t++;
        } else {
            x = pQ1->Front->Data;
            deQueue(pQ1);
            enQueue(x, pQ1); // Thêm lại vào cuối hàng
            t++;
        }
    }
    return t;
}

int main() {
    int n;
    scanf("%d", &n);
    Queue Q1, Q2;
    
    readQueue(n, &Q1);
    readQueue(n, &Q2);
    
    // SỬA LỖI 2: In kết quả ra màn hình
    printf("%d\n", timeQueue(&Q1, &Q2));

    return 0;
}