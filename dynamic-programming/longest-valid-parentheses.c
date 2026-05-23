int longestValidParentheses(char* s) {
    int max = 0, len = strlen(s);
    int* stack = malloc((len + 1) * sizeof(int));
    int top = -1;
    stack[++top] = -1; // base for index calculation

    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            stack[++top] = i;
        } else {
            top--;
            if (top == -1) {
                stack[++top] = i;
            } else {
                int validLen = i - stack[top];
                if (validLen > max) max = validLen;
            }
        }
    }
    free(stack);
    return max;
}

