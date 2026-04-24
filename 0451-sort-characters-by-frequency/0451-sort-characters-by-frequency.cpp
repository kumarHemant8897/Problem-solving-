class Solution {
public:

   static bool cmp(char a, char b, unordered_map<char, int> &map){
        if(map[a]==map[b]){
            return a < b;
        }
        else{
            return map[a] > map[b];
        }
   }

    string frequencySort(string s) {
        unordered_map<char,int> mp;

        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++;
        }

        sort(s.begin(), s.end(), [&](char a, char b){
            return cmp(a, b, mp);   
        });

        return s;
    }
};