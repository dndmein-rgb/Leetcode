class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        int maxQuality=-1;
        vector<int>bestCoordinates={-1,-1};
        for(auto& t:towers){
            int x=t[0];
            int y=t[1];
            int q=t[2];
            int distance=abs(x-center[0])+abs(y-center[1]);
            if(distance<=radius){
                if(q>maxQuality){
                    maxQuality=q;
                    bestCoordinates={x,y};
                }
                if(q==maxQuality){
                    if(x<bestCoordinates[0]||(x==bestCoordinates[0] && y<bestCoordinates[1])){
                        bestCoordinates={x,y};
                    }
                }
            }
        }
        return bestCoordinates;
    }
};