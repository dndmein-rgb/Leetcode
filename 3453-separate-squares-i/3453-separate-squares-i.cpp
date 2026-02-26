class Solution {
public:
bool check (vector<vector<int>>& squares,double mid,double total){
    double bot_area=0;
    for(auto&s:squares){
        double y=s[1];
        double l=s[2];
        double bot_y=y;
        double top_y=y+l;
        if(mid>=top_y){
            bot_area+=l*l;
        }else if(mid>bot_y){
            bot_area+=(mid-bot_y)*l;
    }
        }
        return bot_area>=total/2;
}

    double separateSquares(vector<vector<int>>& squares) {
        double low = INT_MAX;
        double high = INT_MIN;
        double total = 0;
        for (auto& s : squares) {
            double x = s[0];
            double y = s[1];
            double l = s[2];
            total += l * l;
        
        low = min(low, y);
        high = max(high, y + l) ;
        }
        double result = 0;
        while(high-low > 1e-5) {
            double mid = low + (high - low) / 2;
            result = mid;
            if (check(squares,mid,total)) {
                high = mid;
            } else {
                low = mid;
            }
        }
        return result;
    }
};