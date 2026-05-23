int divide(int a, int b) {
    if (a == -2147483648 && b == -1) return 2147483647;
    int sign = (a > 0) == (b > 0) ? 1 : -1;
    long x = labs(a), y = labs(b), res = 0;
    while (x >= y) {
        long t = y, m = 1;
        while (x >= (t << 1)) t <<= 1, m <<= 1;
        x -= t, res += m;
    }
    return sign * res;
}
