// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    string reverse(string h)
    {
        string t = h;
        int start = 0, end = h.size() - 1;
        while (start < end)
        {
            swap(t[start], t[end]);
            start++;
            end--;
        }
        return t;
    }
    string nextPalin(string N)
    {
        if (N.size() <= 3)
            return "-1";
        if (N.size() % 2 == 0)
        {
            int a = N.size() / 2;
            string half = "";
            for (int i = 0; i < a; i++)
                half += N[i];
            if (next_permutation(half.begin(), half.end()))
            {
                string half1 = reverse(half);
                return half + half1;
            }
            else
                return "-1";
        }
        else
        {
            int a = N.size() / 2;
            string half = "";
            for (int i = 0; i < a; i++)
                half += N[i];
            if (next_permutation(half.begin(), half.end()))
            {
                string half1 = reverse(half);
                return half + N[a] + half1;
            }
            else
                return "-1";
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
        string s;
        cin >> s;
        Solution obj;
        cout << obj.nextPalin(s) << endl;
    }
    return 0;
} // } Driver Code Ends