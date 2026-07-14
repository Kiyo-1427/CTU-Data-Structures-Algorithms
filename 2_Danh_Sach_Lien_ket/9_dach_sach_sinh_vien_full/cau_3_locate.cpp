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

struct Node*  locate(char x[10], List L){
    struct Node* p = L;
    while(p->Next !=NULL){
        if(strcmp(x,p->Next->Element.ID)==0){
            return p;
        }
        p=p->Next;
    }
    return NULL;
}