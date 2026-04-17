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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy= new ListNode(0);
        dummy->next=head;

        ListNode* temp=head;
        ListNode*  prev=dummy;

        while( temp != NULL && temp->next != NULL){
            bool isdup=false;

            while(temp->next != NULL && temp->val==temp->next->val){
                ListNode* dup=temp;
                temp=temp->next;
                delete(dup);
                isdup=true;
            }

            if(isdup){
                ListNode* dup=temp;
                temp=temp->next;
                delete(dup);

                prev->next=temp;
            }
            else{
                prev=temp;
                temp=temp->next;
            }

        }
        return dummy->next;
        
    }
};