//chetna
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode d = {0}, *p = &d;
    int c = 0;
    while (l1 || l2 || c) {
        if (l1) c += l1->val, l1 = l1->next;
        if (l2) c += l2->val, l2 = l2->next;
        p = p->next = malloc(sizeof(struct ListNode));
        p->val = c % 10;
        c /= 10;
    }
    p->next = NULL;
    return d.next;
}
