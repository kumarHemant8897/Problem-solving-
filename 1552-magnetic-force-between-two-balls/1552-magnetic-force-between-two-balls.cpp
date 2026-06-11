class Solution {
public:

    bool poss(vector<int> &arr,int dist,int magnet){
        int countmag=1;
        int last=arr[0];

        for(int i=1;i<arr.size() ; i++){
            if(arr[i] - last >= dist){
                countmag++;
                last=arr[i];
            }


            if(countmag >= magnet) return true;
        }

        return false;
    }


    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(position.begin() , position.end());
        int st=1;
        int end=position[n-1] - position[0];
        int ans=0;

        while( st <= end){
            int mid = st + (end - st )/2;

            if(poss(position,mid,m)){
                st=mid+1;
                ans=mid;
            }
            else{
               end= mid-1;
            }
        }

        return ans;
        
    }
};