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
 * Complete the 'gridChallenge' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING_ARRAY grid as parameter.
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
char* gridChallenge(int grid_count, char** grid) {
    int l=strlen(grid[0]);
    for(int i=0;i<grid_count;i++)
    {
      for(int j=0;j<l-1;j++)
      {
        for(int k=j+1;k<l;k++)
        {
        if(grid[i][j]>grid[i][k])
        {
            char temp=grid[i][j];
            grid[i][j]=grid[i][k];
            grid[i][k]=temp;
        }
        }
      }
    }
    for(int c=0;c<l;c++)
    {
        for(int r=1;r<grid_count;r++)
        {
            if(grid[r][c]<grid[r-1][c])
            {
                return "NO";
            }
        }
    }
    return "YES";

}



int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int t = parse_int(ltrim(rtrim(readline())));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n = parse_int(ltrim(rtrim(readline())));

        char** grid = malloc(n * sizeof(char*));

        for (int i = 0; i < n; i++) {
            char* grid_item = readline();

            *(grid + i) = grid_item;
OA        }

OAOA        char* result = gridChallenge(n, grid);
OAOA
        fprintf(fptr, "%s\n", result);
OA    }
OAOA
    fclose(fptr);
OA
OAOA    return 0;
}
OA
OAchar* readline() {
    size_t alloc_length = 1024;
OA    size_t data_length = 0;
OA
    char* data = malloc(alloc_length);

OA    while (true) {
        char* cursor = data + data_length;
OAOA        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
OA            break;
        }
OA
        data_length += strlen(cursor);
OA
        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
OA            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
OA        }
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
OAOAOAOAOAOA}

OAOAOAchar* ltrim(char* str) {
OAOA    if (!str) {
OAOA        return '\0';
    }
OAOAOA
OA    if (!*str) {
        return str;
OAOA    }
OAOAOA
    while (*str != '\0' && isspace(*str)) {
OAOA        str++;
OAOA    }

OAOA    return str;
OAOA}

OBchar* rtrim(char* str) {
OA    if (!str) {
OA        return '\0';
    }

    if (!*str) {
OAOAOAOA        return str;
    }
OA
    char* end = str + strlen(str) - 1;
OAOAOAOA
    while (end >= str && isspace(*end)) {
OA        end--;
    }
OAOA
    *(end + 1) = '\0';
OAOA
    return str;
OA}

int parse_int(char* str) {
OA    char* endptr;
    int value = strtol(str, &endptr, 10);
OA
    if (endptr == str || *endptr != '\0') {
OA        exit(EXIT_FAILURE);
    }
OA
    return value;
}

