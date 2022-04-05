class Solution {
public:
    static bool comp(string a, string b) {
        return a.length() < b.length();
    }
    bool find(vector<string>& strs, int p) {
        char c = strs[0][p];
        for(auto s : strs) {
            if(s[p] != c)
                return false;
        }
        return true;
    }
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end(), comp);
        string ans = "";
        for(int i = 0; i < strs[0].length(); i++) {
            if(find(strs, i))
                ans += strs[0][i];
            else
                break;
        }
        cout << ans << endl;
        return ans;
    }
};
