// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void add_edge(vector<int> adj[], int i, int j)
    {
        adj[i].push_back(j);
    }

    string findOrder(string dict[], int N, int K)
    {
        vector<int> adj[K];
        int indegree[K];
        for (int i = 0; i < K; i++)
            indegree[i] = 0;
        for (int i = 0; i < N - 1; i++)
        {
            int n = min(dict[i].size(), dict[i + 1].size());
            for (int j = 0; j < n; j++)
            {
                if (dict[i][j] != dict[i + 1][j])
                {
                    indegree[dict[i + 1][j] - 'a']++;
                    add_edge(adj, dict[i][j] - 'a', dict[i + 1][j] - 'a');
                    break;
                }
            }
        }
        queue<int> q;
        for (int i = 0; i < K; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        string ans = "";
        while (!q.empty())
        {
            int a = q.front();
            int x = 'a' + a;
            ans += x;
            q.pop();
            for (auto i : adj[a])
            {
                indegree[i]--;
                if (indegree[i] == 0)
                    q.push(i);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b)
{
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++)
    {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++)
            cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i])
                f = false;

        if (f)
            cout << 1;
        else
            cout << 0;
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends