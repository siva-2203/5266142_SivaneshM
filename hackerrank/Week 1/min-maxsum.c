#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

/*
 * Complete the 'miniMaxSum' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void miniMaxSum(int arr_count, int* arr)
{
    for(int i=0;i<arr_count;i++)
    {
        for(int j=0;j<arr_count-i-1;j++)
        {
            if (arr[j]>arr[j+1])
            {
                int temp=0;
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    long min_total = 0;
    long max_total = 0;

    for (int i = 0; i < 4; i++) {
        min_total += arr[i];
    }

    for (int i = 1; i < 5; i++) {
        max_total += arr[i];
    }

    printf("%ld %ld\n", min_total, max_total);
}

int main()
{

    char** arr_temp = split_string(rtrim(readline()));

    int* arr = malloc(5 * sizeof(int));

    for (int i = 0; i < 5; i++) {
        int arr_item = parse_int(*(arr_temp + i));

        *(arr + i) = arr_item;
    }

    miniMaxSum(5, arr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }
OA
OAOA    char* end = str + strlen(str) - 1;
OA
OAOA    while (end >= str && isspace(*end)) {
        end--;
OA    }
OAOA
    *(end + 1) = '\0';
OAOA
OAOA    return str;
OAOA}

OAOAchar** split_string(char* str) {
OAOA    char** splits = NULL;
    char* token = strtok(str, " ");
OAOA
OAOA    int spaces = 0;

    while (token) {
OB        splits = realloc(splits, sizeof(char*) * ++spaces);
OAOAOAOA
        if (!splits) {
OAOAOAOA            return splits;
OAOA        }

OAOAOAOAOA        splits[spaces - 1] = token;

OAOA        token = strtok(NULL, " ");
    }
OAOAOA
    return splits;
OA}

int parse_int(char* str) {
OAOA    char* endptr;
    int value = strtol(str, &endptr, 10);
OA
    if (endptr == str || *endptr != '\0') {
OAOA        exit(EXIT_FAILURE);
    }

    return value;
}

