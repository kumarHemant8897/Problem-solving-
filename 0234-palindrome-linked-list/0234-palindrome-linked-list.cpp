class Solution {
public:

    
    ListNode* reverse(ListNode* head) {
       ListNode* cur=head;
       ListNode* prev=NULL;

       while( cur !=NULL){
         ListNode* newNode= cur->next;
          cur->next=prev;
          prev=cur;
          cur=newNode;
       }
       return prev;
    }

    bool isPalindrome(ListNode* head) {

        if (!head || !head->next) return true;

        
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        
        ListNode* second = reverse(slow);
        ListNode* first = head;
        ListNode* tempSecond = second;

        
        while (tempSecond != NULL) {
            if (first->val != tempSecond->val) {
                reverse(second);  
                return false;
            }
            first = first->next;
            tempSecond = tempSecond->next;
        }

        reverse(second); 
        return true;
    }
};
