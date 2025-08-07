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
 * Complete the 'sockMerchant' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY ar
 */

int sockMerchant(int n, int ar_count, int* ar) {
    int count=0;
    for (int i=0;i<ar_count;i++)
    {
        if(ar[i]==-1)continue;
        for(int j=i+1;j<ar_count;j++)
        {
            if(ar[i]==ar[j])
            {
                count+=1;
                ar[i]=-1;
                ar[i]=-1;
                break;
            }
        }
    }
    return count;

}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int n = parse_int(ltrim(rtrim(readline())));

    char** ar_temp = split_string(rtrim(readline()));

    int* ar = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
OAOAOA        int ar_item = parse_int(*(ar_temp + i));

        *(ar + i) = ar_item;
OAOA    }
OA
    int result = sockMerchant(n, n, ar);
OA
OA    fprintf(fptr, "%d\n", result);
OA
OA    fclose(fptr);
OA
OA    return 0;
OA}
OA
OAchar* readline() {
    size_t alloc_length = 1024;
OAOAOA    size_t data_length = 0;
OA
OA    char* data = malloc(alloc_length);
OA
    while (true) {
OA        char* cursor = data + data_length;
OAOA        char* line = fgets(cursor, alloc_length - data_length, stdin);

OA        if (!line) {
            break;
OA        }

OAOA        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
OA        }

OA        alloc_length <<= 1;

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
OA        }
OAOA    } else {
OAOA        data = realloc(data, data_length + 1);

OA        if (!data) {
            data = '\0';
OAOAOAOA        } else {
OAOA            data[data_length] = '\0';
        }
OA    }
OAOAOAOA
OAOA    return data;
}
OAOAOA
OAOAchar* ltrim(char* str) {
OAOA    if (!str) {
OAOA        return '\0';
    }
OA
    if (!*str) {
        return str;
    }
OAOAOAOAOAOAOA
OAOA    while (*str != '\0' && isspace(*str)) {
        str++;
OA    }

OAOAOAOA    return str;
}
OAOA
char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }
OAOA
    if (!*str) {
        return str;
    }

OAOA    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
OA        end--;
    }
OAOAOAOAOAOA
    *(end + 1) = '\0';

OAOAOA    return str;
OAOAOA}
OA
char** split_string(char* str) {
OAOAOAOA    char** splits = NULL;
    char* token = strtok(str, " ");
OAOAOAOAOA
    int spaces = 0;
OAOAOAOAOA
OAOAOA    while (token) {
OAOAOAOAOA        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
OAOAOAOAOAOAOA        }
OAOAOAOAOAOA
        splits[spaces - 1] = token;
OAOAOA
        token = strtok(NULL, " ");
OAOAOA    }

OAOAOAOAOAOAOAOA    return splits;
}
OAOAOA
OAOAOAOAOAOAOAint parse_int(char* str) {
    char* endptr;
OAOAOAOAOA    int value = strtol(str, &endptr, 10);

OA    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
OAOAOAOAOA    }

OA    return value;
}

