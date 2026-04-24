class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int counter=0,extras=0;
        for(auto& s:moves){
            if(s=='R')counter++;
            else if(s=='L')counter--;
            else extras++;
        }
        return abs(counter)+extras;
    }
};