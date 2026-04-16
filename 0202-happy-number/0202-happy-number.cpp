class Solution {
public:

  int getsum(int n){
    int sum=0;
    while(n>0){
        int d=n%10;
        sum+=d*d;
        n=n/10;
    }
    return sum;
  }
  

    bool isHappy(int n) {
        int slow=n;
        int fast=n;

        while(true){
            fast=getsum(getsum(fast));
            slow=getsum(slow);

            if(slow==fast){
                break;
            }
        }
        return slow==1;
        
    }
};