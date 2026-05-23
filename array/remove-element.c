int removeElement(int* a, int n, int val) {
    int i = 0;
    for (int j = 0; j < n; j++)
        if (a[j] != val)
            a[i++] = a[j];
    return i;
}
