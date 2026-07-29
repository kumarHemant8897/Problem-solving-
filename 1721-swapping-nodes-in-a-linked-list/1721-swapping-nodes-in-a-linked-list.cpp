/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* cur=NULL;
        ListNode* temp=head;
        int len=0;

        while(temp != NULL){
            len++;

            if(len == k ){
                cur=temp;
            }

            temp=temp->next;
        }

        temp=head;


        for(int i=1;i<= len-k ;i++){
            temp=temp->next;
        }

        swap(cur->val,temp->val);
        return head;
        

        
        
    }
};