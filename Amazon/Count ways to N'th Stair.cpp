// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to count number of ways to reach the nth stair
    // when order does not matter.
    long long countWays(int m)
    {
        long long dp[m + 1];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i < m + 1; i++)
        {
            dp[i] = dp[i - 1];
            if (i % 2 == 0)
                dp[i]++;
        }
        return dp[m];
    }
};

// { Driver Code Starts.
int main()
{
    // taking count of testcases
    int t;
    cin >> t;

    while (t--)
    {
        // taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array
    }
    return 0;
} // } Driver Code Ends