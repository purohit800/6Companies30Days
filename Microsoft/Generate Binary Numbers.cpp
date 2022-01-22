// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Function to generate binary numbers from 1 to N using a queue.
void reverse(string &s)
{
    int start = 0, end = s.size() - 1;
    while (start < end)
    {
        swap(s[start], s[end]);
        start++;
        end--;
    }
}
string binary_conv(int n)
{
    string ans = "";
    while (n != 0)
    {
        int a = n & 1;
        if (a == 0)
            ans += "0";
        else
            ans += "1";
        n = n >> 1;
    }
    reverse(ans);
    return ans;
}
vector<string> generate(int N)
{
    vector<string> v;
    for (int i = 1; i <= N; i++)
        v.push_back(binary_conv(i));
    return v;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> ans = generate(n);
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends