class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long num=mass;
        for(int a:asteroids){
            if(num<a)return false;
            num+=a;
        }
        return true;
    }
};