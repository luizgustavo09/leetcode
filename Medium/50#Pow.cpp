class Solution {
public:
    double fastPow(double base, long long int exp) {
       if(exp == 0)
            return 1;
        double aux = fastPow(base, exp >> 1);
        aux *= aux;
        if(exp & 1)
            aux *= base;
        return aux;
    }
    double myPow(double x, int n) {
        double ans = fastPow(x, (long long int)abs(n));
        return n < 0 ? 1.0/ans : ans;
    }
};
