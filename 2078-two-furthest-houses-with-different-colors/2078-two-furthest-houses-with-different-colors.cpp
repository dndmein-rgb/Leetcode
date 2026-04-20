class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n =colors.size();
        int maxD=0;
       int i=0,j=n-1;
       while(i<j && colors[i]==colors[j])j--;
       maxD=max(maxD,abs(j-i));
       j=n-1;
       while(i<j && colors[i]==colors[j] )i++;
       maxD=max(maxD,abs(j-i));
       
       return maxD;
    }
};