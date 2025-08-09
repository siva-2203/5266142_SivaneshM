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
 * Complete the 'caesarCipher' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER k
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
char* caesarCipher(char* s, int k) {
    k%=26;
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
        if(s[i]>='A'&&s[i]<='Z')
        {
            s[i]=(((s[i]-'A'+k)%26)+'A');
        }
        else if(s[i]>='a'&&s[i]<='z')
        {
            s[i]=(((s[i]-'a'+k)%26)+'a');
        }
    }
OAOAOAreturn s;
}

OAOAOAint main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int n = parse_int(ltrim(rtrim(readline())));

    char* s = readline();

    int k = parse_int(ltrim(rtrim(readline())));

    char* result = caesarCipher(s, k);

    fprintf(fptr, "%s\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
OAOAOA        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);
OAOAOA
OAOAOA        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
OAOAOA        }

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

OAOAOA        if (!data) {
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
OAOAOA}

char* rtrim(char* str) {
OAOAOA    if (!str) {
OAOAOA        return '\0';
    }
OAOAOA
    if (!*str) {
OAOAOA        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

OAOAOAint parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);
OAOAOA
OAOAOAOAOAOA    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
OAOAOA    }

OAOAOA    return value;
}

