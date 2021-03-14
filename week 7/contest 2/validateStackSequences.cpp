// 12:02
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.empty() && popped.empty()) return true;
        if(pushed.empty() || popped.empty()) return false;
        
        stack<int> s;
        int popIndex = 0;
        
        for(int n: pushed){
            s.push(n);
            
            while(!s.empty() && s.top() == popped[popIndex]){
                s.pop();
                popIndex++;
                
                if(popIndex == popped.size() && !s.empty()) return false;
            }
        }
        
        return s.size() == 0 && popIndex == popped.size();
    }
};