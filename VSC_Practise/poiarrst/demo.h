#ifndef __DEMO_H
#define __DEMO_H

typedef struct
{
    int age;
    char name[20];
    float height;
}person;

int isAdult(person *p);
person *tallest(person *arr,int size);
int all_minor(person *arr,int size);

#endif
