#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        char* result = malloc(1);
        result[0] = '\0';
        return result;
    }

    int prefixLen = strlen(strs[0]);

    for (int i = 1; i < strsSize; i++) {
        int j = 0;

        while (j < prefixLen &&
               strs[i][j] != '\0' &&
               strs[0][j] == strs[i][j]) {
            j++;
        }

        prefixLen = j;

        if (prefixLen == 0) {
            break;
        }
    }

    char* result = malloc(prefixLen + 1);

    for (int i = 0; i < prefixLen; i++) {
        result[i] = strs[0][i];
    }

    result[prefixLen] = '\0';

    return result;
}