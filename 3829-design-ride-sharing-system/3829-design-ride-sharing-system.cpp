class RideSharingSystem {
public:
queue<int>rider,driver;
unordered_map<int,int>mp;//riderId,freq
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        rider.push(riderId);
        mp[riderId]++;
    }
    
    void addDriver(int driverId) {
        driver.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        vector<int>ans={-1,-1};
        while(!rider.empty() && !mp.count(rider.front()))rider.pop();
        if(!rider.empty() && !driver.empty()){
            int d=driver.front();
            int r=rider.front();
            driver.pop();
            rider.pop();
           return {d,r} ;
        }
        return ans;
    }
    
    void cancelRider(int riderId) {
        if(mp.count(riderId)){
            mp[riderId]--;
            if(mp[riderId]==0)mp.erase(riderId);
        }
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */