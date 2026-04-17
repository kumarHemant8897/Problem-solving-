class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        int len = 1;
        ListNode* tail = head;

        while (tail->next != NULL) {
            len++;
            tail = tail->next;
        }

        tail->next = head;   // make circular

        k = k % len;
        if (k == 0) {
            tail->next = NULL;   // 🔥 FIX: break circle
            return head;
        }

        int steps = len - k;
        ListNode* temp = head;

        while (steps > 1) {
            temp = temp->next;
            steps--;
        }

        ListNode* newhead = temp->next;
        temp->next = NULL;

        return newhead;
    }
};