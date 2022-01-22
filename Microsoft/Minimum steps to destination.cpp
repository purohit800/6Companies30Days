// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int minSteps(int D)
    {
        for (int i = 1; i < 2 * D; i++)
        {
            int sum = (i * (i + 1)) / 2;
            if (sum == D)
                return i;
            if ((sum - D) % 2 == 0 && sum > D)
                return i;
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int D;
        cin >> D;

        Solution ob;
        cout << ob.minSteps(D) << "\n";
    }
    return 0;
} // } Driver Code Ends