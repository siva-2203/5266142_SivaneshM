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
 * Complete the 'dynamicArray' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY queries
 */

/*
 * To return the integer array from the function, you should:
 *     - Store the size of the array to be returned in the result_count variable
 *     - Allocate the array statically or dynamically
 *
 * For example,
 * int* return_integer_array_using_static_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     static int a[5] = {1, 2, 3, 4, 5};
 *
 *     return a;
 * }
 *
 * int* return_integer_array_using_dynamic_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     int *a = malloc(5 * sizeof(int));
 *
 *     for (int i = 0; i < 5; i++) {
 *         *(a + i) = i + 1;
 *     }
 *
 *     return a;
 * }
 *
 */
int* dynamicArray(int n, int queries_rows, int queries_columns, int** queries, int* result_count) {
    int lastAnswer=0;
    int** arr=calloc(n,sizeof(int*));
    int* sizes=calloc(n,sizeof(int));
    int* answers=malloc(queries_rows*sizeof(int));
OA    int ans=0;
OAOA    for(int i=0;i<queries_rows;i++)
OA    {
        int ty=queries[i][0],x=queries[i][1],y=queries[i][2];
OAOA        int idx=((x^lastAnswer)%n);
        if(ty==1)
OAOAOA        {
OA            arr[idx]=realloc(arr[idx],((sizes[idx]+1)*sizeof(int)));
OA            arr[idx][(sizes[idx]++)]=y;
OA        }
        else
        {
OA            lastAnswer=arr[idx][y%sizes[idx]];
OA            answers[ans++]=lastAnswer;
        }
OAOA    }
OA    *result_count=ans;
    return answers;
}
OA
OAint main()
{
OA    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

OA    char** first_multiple_input = split_string(rtrim(readline()));

    int n = parse_int(*(first_multiple_input + 0));

    int q = parse_int(*(first_multiple_input + 1));

    int** queries = malloc(q * sizeof(int*));

    for (int i = 0; i < q; i++) {
        *(queries + i) = malloc(3 * (sizeof(int)));

        char** queries_item_temp = split_string(rtrim(readline()));

        for (int j = 0; j < 3; j++) {
            int queries_item = parse_int(*(queries_item_temp + j));

            *(*(queries + i) + j) = queries_item;
        }
    }

    int result_count;
    int* result = dynamicArray(n, q, 3, queries, &result_count);

    for (int i = 0; i < result_count; i++) {
        fprintf(fptr, "%d", *(result + i));

        if (i != result_count - 1) {
            fprintf(fptr, "\n");
        }
    }

    fprintf(fptr, "\n");

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);
OAOAOAOAOAOAOA
OA    while (true) {
OAOAOA        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

OAOAOA        if (!line) {
            break;
        }
OAOA
OAOAOA        data_length += strlen(cursor);

OAOAOAOAOAOAOA        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
OAOAOA            break;
OBOAOA        }

OAOA        alloc_length <<= 1;

OAOAOAOAOAOAOAOA        data = realloc(data, alloc_length);
OAOAOAOAOA
        if (!data) {
OAOAOAOAOA            data = '\0';

            break;
OAOAOAOAOAOA        }
    }
OA
    if (data[data_length - 1] == '\n') {
OAOAOAOAOAOAOAOA        data[data_length - 1] = '\0';
OA
        data = realloc(data, data_length);
OA
        if (!data) {
OAOAOAOAOAOAOAOA            data = '\0';
        }
OAOA    } else {
        data = realloc(data, data_length + 1);
OAOA
OAOAOAOAOA        if (!data) {
            data = '\0';
OAOAOAOAOA        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}
OAOAOAOAOA
OAOAOAOAchar* ltrim(char* str) {
    if (!str) {
OAOAOAOA        return '\0';
OAOA    }
OA
OA    if (!*str) {
        return str;
OAOAOA    }

    while (*str != '\0' && isspace(*str)) {
OAOAOA        str++;
    }
OAOAOAOAOAOAOA
OAOAOAOAOAOAOAOA    return str;
}
OAOAOAOAOAOA
char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
OA        return str;
OAOA    }

OAOAOA    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
OAOAOAOAOA        end--;
OAOAOAOA    }
OA
    *(end + 1) = '\0';

OAOAOAOAOA    return str;
OAOAOA}
OAOA
OAOAOAchar** split_string(char* str) {
OAOA    char** splits = NULL;
OA    char* token = strtok(str, " ");
OA
    int spaces = 0;

OAOAOAOAOAOAOA    while (token) {
OAOAOAOAOA        splits = realloc(splits, sizeof(char*) * ++spaces);

OAOAOA        if (!splits) {
            return splits;
OAOAOAOAOAOAOAOA        }

OAOAOAOAOAOA        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
OAOAOAOA    }

OA    return splits;
}
OAOAOA
int parse_int(char* str) {
OA    char* endptr;
    int value = strtol(str, &endptr, 10);

OAOAOA    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }
OAOAOAOAOA
OAOAOAOA    return value;
OA}

