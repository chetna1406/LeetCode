struct ListNode* reverseKGroup(struct ListNode* h, int k) {
    struct ListNode d = {0, h}, *p = &d, *a, *b, *c;
    int i;
    while (1) {
        a = p;
        for (i = 0; i < k && a; i++) a = a->next;
        if (!a) break;
        b = p->next;
        for (i = 0; i < k - 1; i++) {
            c = b->next;
            b->next = c->next;
            c->next = p->next;
            p->next = c;
        }
        p = b;
    }
    return d.next;
}
