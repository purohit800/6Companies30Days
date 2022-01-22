// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int lengthOfLongestAP(int A[], int n)
    {
        if (n == 1)
            return 1;
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
            dp[i][n - 1] = 2;
        int a = 2;
        sort(A, A + n);
        for (int j = n - 2; j > 0; j--)
        {
            int i = j - 1, k = j + 1;
            while (i >= 0 and k < n)
            {
                if (A[i] + A[k] == 2 * A[j])
                {
                    dp[i][j] = dp[j][k] + 1;
                    a = max(dp[i][j], a);
                    i--;
                    k++;
                }
                else if (A[i] + A[k] > 2 * A[j])
                {
                    dp[i][j] = 2;
                    i--;
                }
                else
                    k++;
            }
            while (i >= 0)
            {
                dp[i][j] = 2;
                i--;
            }
        }
        return a;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends