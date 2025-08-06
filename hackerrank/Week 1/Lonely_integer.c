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
 * Complete the 'lonelyinteger' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

int lonelyinteger(int a_count, int* a) 
{
    int result=0;
    for(int i=0;i<a_count;i++)
    {
        result^=a[i];
 
    }

 return result;   
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int n = parse_int(ltrim(rtrim(readline())));

    char** a_temp = split_string(rtrim(readline()));

    int* a = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int a_item = parse_int(*(a_temp + i));

        *(a + i) = a_item;
    }

    int result = lonelyinteger(n, a);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

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
OAOAOA            data = '\0';
        }
    } else {
OAOAOA        data = realloc(data, data_length + 1);
OAOAOA
        if (!data) {
            data = '\0';
OAOAOA        } else {
            data[data_length] = '\0';
        }
    }
OAOAOA
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
OAOAOA    if (!str) {
        return '\0';
    }

OAOAOA    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}
OAOAOA
char** split_string(char* str) {
    char** splits = NULL;
OAOAOA    char* token = strtok(str, " ");
OAOAOA
OAOAOA    int spaces = 0;

    while (token) {
OAOAOA        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
OAOAOA        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}
OAOAOA
OAOAOAint parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);
OAOAOA
    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }
OAOAOA
    return value;
}

