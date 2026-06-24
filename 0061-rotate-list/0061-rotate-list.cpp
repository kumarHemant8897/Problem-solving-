class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL || head->next == NULL || k == 0)
            return head;

        int len = 1;
        ListNode* tail = head;

        while(tail->next != NULL) {
            tail = tail->next;
            len++;
        }

        k = k % len;

        if(k == 0)
            return head;

        tail->next = head; // make circular

        int steps = len - k;
        ListNode* temp = head;

        while(steps > 1) {
            temp = temp->next;
            steps--;
        }

        ListNode* newHead = temp->next;
        temp->next = NULL;

        return newHead;
    }
};