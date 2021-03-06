class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(start < 0 || start >= arr.size()) return false;
        vector<bool> visited(arr.size(),false);
        bool ret = false;
        
        list< pair<int, int> > l;
        
        if(arr[start] == 0) return true;
        
        l.push_back({arr[start], start});
        
        
        while(l.size() > 0){
            int popsAllowed = l.size();
            while(popsAllowed > 0){
                auto currentNum = l.front();
                l.pop_front();
                
                if(currentNum.first == 0) return true;
                    
                visited[currentNum.second] = true;
                
                if(currentNum.first + currentNum.second > -1 &&
                  currentNum.first + currentNum.second < arr.size() &&
                   !visited[currentNum.first + currentNum.second]
                  )
                {
                    l.push_back({arr[currentNum.first + currentNum.second], currentNum.first + currentNum.second});
                }
                 if( currentNum.second - currentNum.first > -1 &&
                  currentNum.second - currentNum.first < arr.size()&&
                   !visited[currentNum.second - currentNum.first]
                  )
                {
                    l.push_back({arr[currentNum.second - currentNum.first], currentNum.second - currentNum.first});
                }
                
                popsAllowed--;
            }
        }
        
        
        
        return ret; 
    }
};