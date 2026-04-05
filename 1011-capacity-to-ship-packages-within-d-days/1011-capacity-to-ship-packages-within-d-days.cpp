class Solution {
public:

  int solve(vector<int> & weights, int cap){
    int day=1;
    int load=0;

    for(int i=0;i<weights.size();i++){
        if(load + weights[i] > cap){
            day+=1;
            load=weights[i];
        }
        else{
            load+=weights[i];
        }
    }
    return day;
  }



    int shipWithinDays(vector<int>& weights, int days) {
        
        int sum=0;
        int maxelem=0;

        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
        }
        for(int i=0;i<weights.size();i++){
            maxelem=max(maxelem,weights[i]);
        }

        
        int st=maxelem;
        int end=sum;
        int ans=sum;

        while(st<=end){
            int mid=st+(end-st)/2;
            int dayreq=solve(weights,mid);

           

             if(dayreq <= days){
                 end=mid-1;
                ans=mid;
            }
            else{
                st=mid+1;
               
            }
        }
        return ans;

       
        
    }
};