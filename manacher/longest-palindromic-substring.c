#include <string.h>
#include <stdbool.h>

char* longestPalindrome(char* s) {
    int len = strlen(s);
    if (len <= 1) return s;

    bool dp[1001][1001] = { false };
    int maxLen = 1, start = 0;

    for (int i = 0; i < len; i++) dp[i][i] = true;

    for (int i = 0; i < len - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            maxLen = 2;
        }
    }

    for (int k = 3; k <= len; k++) {
        for (int i = 0; i <= len - k; i++) {
            int j = i + k - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                if (k > maxLen) {
                    start = i;
                    maxLen = k;
                }
            }
        }
    }

    static char result[1001];
    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0';
    return result;
}
