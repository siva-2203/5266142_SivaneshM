#include "demo.h"

int all_minor(person* arr,int size)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i].age>=18)return 0;
    }
    return 1;
}