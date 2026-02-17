class RideSharingSystem {
public:
queue<int>driver,rider;
unordered_set<int>riderSet;
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        rider.push(riderId);
        riderSet.insert(riderId);
    }
    
    void addDriver(int driverId) {
       driver.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        while(!rider.empty() && riderSet.find(rider.front())==riderSet.end()){
            rider.pop();
        }
        if(rider.empty() || driver.empty()){
            return {-1,-1};
        }
        int D=driver.front();
        driver.pop();
        int R=rider.front();
        rider.pop();
        return {D,R};
    }
    
    void cancelRider(int riderId) {
        if(riderSet.count(riderId))
        riderSet.erase(riderId);
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