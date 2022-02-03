class Solution
{
public:
    int check(vector<int> piles, int m, int h)
    {
        int ans = 0;
        for (auto i : piles)
        {
            ans += i / m;
            if (i % m != 0)
                ans++;
        }
        if (ans == h)
            return 0;
        else if (ans > h)
            return 1;
        else
            return -1;
    }
    void bin_s(int m1, int m2, int h, vector<int> piles, int &ans)
    {
        if (m1 > m2)
            return;
        int val = m1 + ((m2 - m1) / 2);
        int a = check(piles, val, h);
        if (a <= 0)
        {
            ans = min(ans, val);
            bin_s(m1, val - 1, h, piles, ans);
        }
        else if (a > 0)
            bin_s(val + 1, m2, h, piles, ans);
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        if (piles.size() == 1)
        {
            int res = 0;
            res = piles[0] / h;
            if (piles[0] % h != 0)
                res++;
            return res;
        }
        int ans = INT_MAX;
        long long int sum = 0;
        int end = 0;
        for (auto i : piles)
        {
            end = max(end, i);
            sum += i;
        }
        int start = sum / h;
        bin_s(start, end, h, piles, ans);
        return ans;
    }
};