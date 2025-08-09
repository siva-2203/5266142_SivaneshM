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
 * Complete the 'towerBreakers' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 */

int towerBreakers(int n, int m) {
    int result;
    if(m==1)
    {
        result=2;
    }
    else if(m>1 && (n%2==0))
    {
        result=2;
    }
    else if(m>1 && (n%2!=0)){
    result=1;
    }
    return result;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int t = parse_int(ltrim(rtrim(readline())));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        char** first_multiple_input = split_string(rtrim(readline()));

        int n = parse_int(*(first_multiple_input + 0));

        int m = parse_int(*(first_multiple_input + 1));

        int result = towerBreakers(n, m);

        fprintf(fptr, "%d\n", result);
    }

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
OAOAOA
        if (!line) {
            break;
        }

        data_length += strlen(cursor);
OAOAOA
        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
OAOAOA    }

OAOAOA    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

OAOAOA        data = realloc(data, data_length);
OAOAOA
        if (!data) {
OAOAOA            data = '\0';
OAOAOA        }
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
OAOAOA    if (!str) {
        return '\0';
    }

OAOAOA    if (!*str) {
OAOAOA        return str;
    }
OAOAOA
    while (*str != '\0' && isspace(*str)) {
        str++;
OAOAOA    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }
OAOAOA
    *(end + 1) = '\0';

OAOAOA    return str;
OAOAOA}
OAOAOA
char** split_string(char* str) {
OAOAOA    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }
OAOAOA
    return splits;
}
OAOAOA
int parse_int(char* str) {
    char* endptr;
OAOAOA    int value = strtol(str, &endptr, 10);
OAOAOA
OAOAOA    if (endptr == str || *endptr != '\0') {
OAOAOA        exit(EXIT_FAILURE);
    }

    return value;
}

