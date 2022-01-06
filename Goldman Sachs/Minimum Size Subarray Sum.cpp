class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int win_start = 0;
        int win_end = 0;
        int win_sum = 0;
        int win_size = 0;
        int ans = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= target)
                return 1;
            win_end = i;
            win_sum += nums[i];
            win_size++;
            while (win_size > 1)
            {
                if (win_sum < target)
                    break;
                else if (win_sum >= target)
                    ans = min(ans, win_size);
                win_sum -= nums[win_start];
                win_start++;
                win_size--;
            }
        }
        if (ans == INT_MAX)
            return 0;
        return ans;
    }
};