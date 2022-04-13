class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> q;
        for(auto op: ops) {
            if(op == "C")
                q.pop();
            else if(op == "D")
                q.push(q.top() * 2);
            else if(op == "+") {
                int a = q.top(); q.pop();
                int b = q.top(); q.pop();
                int c = a + b;
                q.push(b);
                q.push(a);
                q.push(c);
            }
            else {
                int a = stoi(op);
                q.push(a);
            }
        }
        int ans = 0;
        while(!q.empty()) {
            ans += q.top();
            q.pop();
        }
        return ans;
    }
};
