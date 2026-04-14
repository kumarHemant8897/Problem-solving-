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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1=l1;
        ListNode* t2=l2;
        ListNode* dummyNode =  new ListNode(-1);
        int carry=0;
        ListNode* cur=dummyNode;

        while(t1 != NULL || t2!=NULL){
            int sum=carry;
          

          if(t1){
            sum+=t1->val;
            t1=t1->next;
          }

          if(t2){
            sum+=t2->val;
            t2=t2->next;
          }

            ListNode* newNode=new ListNode(sum%10);
            carry=sum/10;

            cur->next=newNode;
            cur=cur->next;

          
        }

        if(carry !=0){
            ListNode* newNode= new ListNode(carry);
            cur->next=newNode;
        }

        return dummyNode->next;
        
    }
};