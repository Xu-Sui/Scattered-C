struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *tmp = head;
    bool forward = false;
    while (l1 || l2 || forward) {
        int val1 = l1 ? l1->val : 0;
        int val2 = l2 ? l2->val : 0;
        int total = val1 + val2 + (forward ? 1 : 0);
        tmp->val = total % 10;
        forward = total / 10;
        l1 = l1 ? l1->next : NULL;
        l2 = l2 ? l2->next : NULL;
        if (l1 || l2 || forward) {
            tmp->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            tmp = tmp->next;
        }
    }
    tmp->next = NULL;
    return head;
}