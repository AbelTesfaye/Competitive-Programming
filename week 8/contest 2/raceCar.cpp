class Solution {
public:
    struct moves{
        int pos, speed, moves;
    };
    
    unordered_set<string> vis;
    
    bool willGetCloser(moves newMove, moves oldMove, int target){
        if(newMove.pos < 0 || newMove.pos > 10000) return false;
        
        return true;
    }
    
    int racecar(int target) {
        
        queue< moves > q;
        
        q.push({0, 1, 0});
        
        while(q.size()){
            auto p = q.front(); q.pop();
            // cout<<"p.pos: "<<p.pos<<" p.speed: "<<p.speed<<endl;
            
            string key = to_string(p.pos) +","+ to_string(p.speed);
            if(vis.find(key) != vis.end()) continue;
            
            vis.insert(key);
            
            if(p.pos == target) return p.moves;
            
            //accelerate
            auto a = p;
            a.pos += a.speed;
            a.speed *= 2;
            a.moves++;
            
            if(a.pos == target){
                return a.moves;
            }
            string keyA = to_string(a.pos) +","+ to_string(a.speed);
            if(vis.find(keyA) == vis.end() && willGetCloser(a, p, target)){
                q.push(a);
            }
            
            
            //reverse
            auto b = p;
            if(b.speed > 0){
                b.speed = -1;
            } else {
                b.speed = 1;
            }
            
            b.moves++;
            
            string keyB = to_string(b.pos) +","+ to_string(b.speed);
            if(vis.find(keyB) == vis.end() && willGetCloser(b, p, target)) {
                q.push(b);
            }
        }
        
        
        return -1;
    }
};