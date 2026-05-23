#include <string.h>
#include <stdlib.h>

char* convert(char* s, int numRows) {
    if (numRows == 1 || numRows >= strlen(s)) return s;

    int len = strlen(s);
    char* result = (char*)malloc(len + 1);
    int idx = 0;

    for (int row = 0; row < numRows; row++) {
        for (int i = row; i < len; i += 2 * numRows - 2) {
            result[idx++] = s[i];
            int diag = i + 2 * (numRows - row - 1);
            if (row != 0 && row != numRows - 1 && diag < len)
                result[idx++] = s[diag];
        }
    }

    result[idx] = '\0';
    return result;
}
