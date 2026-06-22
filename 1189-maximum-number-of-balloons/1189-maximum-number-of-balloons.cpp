class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>mp;
        for(char c:text){
            if(c=='b' || c=='a' || c=='l'||c=='o'||c=='n'){
                mp[c]++;
            }
        }
        if(mp.size()!=5)return 0;
        int total=1e9;
        int lCount=0;
        int oCount=0;
        for(auto&it:mp){
            if(it.first=='l' )lCount+=it.second;
            else if(it.first=='o')oCount+=it.second;

            else{
                total=min(total,it.second);
            }
        }
        if(lCount<2 ||oCount<2 )return 0;
        total=min({total,oCount/2,lCount/2});
        return total;
    }
};