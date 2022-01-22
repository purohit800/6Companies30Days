// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int>> remove_dup(vector<vector<int>> v)
    {
        vector<vector<int>> ans;
        if (v.size() == 0)
            return ans;
        for (int i = 0; i < v.size() - 1; i++)
        {
            if (v[i] != v[i + 1])
                ans.push_back(v[i]);
        }
        ans.push_back(v[v.size() - 1]);
        return ans;
    }
    vector<vector<int>> fourSum(vector<int> &arr, int k)
    {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<vector<int>> v;
        for (int i = 0; i < n - 3; i++)
        {
            for (int j = i + 1; j < n - 2; j++)
            {
                int target = k - arr[i] - arr[j];
                int start = j + 1, end = n - 1;
                while (start < end)
                {
                    if (arr[start] + arr[end] == target)
                    {
                        v.push_back({arr[i], arr[j], arr[start], arr[end]});
                        start++;
                        end--;
                    }
                    else if (arr[start] + arr[end] > target)
                        end--;
                    else
                        start++;
                }
            }
        }
        sort(v.begin(), v.end());
        v = remove_dup(v);
        return v;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int>> ans = ob.fourSum(a, k);
        for (auto &v : ans)
        {
            for (int &u : v)
            {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty())
        {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends