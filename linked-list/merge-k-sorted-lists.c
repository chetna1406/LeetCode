#define SWAP(a,b) {void* t=a;a=b;b=t;}

void heapify(struct ListNode** h, int n, int i) {
    int s = i, l = 2*i+1, r = 2*i+2;
    if (l<n && h[l]->val < h[s]->val) s=l;
    if (r<n && h[r]->val < h[s]->val) s=r;
    if (s!=i) { SWAP(h[i], h[s]); heapify(h,n,s); }
}

struct ListNode* mergeKLists(struct ListNode** lists, int k) {
    struct ListNode** h = malloc(k * sizeof(*h));
    int n = 0;
    for (int i = 0; i < k; i++) if (lists[i]) h[n++] = lists[i];
    for (int i = n/2; i >= 0; i--) heapify(h, n, i);

    struct ListNode dummy = {0}, *cur = &dummy;
    while (n) {
        cur = cur->next = h[0];
        if ((h[0] = h[0]->next)) heapify(h,n,0);
        else { h[0] = h[--n]; heapify(h,n,0); }
    }
    free(h);
    return dummy.next;
}

