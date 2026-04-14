class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        if(head == NULL) return head;

        vector<int> arr;
        ListNode* temp = head;

        
        while(temp != NULL){
            arr.push_back(temp->val);
            if(temp->next) temp = temp->next->next;
            else break;
        }

        
        temp = head->next;
        while(temp != NULL){
            arr.push_back(temp->val);
            if(temp->next) temp = temp->next->next;
            else break;
        }

        
        temp = head;
        int i = 0;
        while(temp != NULL){
            temp->val = arr[i++];
            temp = temp->next;
        }

        return head;
    }
};