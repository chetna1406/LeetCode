/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <string.h>

char *map[] = {
    "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
};

void backtrack(char *digits, int pos, char *curr, char **res, int *count) {
    if (digits[pos] == '\0') {
        res[(*count)] = strdup(curr);
        (*count)++;
        return;
    }
    char *letters = map[digits[pos] - '0'];
    for (int i = 0; letters[i]; i++) {
        curr[pos] = letters[i];
        backtrack(digits, pos + 1, curr, res, count);
    }
}

char **letterCombinations(char *digits, int *returnSize) {
    int len = strlen(digits);
    if (len == 0) {
        *returnSize = 0;
        return NULL;
    }
    int max = 1;
    for (int i = 0; i < len; i++)
        max *= (digits[i] == '7' || digits[i] == '9') ? 4 : 3;
    char **res = malloc(max * sizeof(char *));
    char *curr = malloc(len + 1);
    curr[len] = '\0';
    int count = 0;
    backtrack(digits, 0, curr, res, &count);
    free(curr);
    *returnSize = count;
    return res;
}

    
