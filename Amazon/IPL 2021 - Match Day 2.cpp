// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void add_element(deque<int> &dq, int a)
    {
        if (dq.empty())
            dq.push_front(a);
        else
        {
            if (a > dq.front())
                dq.push_front(a);
            else if (a < dq.back())
                dq.push_back(a);
            else
            {
                while (dq.back() < a)
                    dq.pop_back();
                dq.push_back(a);
            }
        }
    }
    vector<int> max_of_subarrays(vector<int> arr, int n, int k)
    {
        deque<int> dq;
        vector<int> v;
        unordered_map<int, int> mp;
        for (int i = 0; i < k; i++)
        {
            add_element(dq, arr[i]);
            mp[arr[i]]++;
        }
        v.push_back(dq.front());
        for (int i = k; i < n; i++)
        {
            mp[arr[i - k]]--;
            add_element(dq, arr[i]);
            mp[arr[i]]++;
            while (mp[dq.front()] == 0)
                dq.pop_front();
            v.push_back(dq.front());
        }
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

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
} // } Driver Code Ends