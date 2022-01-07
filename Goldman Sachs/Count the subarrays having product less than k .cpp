class Solution
{
public:
    int countSubArrayProductLessThanK(const vector<int> &nums, int n, long long k)
    {
        int win_start = 0;
        int win_end = 0;
        int win_size = 0;
        long long win_prod = 1;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= k)
            {
                win_start = -1;
                win_size = 0;
                win_prod = 1;
            }
            else if (win_prod * nums[i] < k)
            {
                if (win_start == -1)
                    win_start = i;
                win_end = i;
                win_size++;
                win_prod = win_prod * nums[i];
                ans += win_size;
            }
            else if (win_prod * nums[i] >= k)
            {
                while (win_size > 0)
                {
                    win_size--;
                    win_prod = win_prod / nums[win_start];
                    win_start++;
                    if (win_prod * nums[i] < k)
                    {
                        win_end = i;
                        win_size++;
                        win_prod = win_prod * nums[i];
                        ans += win_size;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};