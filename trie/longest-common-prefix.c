#include <stdio.h>
#include <string.h>

int findMinLength(char **strs, int strsSize) {
    int min = strlen(strs[0]);
    for (int i = 1; i < strsSize; i++) {
        int len = strlen(strs[i]);
        if (len < min)
            min = len;
    }
    return min;
}

char* longestCommonPrefix(char **strs, int strsSize) {
    if (strsSize == 0)
        return "";

    static char prefix[201];
    int minLen = findMinLength(strs, strsSize);
    int i;

    for (i = 0; i < minLen; i++) {
        char current = strs[0][i];
        for (int j = 1; j < strsSize; j++) {
            if (strs[j][i] != current) {
                prefix[i] = '\0';
                return prefix;
            }
        }
        prefix[i] = current;
    }
    prefix[i] = '\0';
    return prefix;
}