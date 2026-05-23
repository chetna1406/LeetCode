int searchInsert(int* a, int n, int t) {
    int l=0,h=n-1,m;
    while(l<=h){
        m=(l+h)/2;
        if(a[m]==t) return m;
        if(a[m]<t) l=m+1;
        else h=m-1;
    }
    return l;
}
