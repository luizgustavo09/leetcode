
//Essa solução tem como referência o geeks for geeks
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        map<char, int> mapa;
        for(auto c : s)
            mapa[c] = -1;
        int l = 0;
        int ans = 0;
        for(int r = 0; r < n; r++) {
            char c = s[r];
            l = max(l, mapa[c] + 1);
            ans = max(ans, r - l + 1);
            mapa[c] = r;
        }
        return ans;
    }
};
