// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    /*You are required to complete this method */
    int atoi(string str)
    {
        int a = 0;
        int i = 0;
        bool check = false;
        if (str[i] == '-')
        {
            check = true;
            i++;
        }
        for (; i < str.size(); i++)
        {
            a = a * 10;
            int b = str[i] - '0';
            if (b > 9 || b < 0)
                return -1;
            a += b;
        }
        if (check)
            return -1 * a;
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
        string s;
        cin >> s;
        Solution ob;
        cout << ob.atoi(s) << endl;
    }
} // } Driver Code Ends