class Solution
{
public:
    bool check(vector<int> &weights, int days, int cap)
    {
        int x = 0;
        int c = 0;
        for (int i : weights)
        {
            x += i;
            if (x > cap)
            {
                c++;
                x = i;
            }
        }
        return c + 1 <= days;
    }
    void bin_search(int start, int end, vector<int> &weights, int days, int &ans)
    {
        if (start > end)
            return;
        int mid = (start + end) / 2;
        if (check(weights, days, mid))
        {
            ans = min(ans, mid);
            bin_search(start, mid - 1, weights, days, ans);
        }
        else
            bin_search(mid + 1, end, weights, days, ans);
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int ans = INT_MAX;
        int start = 0, end = 0;
        for (auto i : weights)
        {
            end += i;
            start = max(start, i);
        }
        bin_search(start, end, weights, days, ans);
        return ans;
    }
};