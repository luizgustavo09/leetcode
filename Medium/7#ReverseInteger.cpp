class Solution {
public:
    int reverse(int x) {
        int n = abs(x);
        string s = to_string(n);
        std::reverse(s.begin(), s.end());
        long long int ans = stoll(s);
        if(x < 0)
            ans *= -1;
        long long int limit = 1 << 31;
        limit *= -1;
        if(ans < -limit or ans > limit - 1)
            ans = 0;
        return (int) ans;
    }
};
