#include <stdio.h>
#include<string.h>
#define MaxLength 80
typedef struct{
    char Data[MaxLength];
    int n;
}Line;
void appendChar(char ch, Line *pL){
    pL->Data[pL->n]=ch;
    pL->n++;
}


void initLine(Line *pL){
    pL->n=0;
}

void readLine(Line *pL)
{
   char st[MaxLength];
   initLine(pL);
   fgets(st, MaxLength, stdin);
   if (st[strlen(st)-1]=='\n')
	st[strlen(st)-1]='\0';
   
   /*Đưa từng ký tự của st vào dòng văn bản chỉ bởi con trỏ pL. SINH VIÊN ĐIỀN VÀO ĐÂY*/

   {
    int i;
    for(i = 0; i < strlen(st); i++){
        // Chỉ nối các ký tự chữ, CẤM nối các ký tự ẩn \r hoặc \n
        if(st[i] != '\r' && st[i] != '\n'){
            appendChar(st[i], pL);
        }
    }
}
}    

int main(){
    int i;
    Line L;
    readLine(&L);
    for(i=0;i<=L.n-1;i++)
      printf("%c", L.Data[i]);
    return 0;
}