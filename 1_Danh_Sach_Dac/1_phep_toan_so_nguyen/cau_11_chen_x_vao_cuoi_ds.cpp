#include <stdio.h>
#include <conio.h>
#define Maxlength 100
typedef int ElementType;
typedef int Position;
typedef struct
{
    ElementType Elements[Maxlength];
    Position Last;
} List;

void insertSet(ElementType x, List *pL)
{
    pL->Elements[pL->Last] = x;
    pL->Last++;
}