class Solution
{
public:
    bool checker(vector<int> &nums, int m, int mid)
    {
        int total = 0, subarr = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > mid)
                return false;
            if (total + nums[i] <= mid)
                total += nums[i];
            else
            {
                total = nums[i];
                subarr++;
            }
        }
        subarr++;
        return subarr <= m;
    }
    int splitArray(vector<int> &nums, int m)
    {
        int start = 0;
        int end = pow(10, 9) + 1;
        while (start < end)
        {
            int mid = (start + end) / 2;
            if (checker(nums, m, mid))
                end = mid;
            else
                start = mid + 1;
        }
        return start;
    }
};