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

List getList()
{
    List Header;
    Header = (struct Node *)malloc(sizeof(struct Node));
    Header->Next = NULL;
    return Header;
}