// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        int incl_curr = 0, excl_curr = 0, incl_prev = arr[0], excl_prev = 0;
        for (int i = 1; i < n; i++)
        {
            excl_curr = max(incl_prev, excl_prev);
            incl_curr = excl_prev + arr[i];
            incl_prev = incl_curr;
            excl_prev = excl_curr;
        }
        return max(excl_prev, incl_prev);
    }
};

// { Driver Code Starts.
int main()
{
    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // taking number of houses
        int n;
        cin >> n;
        int a[n];

        // inserting money of each house in the array
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        Solution ob;
        // calling function FindMaxSum()
        cout << ob.FindMaxSum(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends