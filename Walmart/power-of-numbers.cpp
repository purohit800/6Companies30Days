// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

// } Driver Code Ends
class Solution
{
public:
    // You need to complete this fucntion
    long long power(int x, int y)
    {
        int res = 1; // Initialize result
        x = x % mod; // Update x if it is more than or
        if (x == 0)
            return 0; // In case x is divisible by p;
        while (y > 0)
        {
            if (y % 2 == 1)
                res = (res * x) % mod;
            y = y / 2;
            x = (x * x) % mod;
        }
        return res;
    }
};

// { Driver Code Starts.

// compute reverse of a number
long long rev(long long n)
{
    long long rev_num = 0;
    while (n > 0)
    {
        rev_num = rev_num * 10 + n % 10;
        n = n / 10;
    }
    return rev_num;
}

int main()
{
    int T;
    cin >> T; // testcases

    while (T--)
    {
        long long N;
        cin >> N; // input N

        long long R = 0;

        // reverse the given number n
        R = rev(N);
        Solution ob;
        // power of the number to it's reverse
        long long ans = ob.power(N, R);
        cout << ans << endl;
    }
} // } Driver Code Ends