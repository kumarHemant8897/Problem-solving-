class Solution {
public:

   bool check(int n){
    bool change=false;

    while(n > 0 ){
        int digit=n%10;

        if(digit == 3 || digit==4 || digit==7 ){
            return false;
        }

        if(digit==2 || digit==5 || digit==6 || digit==9){
            change= true;
        }
        n=n/10;
    }
    return change;

   }


    int rotatedDigits(int n) {
        int count=0;
        for(int i=0;i<=n;i++){
            if(check(i) == true){
                count++;
            }
        }
        return count;
        
    }
};