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
 * Complete the 'birthday' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY s
 *  2. INTEGER d
 *  3. INTEGER m
 */

int birthday(int s_count, int* s, int d, int m) {
    int count=0;
    for(int i=0;i<s_count-m+1;i++)
    {
        int sum=0;
        for(int j=0;j<m;j++)
        {
            sum+=s[i+j];
        }
        if(sum==d)
        {
            count+=1;
        }
         
    }
return count;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int n = parse_int(ltrim(rtrim(readline())));

    char** s_temp = split_string(rtrim(readline()));

    int* s = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int s_item = parse_int(*(s_temp + i));

        *(s + i) = s_item;
    }

    char** first_multiple_input = split_string(rtrim(readline()));

    int d = parse_int(*(first_multiple_input + 0));

    int m = parse_int(*(first_multiple_input + 1));

    int result = birthday(n, s, d, m);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
OAOA        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);
OA
OA        if (!line) {
OA            break;
        }

OA        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
OA            break;
        }

OA        alloc_length <<= 1;

        data = realloc(data, alloc_length);
OA
        if (!data) {
            data = '\0';

            break;
OA        }
    }

OA    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

OA        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
OA    }

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
OAOA    }
OAOA
OAOA    char* end = str + strlen(str) - 1;

OA    while (end >= str && isspace(*end)) {
        end--;
    }
OA
    *(end + 1) = '\0';
OAOA
OAOA    return str;
OA}

OAOAchar** split_string(char* str) {
OAOA    char** splits = NULL;
    char* token = strtok(str, " ");
OA
OAOA    int spaces = 0;

OAOA    while (token) {
OA        splits = realloc(splits, sizeof(char*) * ++spaces);
OA
        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;
OAOA
        token = strtok(NULL, " ");
    }
OAOAOA
    return splits;
OA}

OAint parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
OA        exit(EXIT_FAILURE);
    }
OA
    return value;
}

