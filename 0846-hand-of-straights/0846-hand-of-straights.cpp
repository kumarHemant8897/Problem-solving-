class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
       int n=hand.size();

       if( n  % groupSize != 0 ){
        return false;
       }

       map<int,int> mp;
       for(int i=0;i<n;i++){
        mp[hand[i]]++;
       }


       while(!mp.empty()){
        int st=mp.begin() -> first;

        for(int i=0;i< groupSize ; i++) {
            int card=st+i;

            if(mp.find(card) == mp.end()){
                return false;
            }
            mp[card]--;


            if(mp[card] == 0){

                mp.erase(card);
            }
        }
       }

       return true;
       
    }
};