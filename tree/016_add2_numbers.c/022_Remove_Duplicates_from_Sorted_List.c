struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode dummy = {0, head};
    struct ListNode *p = &dummy;

    while (p->next) {
        struct ListNode *q = p->next;

        while (q->next && q->val == q->next->val)
            q = q->next;

        if (p->next != q)
            p->next = q->next;
        else
            p = p->next;
    }

    return dummy.next;
}