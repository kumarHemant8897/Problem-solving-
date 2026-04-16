class Solution {
public: 
    ListNode* collision(ListNode* temp1, ListNode* temp2, int d){
        while(d){
            temp2 = temp2->next;
            d--;
        }

        while(temp1 != temp2){
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return temp1;  
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        int n1 = 0, n2 = 0;

        while(temp1 != NULL){
            n1++;
            temp1 = temp1->next;
        }

        while(temp2 != NULL){
            n2++;
            temp2 = temp2->next;
        }

        if(n1 < n2){
            return collision(headA, headB, n2 - n1);
        } else {
            return collision(headB, headA, n1 - n2); 
        }
    }
};