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
    ListNode* oddEvenList(ListNode* head) {
        vector<int> arr;
        ListNode* temp=head;
        if(head==NULL){
            return head;
        }

       while(temp != NULL){
        arr.push_back(temp->val);
        if(temp->next != NULL){
            temp=temp->next->next;
        }
        else{
            break;
        }
       }


       temp=head->next;


        while(temp != NULL){
        arr.push_back(temp->val);
        if(temp->next !=NULL){
            temp=temp->next->next;
        }
        else{
            break;
        }
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