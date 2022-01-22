// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define N 1000

// } Driver Code Ends
// you are required to complete this function
// function should print the required range
class Solution
{
public:
    struct point
    {
        int val;
        int index;
        int list_index;
        point(int a, int b, int c)
        {
            val = a;
            index = b;
            list_index = c;
        }
    };
    struct mycmp
    {
        bool operator()(point &p1, point &p2)
        {
            return p1.val > p2.val;
        }
    };
    pair<int, int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
        priority_queue<point, vector<point>, mycmp> pq;
        int m = 0;
        for (int i = 0; i < k; i++)
        {
            m = max(m, KSortedArray[i][0]);
            point p(KSortedArray[i][0], 0, i);
            pq.push(p);
        }
        int size = INT_MAX;
        pair<int, int> ans;
        while (!pq.empty())
        {
            point temp = pq.top();
            pq.pop();
            int x = temp.val;
            int y = temp.index;
            int z = temp.list_index;
            if (m - x < size)
            {
                size = m - x;
                ans = make_pair(x, m);
            }
            if (y + 1 < n)
            {
                point t2(KSortedArray[z][y + 1], y + 1, z);
                pq.push(t2);
                m = max(KSortedArray[z][y + 1], m);
            }
            else
                break;
        }
        return ans;
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
        int arr[N][N];
        pair<int, int> rangee;
        for (int i = 0; i < k; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        rangee = obj.findSmallestRange(arr, n, k);
        cout << rangee.first << " " << rangee.second << "\n";
    }
    return 0;
}

// } Driver Code Ends