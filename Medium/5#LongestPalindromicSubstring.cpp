class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int n = s.length();
        int l = 0, r = 0;
        for(int i = 0; i < n; i++) {
            int a = expand(s, i, i);
            int b = expand(s, i, i + 1);
            int at = max(a, b);
            if(at > r - l) {
                l = i - (at - 1)/2;
                r = i + at/2;
            }
        }
        for(int i = l + 1; i < r; i++)
            ans += s[i];
        return ans;
    }
    int expand(string &s, int l, int r) {
        int n = s.length();
        while(l >= 0 and r < n and s[l] == s[r])
            --l, ++r;
        return r - l + 1;
        
    }
};


