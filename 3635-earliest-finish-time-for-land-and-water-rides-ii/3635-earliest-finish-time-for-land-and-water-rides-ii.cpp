class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n=landStartTime.size();
        int minLandTime=1e9;
        for(int i=0;i<n;i++){
           int landTime=landStartTime[i]+landDuration[i];
            minLandTime=min(minLandTime,landTime);
        }
        int m=waterStartTime.size();
        int totalTime=1e9;
        for(int i=0;i<m;i++){
        int time=max(minLandTime,waterStartTime[i]);
        int fullTime=time+waterDuration[i];
        totalTime=min(totalTime,fullTime);
        }

         int minWaterTime=1e9;

         for(int i=0;i<m;i++){
            int waterTime=waterStartTime[i]+waterDuration[i];
            minWaterTime=min(minWaterTime,waterTime);
        }
        for(int i=0;i<n;i++){
           int Time=max(minWaterTime,landStartTime[i]);
           int fullTime=Time+landDuration[i];
           totalTime=min(totalTime,fullTime);
        }
        

        return totalTime;
    }
};