class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n=plants.size();
        int stA=capacityA;
        int stB=capacityB;

        int i=0;
        int j=n-1;
        int count =0;

        while( i < j ){
            if(stA < plants[i]){
                count++;
                stA=capacityA;
            }
            stA -= plants[i];
            i++;


            if(stB < plants[j]){
                count++;
                stB=capacityB;
            }
            stB-=plants[j];
            j--;
        }


            if(i==j){
                if(max(stA,stB) < plants[i]){
                    count++;
                }
            }
        

        return count;
    }
};