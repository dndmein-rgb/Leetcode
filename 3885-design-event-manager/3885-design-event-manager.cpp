class EventManager {
public:
priority_queue<pair<int,int>>pq;
unordered_map<int,int>mp;//eventID,pr

    EventManager(vector<vector<int>>& events) {
        for(auto& e:events){
           int id = e[0], pr = e[1];
           pq.push({pr,-id});
           mp[id]=pr;
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        pq.push({newPriority,-eventId});
        mp[eventId]=newPriority;
    }
    
    int pollHighest() {
        if(pq.empty())return -1;
        while(!pq.empty()){
        auto [pr,id]=pq.top();
        if(mp.count(-id) && mp[-id]==pr){
            pq.pop();
            mp.erase(-id);
            return -id;
        }
        pq.pop();
        }
       return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */