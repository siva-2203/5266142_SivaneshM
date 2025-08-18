#include "demo.h"
#include "unity.h"
#include<string.h>

extern person group[3];

void test_adult(void)
{
    TEST_ASSERT_TRUE(isAdult(&group[0]));
    TEST_ASSERT_FALSE(isAdult(&group[1]));
}
void test_tallest(void)
{
    person *tall=tallest(group,3);
    TEST_ASSERT_EQUAL_STRING("aaddlin",tall->name);
}
void test_minor(void)
{
    TEST_IGNORE_MESSAGE("ignored");
    TEST_ASSERT_TRUE(all_minor(group,3));
}
void test_not_minor(void)
{
    TEST_ASSERT_FALSE(all_minor(group,3));
}