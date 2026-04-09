class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0,j=n-1;
        int maxArea=0;
        while(i<j){
            int currArea=(j-i)*min(height[i],height[j]);
            maxArea=max(maxArea,currArea);
            if(height[i]>height[j]){
                j--;
            }else i++;
        }
        return maxArea;
    }
};