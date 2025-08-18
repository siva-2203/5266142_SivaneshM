#include "demo.h"

person* tallest(person* arr,int size)
{
    person *tall=&arr[0];
    for(int i=0;i<size;i++)
    {
        if(arr[i].height>tall->height)
        {
            tall=&arr[i];
        }
    }
    return tall;
}