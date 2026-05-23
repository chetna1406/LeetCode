char** res;
int sz;

void gen(int n, int o, int c, char* s) {
    if (o == n && c == n) {
        res[sz] = strdup(s);
        sz++;
        return;
    }
    if (o < n) {
        s[o + c] = '(';
        gen(n, o + 1, c, s);
    }
    if (c < o) {
        s[o + c] = ')';
        gen(n, o, c + 1, s);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    res = malloc(10000 * sizeof(char*));
    sz = 0;
    char* s = malloc(2 * n + 1);
    s[2 * n] = 0;
    gen(n, 0, 0, s);
    free(s);
    *returnSize = sz;
    return res;
}
