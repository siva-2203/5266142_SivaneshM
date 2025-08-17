#include<stdio.h>
#include "demo.h"
#include "unity.h"

void setUp(){}
void tearDown(){}

void test_sum_pos()
{
    TEST_ASSERT_EQUAL(3,sum(1,2));
    TEST_ASSERT_EQUAL(15,sum(5,10));
}
void test_sum_neg()
{
    TEST_ASSERT_EQUAL(-3,sum(-5,2));
    TEST_ASSERT_EQUAL(-15,sum(-25,10));
}
int main()
{
    int a=10,b=20,c,d;
    c=sum(a,b);
    d=square(a);
    int e=square(b);
    printf("The Sum is: %d\n ",c);
    printf("The Square is: %d%d\n ",d,e);
    UNITY_BEGIN();
    RUN_TEST(test_sum_pos);
    RUN_TEST(test_sum_neg);
    return UNITY_END();
}