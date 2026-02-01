class RideSharingSystem {
public:
    queue<int>driver,rider;
    unordered_set<int>st; //rider
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        rider.push(riderId);
        st.insert(riderId);
    }
    
    void addDriver(int driverId) {
        driver.push(driverId);
        
    }
    
    vector<int> matchDriverWithRider() {
        while(!rider.empty() && !st.count(rider.front())){
            rider.pop();
        }
        if(driver.empty()||rider.empty()){
            return {-1,-1};
        }
        int d=driver.front();
        int r=rider.front();
        driver.pop();
        rider.pop();
        st.erase(r);
            return {d,r};
    }
    
    void cancelRider(int riderId) {
        if(st.count(riderId))st.erase(riderId);
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