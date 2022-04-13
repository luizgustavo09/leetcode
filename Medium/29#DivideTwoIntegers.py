class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        ans = abs(dividend)//abs(divisor)
        if (dividend < 0) ^ (divisor < 0):
            ans *= -1
        return min(ans, 2**31 - 1)
