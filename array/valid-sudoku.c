bool isValidSudoku(char** B, int r, int* c) {
    int i, j, k, l;
    for(i = 0; i < 9; i++) {
        int R[9] = {}, C[9] = {}, G[9] = {};
        for(j = 0; j < 9; j++) {
            if(B[i][j] != '.') {
                k = B[i][j] - '1';
                if(R[k]++) return 0;
            }
            if(B[j][i] != '.') {
                k = B[j][i] - '1';
                if(C[k]++) return 0;
            }
            l = (i/3)*3 + j/3;
            k = (i%3)*3 + j%3;
            if(B[l][k] != '.') {
                int x = B[l][k] - '1';
                if(G[x]++) return 0;
            }
        }
    }
    return 1;
}
