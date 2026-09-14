/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head == NULL){
        return head;
    }

    if(head->next == NULL){
        return head;
    }

    struct ListNode* temp = head;
    struct ListNode* del = NULL;

    while( temp != NULL && temp->next != NULL){
        if(temp->val == temp->next->val){
            del = temp->next;
            temp->next = temp->next->next;
            free(del);
        }else{
            temp = temp->next;
        }
        
    }

    return head;
}
