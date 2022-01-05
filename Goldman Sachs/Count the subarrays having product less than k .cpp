class Solution
{
public:
    int countSubArrayProductLessThanK(const vector<int> &a, int n, long long k)
    {
        int start = 0, end = 1;
        int ans = 0;
        long long s = a[start] * a[end];
        for (int i : a)
            if (i < k)
                ans++;
        while (start != end)
        {
            if (s < k)
        }
    }
};