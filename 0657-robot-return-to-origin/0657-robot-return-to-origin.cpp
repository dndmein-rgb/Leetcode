class Solution {
public:
    bool judgeCircle(string moves) {
        int vertical=0,horizontal=0;
        for(char &c:moves){
            if(c=='L')horizontal++;
            else if(c=='R')horizontal--;
            else if(c=='U')vertical++;
            else vertical--;
        }
        return (vertical==0 && horizontal==0);
    }
};