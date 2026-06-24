class Solution {
public:
    int timeRequiredToBuy(vector<int>& tic, int k) {

        queue<int> q;
        for(int i=0;i<tic.size();i++) q.push(i);

        int time=0; 
        while(!q.empty()){
         time++;
        



        int idfront=q.front();
        q.pop();
        tic[idfront]--;

        if(tic[idfront]==0 && k==idfront ) return time;
        if(tic[idfront] != 0)   q.push(idfront);
        }
         return time;
        
    }
    
};