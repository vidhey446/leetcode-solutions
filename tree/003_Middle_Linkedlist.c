struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode *middle = head;
    struct ListNode *second = head;
    while (second != NULL && second->next != NULL) {
        middle = middle->next;
        second = second->next->next;
    }
    return middle;
}