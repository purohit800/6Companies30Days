class Solution
{
public:
    long long divide(long long dividend, long long divisor)
    {
        int sign = 1;
        if (dividend < 0)
            sign = -1;
        if (divisor < 0)
            sign = -sign;
        long long ans = 0;
        int temp = 0;
        for (int i = 31; i >= 0; i--)
        {
            if (temp + (divisor << i) <= dividend)
            {
                temp += divisor << i;
                ans += 1LL << i;
            }
        }
        if (sign == -1)
            ans = -ans;
        return ans;
    }
};