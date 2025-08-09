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

int parse_int(char*);

/*
 * Complete the 'pageCount' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER p
 */

int pageCount(int n, int p) {
    int a,b;
    /*a is used when page is counted from front
    b is used when page is counted from back*/
    if(p%2!=0)
    {
        p=p-1;
    }
    a=p/2;
    b=(n-p)/2;
    int min_turn;
    //min_turn is used to store the minimun turns
    if(a<b)
    {
        min_turn=a;
    }
    else 
    {
        min_turn=b;            
    }
    return min_turn;

}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int n = parse_int(ltrim(rtrim(readline())));

    int p = parse_int(ltrim(rtrim(readline())));

    int result = pageCount(n, p);

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

OAOAOA        data = realloc(data, data_length);

        if (!data) {
OAOAOA            data = '\0';
        }
OAOAOA    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
OAOAOA            data = '\0';
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

OAOAOAchar* rtrim(char* str) {
    if (!str) {
        return '\0';
OAOAOA    }

    if (!*str) {
OAOAOA        return str;
    }

OAOAOA    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
OAOAOA        end--;
    }

    *(end + 1) = '\0';

    return str;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
OAOAOA    }

    return value;
OAOAOA}

