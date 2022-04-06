class Solution {
public:
    bool isValid(string s) {
        stack<char> p;
        map<char, char> mapa;
        mapa[')'] = '(';
        mapa[']'] = '[';
        mapa['}'] = '{';
        for(int ch : s) {
            if(ch == '(' or ch == '[' or ch == '{')
                p.push(ch);
            else {
                if(p.empty())
                    return false;
                char topo = p.top();
                p.pop();
                if(mapa[ch] != topo)
                    return false;
            }
        }
        if(!p.empty())
            return false;
        return true;
    }
};
