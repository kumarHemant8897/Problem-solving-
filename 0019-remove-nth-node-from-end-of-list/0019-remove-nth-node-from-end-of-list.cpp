class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return head;

        ListNode* fast = head;
        ListNode* slow = head;

        
        for(int i = 0; i < n; i++){
            fast = fast->next;
        }

        
        if(fast == NULL){
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }

       
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;

        return head;
    }
};