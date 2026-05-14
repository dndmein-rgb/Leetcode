class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int i=0,j=m*n-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            int r=mid/m;
            int c=mid%m;
            if(matrix[r][c]==target)return true;
            else if(matrix[r][c]<target)i++;
            else j--;
        }
        return false;
    }
};