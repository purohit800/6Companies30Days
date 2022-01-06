// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool canPair(vector<int> nums, int k)
    {
        if (nums.size() % 2 == 1)
            return false;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i] % k]++;
            nums[i] = nums[i] % k;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            bool a = false;
            if (m[nums[i]] > 0)
            {
                if (nums[i] == 0)
                {
                    if (m[nums[i]] >= 2)
                    {
                        m[nums[i]] -= 2;
                        a = true;
                    }
                }
                else if (m[k - nums[i]] > 0)
                {
                    m[nums[i]]--;
                    m[k - nums[i]]--;
                    a = true;
                }
                if (!a)
                    return false;
            }
        }
        return true;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++)
            cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
} // } Driver Code Ends