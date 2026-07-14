#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
typedef struct
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
typedef struct Node *List;

struct Node*  locate(char ID[10], List L){
    struct Node* p = L;
    while(p->Next !=NULL){
        if(strcmp(ID,p->Next->Element.ID)==0){
            return p;
        }
        p=p->Next;
    }
    return NULL;
}

List getList()
{
    List Header;
    Header = (struct Node *)malloc(sizeof(struct Node));
    Header->Next = NULL;
    return Header;
}

int append(Student s, List *pL){
    // Gọi locate và giữ lại vị trí trả về
    struct Node* p = locate(s.ID, *pL);
    
    // Nếu nút kế tiếp KHÔNG bằng NULL, nghĩa là sinh viên s.ID ĐÃ TỒN TẠI
    if(p->Next != NULL){
        return 0; 
    }
    // Nếu nút kế tiếp bằng NULL, nghĩa là CHƯA TỒN TẠI 
    // Và hiện tại p đang đứng ngay tại nút cuối cùng luôn!
    else {
        struct Node* t = (struct Node*)malloc(sizeof(struct Node));
        t->Element = s;
        t->Next = NULL;
        
        // Móc trực tiếp vào p (vì p chính là nút đuôi do locate trả về)
        p->Next = t; 
        return 1;
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
     // Nếu mã sinh viên chưa có thì chèn vào danh sách
		if (append(s, &L) == 0) {
			printf("%s exists\n", s.ID);
		}

	}
	return L;
}    
