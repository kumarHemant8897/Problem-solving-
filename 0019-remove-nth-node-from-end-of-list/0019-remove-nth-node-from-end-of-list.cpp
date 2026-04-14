class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return head;

        int count = 0;
        ListNode* temp = head;

        
        while(temp != NULL){
            count++;
            temp = temp->next;
        }

        
        if(count == n){
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        
        int res = count - n;
        temp = head;

        for(int i = 1; i < res; i++){
            temp = temp->next;
        }

        
        ListNode* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;

        return head;
    }
};