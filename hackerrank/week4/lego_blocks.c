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
#define MOD 1000000007
char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

/*
 * Complete the 'legoBlocks' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 */

int legoBlocks(int n, int m) {
    long long row[m+1],total[m+1],solid[m+1];
    row[0]=1;
    for(int i=1;i<=m;i++)
    {
        row[i]=0;
        for(int x=1;x<=4;x++)
        {
            if(i-x>=0)
            {
                row[i]=(row[i]+row[i-x])%MOD;
            }
        }
    }
        for(int i=1;i<=m;i++) 
        {
            long long ways=1;
            for(int j=0;j<n;j++)ways=(ways*row[i])%MOD;
            total[i]=ways;
        }
    for(int i=1;i<=m;i++) 
    {
        solid[i]=total[i];
        for(int j=1;j<i;j++)
            solid[i]=(solid[i]-(solid[j]*total[i-j])%MOD+MOD)%MOD;
    }
        return(int)solid[m];
}
int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int t = parse_int(ltrim(rtrim(readline())));

OAOAOA    for (int t_itr = 0; t_itr < t; t_itr++) {
        char** first_multiple_input = split_string(rtrim(readline()));
OAOAOA
        int n = parse_int(*(first_multiple_input + 0));
OAOA
        int m = parse_int(*(first_multiple_input + 1));
OAOA
OA        int result = legoBlocks(n, m);
OAOA
        fprintf(fptr, "%d\n", result);
    }
OA
OA    fclose(fptr);

OA    return 0;
OA}

OAchar* readline() {
OA    size_t alloc_length = 1024;
    size_t data_length = 0;
OA
OAOA    char* data = malloc(alloc_length);
OA
    while (true) {
OA        char* cursor = data + data_length;
OA        char* line = fgets(cursor, alloc_length - data_length, stdin);
OA
        if (!line) {
OA            break;
OA        }

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
OAOA            data = '\0';
OAOA        }
    } else {
        data = realloc(data, data_length + 1);

OAOA        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
OA        }
OAOA    }
OA
    return data;
OA}
OAOA
OAchar* ltrim(char* str) {
OAOA    if (!str) {
OA        return '\0';
    }
OA
OAOA    if (!*str) {
        return str;
OA    }
OAOA
OA    while (*str != '\0' && isspace(*str)) {
        str++;
OAOA    }

    return str;
OAOAOA}

OAchar* rtrim(char* str) {
    if (!str) {
        return '\0';
OA    }

OA    if (!*str) {
        return str;
OA    }

    char* end = str + strlen(str) - 1;

OA    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}
OA
OAOAOAOAchar** split_string(char* str) {
OAOAOAOA    char** splits = NULL;
    char* token = strtok(str, " ");
OA
OAOAOAOA    int spaces = 0;

OAOAOA    while (token) {
OAOA        splits = realloc(splits, sizeof(char*) * ++spaces);

OAOAOA        if (!splits) {
            return splits;
        }

OAOA        splits[spaces - 1] = token;
OAOAOAOA
OA        token = strtok(NULL, " ");
OB    }

    return splits;
OAOAOAOAOAOAOA}

OAOAOAint parse_int(char* str) {
    char* endptr;
OAOAOAOAOAOAOA    int value = strtol(str, &endptr, 10);

OAOAOAOAOAOAOAOAOAOAOA    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}

