int strStr(char* h, char* n) {
    int i, j;
    for (i = 0; h[i]; i++) {
        for (j = 0; n[j] && h[i + j] == n[j]; j++);
        if (!n[j]) return i;
    }
    return -1;
}

