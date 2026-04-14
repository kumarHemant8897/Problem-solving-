class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        if(head == NULL) return head;

        vector<int> arr;
        ListNode* temp = head;

        // collect odd index nodes
        while(temp != NULL){
            arr.push_back(temp->val);
            if(temp->next) temp = temp->next->next;
            else break;
        }

        // collect even index nodes
        temp = head->next;
        while(temp != NULL){
            arr.push_back(temp->val);
            if(temp->next) temp = temp->next->next;
            else break;
        }

        // rewrite values correctly
        temp = head;
        int i = 0;
        while(temp != NULL){
            temp->val = arr[i++];
            temp = temp->next;
        }

        return head;
    }
};