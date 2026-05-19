class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int sz=tasks.size();

        vector<int> freq(26,0);
        for(int i=0; i <sz;i++){
            freq[tasks[i]- 'A']++;
        }

        int maxfreq=0;
        for(int i=0 ;i < 26 ;i++){
            if(freq[i] > maxfreq){
                maxfreq=freq[i];
            }
        }

        int maxcount=0;
        for(int i=0;i<26;i++){
            if(freq[i] == maxfreq){
                maxcount++;
            }
        }

        int ans=(maxfreq - 1 ) * (n + 1 ) +  maxcount;

        return max((int)tasks.size(), ans);

        
        
    }
};