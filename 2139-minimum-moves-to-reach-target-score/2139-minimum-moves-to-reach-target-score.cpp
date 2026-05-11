class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int st=1;

        int moves=0;

        while(target > 1 && maxDoubles  > 0){
            if(target % 2 == 0 ){
                maxDoubles--;

                target=target/2;

            }
            else {
                target=target-1;
            }
            moves++;
        }

        moves+=(target-1);
        return moves;
        
    }
};