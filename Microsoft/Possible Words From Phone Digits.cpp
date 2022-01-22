// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Function to find list of all words possible by pressing given numbers.
    void util(vector<string> &v, int a, unordered_map<int, string> mp)
    {
        vector<string> ans;
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < mp[a].size(); j++)
            {
                ans.push_back(v[i] + mp[a][j]);
            }
        }
        v = ans;
    }
    vector<string> possibleWords(int a[], int N)
    {
        unordered_map<int, string> mp;
        int start = 97;
        for (int i = 2; i < 10; i++)
        {
            string s = "";
            if (i == 7 || i == 9)
            {
                for (int j = 0; j < 4; j++)
                {
                    char c = start;
                    s += c;
                    start++;
                }
            }
            else
            {
                for (int j = 0; j < 3; j++)
                {
                    char c = start;
                    s += c;
                    start++;
                }
            }
            mp[i] = s;
        }
        vector<string> ans;
        string x = mp[a[0]];
        for (int i = 0; i < x.size(); i++)
        {
            string z = "";
            z += x[i];
            ans.push_back(z);
        }
        for (int i = 1; i < N; i++)
        {
            util(ans, a[i], mp);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{

    int T;

    cin >> T; // testcases

    while (T--)
    { // while testcases exist
        int N;

        cin >> N; // input size of array

        int a[N]; // declare the array

        for (int i = 0; i < N; i++)
        {
            cin >> a[i]; // input the elements of array that are keys to be pressed
        }

        Solution obj;

        vector<string> res = obj.possibleWords(a, N);
        for (string i : res)
            cout << i << " ";
        cout << endl;
    }

    return 0;
} // } Driver Code Ends