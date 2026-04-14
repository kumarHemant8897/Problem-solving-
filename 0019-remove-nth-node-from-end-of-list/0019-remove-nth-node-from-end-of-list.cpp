class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return head;

        ListNode* fast = head;
        ListNode* slow = head;

        // move fast n steps
        for(int i = 0; i < n; i++){
            fast = fast->next;
        }

        // if deleting head
        if(fast == NULL){
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        // move both until fast reaches end
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }

        // delete node
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;

        return head;
    }
};