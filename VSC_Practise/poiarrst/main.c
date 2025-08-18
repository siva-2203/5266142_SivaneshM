#include<stdio.h>
#include"demo.h"
#include "unity.h"
#include<string.h>

person group[3];
void setUp(void)
{
    group[0].age=18;
    strcpy(group[0].name,"alice");
    group[0].height=162.8f;

    group[1].age=15;
    strcpy(group[1].name,"sam");
    group[1].height=102.8f;

    group[2].age=50;
    strcpy(group[2].name,"aaddlin");
    group[2].height=192.8f;
    
}

void tearDown(void)
{}

void test_adult(void);
void test_tallest(void);
void test_minor(void);
void test_not_minor(void);

int main()
{
    UNITY_BEGIN();
    RUN_TEST(test_adult);
    RUN_TEST(test_tallest);
    RUN_TEST(test_minor);
    RUN_TEST(test_not_minor);
    return UNITY_END();
}