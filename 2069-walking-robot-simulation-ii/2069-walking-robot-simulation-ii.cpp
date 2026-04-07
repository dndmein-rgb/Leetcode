class Robot {
public:
int idx=0;
 vector<vector<int>>pos;
 bool moved=false;
    Robot(int width, int height) {
        for(int i=0;i<width;i++){
            pos.push_back({i,0,0});
        }
        for(int j=1;j<height;j++){
            pos.push_back({width-1,j,1});
        }
        for(int i=width-2;i>=0;i--){
            pos.push_back({i,height-1,2});
        }
        for(int j=height-2;j>0;j--){
            pos.push_back({0,j,3});
        }
        pos[0][2]=3;
    }
    
    void step(int num) {
        moved=true;
        idx=(idx+num)%pos.size();
    }
    
    vector<int> getPos() {
        return {pos[idx][0],pos[idx][1]};
    }
    
    string getDir() {
        if(!moved)return "East";
         int d = pos[idx][2];
        if(d == 0) return "East";
        else if(d == 1) return "North";
        else if(d == 2) return "West";
        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */