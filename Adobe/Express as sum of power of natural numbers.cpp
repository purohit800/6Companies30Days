// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    int mod = pow(10, 9) + 7;
    long long int checkRecursive(int x, int n, int curr_num, int curr_sum, vector<vector<long long int>> &dp)
    {
        if (dp[curr_num][curr_sum] != -1)
            return dp[curr_num][curr_sum];
        long long int results = 0;
        long long int p = pow(curr_num, n);
        while (p + curr_sum < x)
        {
            results += checkRecursive(x, n, curr_num + 1, p + curr_sum, dp);
            results = results % mod;
            curr_num++;
            p = pow(curr_num, n);
        }
        if (p + curr_sum == x)
            results++;
        dp[curr_num][curr_sum] = results;
        return results % mod;
    }
    long long int numOfWays(int n, int x)
    {
        vector<vector<long long int>> dp(n + 1, vector<long long int>(n + 1, -1));
        return checkRecursive(n, x, 1, 0, dp);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        Solution ob;
        cout << ob.numOfWays(n, x) << endl;
    }
    return 0;
}
// } Driver Code Ends