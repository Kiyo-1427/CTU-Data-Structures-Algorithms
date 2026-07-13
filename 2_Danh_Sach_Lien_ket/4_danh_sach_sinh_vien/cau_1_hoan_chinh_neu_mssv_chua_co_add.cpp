#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct Student{
    char ID[10];
    char Name[50];
    float R1, R2, R3;
}Student;

struct Node{
    Student Element;
    struct Node* Next;
};


typedef struct Node* Position;
typedef Position List;


List getList() {
    List Header; // Chỉ cần khai báo con trỏ cấp 1 bình thường
    
    // Xin cấp phát bộ nhớ cho Header
    Header = (struct Node*)malloc(sizeof(struct Node));
    
    // Khóa đuôi an toàn
    Header->Next = NULL;
    
    // Trả cái toa tàu vừa chế tạo xong ra cho bên ngoài xài
    return Header;
}

struct Node* locate(char ID[], List L){
    Position p = L->Next;
    for(; p !=NULL; p = p->Next){
        if(strcmp(p->Element.ID, ID)==0){
            return p;
        }
    }
    return NULL;
}


int append(Student s, List *pL){
    // ĐÃ SỬA 4: Kiểm tra trước, an toàn rồi mới tốn tiền mua toa tàu (malloc)
    if(locate(s.ID, *pL) == NULL){
        Position t = (Position)malloc(sizeof(struct Node));
        t->Element = s;
        t->Next = NULL;
        
        Position last = (*pL);
        while (last->Next != NULL){
            last = last->Next;
        }
        last->Next = t;
        return 1;
    } else {
        return 0;
    }
}

List readList()
{
	int n,i;
	Student s;
	char st[50];
	List L = getList(); // Khởi tạo danh sách rỗng
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf(" "); //skip some characters
		fgets(st,10,stdin);
		if (st[strlen(st)-1] == '\n')
			st[strlen(st)-1] = '\0';
		strcpy(s.ID, st);
		fgets(st,50,stdin);
		if (st[strlen(st)-1] == '\n')
			st[strlen(st)-1] = '\0';
		strcpy(s.Name, st);
		scanf("%f%f%f",&s.R1,&s.R2,&s.R3);
		if(append(s, &L)==0){
            printf("%s exists\n",s.ID);
        }
	}
	return L;
}    

int main(){
    List L;
    L = readList();
    struct Node *p=L;
while(p->Next!=NULL)
{						
   printf("%10s - %50s - %.3f - %.3f - %.3f\n",p->Next->Element.ID, 
      p->Next->Element.Name, p->Next->Element.R1, p->Next->Element.R2,
      p->Next->Element.R3);					
		
   p=p->Next;
}


     return 0;
}


