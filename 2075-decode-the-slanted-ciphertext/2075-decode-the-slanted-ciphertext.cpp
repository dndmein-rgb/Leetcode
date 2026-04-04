class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
         if (rows == 1) 
            return encodedText;
        int  column=encodedText.length()/rows;
        vector<vector<char>>mat(rows,vector<char>(column));
        int k=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<column;j++){
                mat[i][j]=encodedText[k];
                k++;
            }
        }
        string ans="";
        for(int col=0;col<column;col++){
          int i=0;
          int j=col;
          while(i<rows && j<column){
          ans+=mat[i][j];
          i++;
          j++;
          }
        }
        while(!ans.empty() && ans.back()==' '){
            ans.pop_back();
        }
        return ans;
    }
};