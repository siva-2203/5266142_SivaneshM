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
 * Complete the 'twoArrays' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY A
 *  3. INTEGER_ARRAY B
 */

/*
 * To return the string from the function, you should either do static allocation or dynamic allocation
 *
 * For example,
 * char* return_string_using_static_allocation() {
 *     static char s[] = "static allocation of string";
 *
 *     return s;
 * }
 *
 * char* return_string_using_dynamic_allocation() {
 *     char* s = malloc(100 * sizeof(char));
 *
 *     s = "dynamic allocation of string";
 *
 *     return s;
 * }
 *
 */
char* twoArrays(int k, int A_count, int* A, int B_count, int* B) {
    for(int i=0;i<A_count;i++)
    {
        for(int j=0;j<A_count-i-1;j++)
        {
            if(A[j]>A[j+1])
            {
                int temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }
    for(int i=0;i<B_count;i++)
    {
        for(int j=0;j<B_count-i-1;j++)
        {
            if(B[j]<B[j+1])
            {
                int temp=B[j];
                B[j]=B[j+1];
                B[j+1]=temp;
            }
        }
    }
    for(int i=0;i<A_count;i++)
    {
        if(A[i]+B[i]<k)
        {
            return "NO";
        }
    }
    return "YES";

}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int q = parse_int(ltrim(rtrim(readline())));

OA    for (int q_itr = 0; q_itr < q; q_itr++) {
OA        char** first_multiple_input = split_string(rtrim(readline()));

OAOA        int n = parse_int(*(first_multiple_input + 0));

OA        int k = parse_int(*(first_multiple_input + 1));

OA        char** A_temp = split_string(rtrim(readline()));
OA
        int* A = malloc(n * sizeof(int));

OA        for (int i = 0; i < n; i++) {
OA            int A_item = parse_int(*(A_temp + i));

            *(A + i) = A_item;
        }

        char** B_temp = split_string(rtrim(readline()));

OA        int* B = malloc(n * sizeof(int));

        for (int i = 0; i < n; i++) {
            int B_item = parse_int(*(B_temp + i));
OA
            *(B + i) = B_item;
        }

OA        char* result = twoArrays(k, n, A, n, B);

        fprintf(fptr, "%s\n", result);
    }

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
OA    size_t data_length = 0;

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

OAOAOAOAOA        data = realloc(data, data_length);

OA        if (!data) {
OAOA            data = '\0';
OA        }
OAOA    } else {
        data = realloc(data, data_length + 1);

OA        if (!data) {
OAOA            data = '\0';
OA        } else {
            data[data_length] = '\0';
OA        }
OAOA    }
OAOA
OA    return data;
OA}

char* ltrim(char* str) {
    if (!str) {
OAOAOA        return '\0';
    }
OA
    if (!*str) {
OA        return str;
    }
OA
    while (*str != '\0' && isspace(*str)) {
OA        str++;
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

OA    char* end = str + strlen(str) - 1;
OAOAOA
    while (end >= str && isspace(*end)) {
        end--;
    }

OAOAOA    *(end + 1) = '\0';
OAOAOA
OA    return str;
OAOAOA}
OAOA
OAOAchar** split_string(char* str) {
OAOA    char** splits = NULL;
OAOA    char* token = strtok(str, " ");

OAOAOA    int spaces = 0;
OAOA
    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
OAOAOAOAOA        }

        splits[spaces - 1] = token;
OAOAOAOAOA
        token = strtok(NULL, " ");
OA    }

OAOAOAOAOA    return splits;
}
OAOAOAOAOAOA
int parse_int(char* str) {
OAOAOA    char* endptr;
    int value = strtol(str, &endptr, 10);
OAOAOA
    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

OAOAOAOA    return value;
}

