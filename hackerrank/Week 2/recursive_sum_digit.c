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
 * Complete the 'superDigit' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING n
 *  2. INTEGER k
 */

int superDigit(char* n, int k) {
    int x=strlen(n);
    long long tot=0;
    for(int i=0;i<x;i++)
    {
        tot=tot+n[i]-'0';
    }
    tot*=k;
    while(tot>=10)
    {
        long long sum=0;
        while(tot>0)
        {
            sum=sum+tot%10;
            tot=tot/10;
        }
        tot=sum;
    }
    return (int)tot;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** first_multiple_input = split_string(rtrim(readline()));

    char* n = *(first_multiple_input + 0);

    int k = parse_int(*(first_multiple_input + 1));

    int result = superDigit(n, k);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

OAOA    return 0;
}
OA
OAchar* readline() {
OA    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);
OA
    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);
OA
        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

OA        data = realloc(data, alloc_length);

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

    char* end = str + strlen(str) - 1;

OAOA    while (end >= str && isspace(*end)) {
OAOAOA        end--;
OAOA    }

OA    *(end + 1) = '\0';
OAOAOA
    return str;
}

OAchar** split_string(char* str) {
OAOAOA    char** splits = NULL;
OAOA    char* token = strtok(str, " ");

OAOA    int spaces = 0;
OAOA
    while (token) {
OAOA        splits = realloc(splits, sizeof(char*) * ++spaces);
OAOAOAOA
OA        if (!splits) {
            return splits;
        }
OA
        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }
OAOA
    return splits;
}
OAOAOAOAOAOAOA
int parse_int(char* str) {
OAOAOAOA    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
OAOAOAOAOA    }

    return value;
}

