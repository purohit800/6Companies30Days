// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        int win_start = 0, win_end = 0;
        long long win_sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (win_sum + arr[i] == s)
                return {win_start + 1, i + 1};
            else if (win_sum + arr[i] < s)
            {
                win_sum += arr[i];
                win_end = i;
            }
            else if (win_sum + arr[i] > s)
            {
                while (win_sum + arr[i] > s && win_start < n)
                {
                    win_sum = win_sum - arr[win_start];
                    win_start++;
                }
                win_sum += arr[i];
                if (win_sum == s)
                    return {win_start + 1, i + 1};
            }
        }
        return {-1};
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
        long long s;
        cin >> n >> s;
        int arr[n];
        const int mx = 1e9;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> res;
        res = ob.subarraySum(arr, n, s);

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends