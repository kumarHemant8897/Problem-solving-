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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL){
            return NULL;
        }

        while(head != NULL && head->val==val){
            ListNode* del=head;
            head=head->next;
            delete del;
            
        }

        ListNode* temp=head;
        ListNode* prev=NULL;

        while( temp != NULL){
            if(temp->val==val){
                ListNode* del=temp;
                if(prev != NULL){
                    prev->next=temp->next;
                }

                temp=temp->next;
                delete del;
            }
            else{
            
            prev=temp;
            temp=temp->next;
            }
        }
        return head;

       
    }
};