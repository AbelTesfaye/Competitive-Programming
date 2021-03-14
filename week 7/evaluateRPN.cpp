class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size() == 1) return stoi(tokens[0]);
        
        int ret = INT_MIN;
            
        stack<int> s;
        
        for(int i = 0; i < tokens.size(); i++){
            string n = tokens[i];

            if(n == "*") {
                int n2 = s.top(); s.pop();
                int n1 = s.top(); s.pop();

                int nn = n1 * n2;
                s.push(nn);
            }
            else if(n == "/") {
                int n2 = s.top(); s.pop();
                int n1 = s.top(); s.pop();

                int nn = n1 / n2;
                s.push(nn);
            }
            else if(n == "+") {
                int n2 = s.top(); s.pop();
                int n1 = s.top(); s.pop();

                int nn = n1 + n2;
                s.push(nn);
            }
            else if(n == "-") {
                int n2 = s.top(); s.pop();
                int n1 = s.top(); s.pop();

                int nn = n1 - n2;
                s.push(nn);
            } else {
                int nn = stoi(n);
                s.push(nn);
            }

            
            if(i == tokens.size() - 1) ret = s.top();
        }
        
        return ret;
    }
};