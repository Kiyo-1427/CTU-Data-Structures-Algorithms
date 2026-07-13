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

int demHoa(Cau d){
    int t= 0;
    struct Node* p= d->Next;
    for(; p !=NULL; p = p->Next){
        if(p->KyTu >= 'A' && p->KyTu <= 'Z'){
            t++;
        }
    }
    return t;

}
int main(){
    struct Node* t;
Cau d = (struct Node*)malloc(sizeof(struct Node));
d->Next=NULL;

t = (struct Node*)malloc(sizeof(struct Node));
t->KyTu='E';
t->Next=d->Next;
d->Next=t;		
printf("%d",demHoa(d));
    return 0;
}