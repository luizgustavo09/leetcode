class Solution {
public:
    
    bool isPalindrome(int x) {
        if(x < 0) return false;
        string n = to_string(x);
        int l = 0;
        int r = n.length() - 1;
        while(l <= r) {
            if(n[l] != n[r])
                return false;
            ++l, --r;
        }
        return true;
    }
};
