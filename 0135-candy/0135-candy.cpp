class Solution {
public:
    int candy(vector<int>& rating) {
        int n=rating.size();
        if(n==0) return 0;

        int up=0;
        int down=0;
        int peak=0;
        int count=1;

        for(int i=1;i<n;i++){
            if(rating[i] > rating[i-1]){
                up++;
                peak=up;
                down=0;
                count+=up+1;

            }
            else if(rating[i]==rating[i-1]){
                up=down=peak=0;
                count+=1;
            }
            else{
                down++;
                up=0;
                count+=down;

                if(down>peak){
                    count+=1;
                }
            }
        }

        return count;
        
    }
};