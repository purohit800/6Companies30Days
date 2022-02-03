// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
const int MAX_DIGITS = 5;

int missingNumber(const string &str);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        cout << missingNumber(str) << endl;
    }
    return 0;
}
// } Driver Code Ends

/* You are required to complete this function
which return the required missing number
if present else return -1*/
int get_value(string str, int i, int length)
{
    if (i + length > str.size())
        return -1;
    int ans = 0;
    for (int j = i; j < i + length; j++)
    {
        int a = str[j] - '0';
        if (a < 0 and a > 9)
            return -1;
        ans = (ans * 10) + a;
    }
    return ans;
}
int missingNumber(const string &str)
{
    for (int l = 1; l <= 6; l++)
    {
        int i = 0;
        int ans = 0;
        vector<int> v;
        int k = l;
        int count = 0;
        while (i < str.size())
        {
            int curr = get_value(str, i, k);
            if (curr == -1)
                count = 100;
            i += k;
            cout << curr << " ";
            v.push_back(curr);
            int a = log10(curr + 1);
            int b = log10(curr);
            if (curr != 0 and a > b)
                k++;
        }
        for (int i = 0; i < v.size() - 1; i++)
        {
            if (v[i + 1] - v[i] > 2 or v[i] > v[i + 1])
            {
                count = 100;
                break;
            }
            else if (v[i + 1] != v[i] + 1)
            {
                count++;
                ans = v[i] + 1;
            }
        }
        if (count == 1)
            return ans;
    }
    return -1;
}
