class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        vector<int> vis(n,0);
        queue<int> q;

        unordered_map<int, vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }

       q.push(0);
       vis[0]=1;

       int steps=0;

        while(!q.empty()){
            int size=q.size();

            while(size--){
                int idx=q.front();
                q.pop();

                if(idx==n-1) return steps;


                if(idx - 1 >= 0 && !vis[idx-1]){
                    vis[idx-1]=1;
                    q.push(idx-1);

                }

                if(idx+1 <n && !vis[idx+1]){
                    vis[idx+1]=1;
                    q.push(idx+1);
                }


                for( int next : mp[arr[idx]]){
                    if(!vis[next]){
                        vis[next]=1;
                        q.push(next);
                    }
                }

                mp[arr[idx]].clear();
            }
            steps++;
            
        }


        return -1;
    }
};