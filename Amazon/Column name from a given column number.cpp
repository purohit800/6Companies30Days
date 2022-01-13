class Solution
{
public:
    void reverse(string &s)
    {
        int start = 0;
        int end = s.size() - 1;
        while (start < end)
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
    string colName(long long int n)
    {
        string ans = "";
        while (n >= 26)
        {
            int a = n % 26;
            n = n / 26;
            if (a == 0)
            {
                ans += 'Z';
                n--;
            }
            else
            {
                a = a + 64;
                char b = a;
                ans += b;
            }
        }
        if (n != 0)
        {
            n = n + 64;
            char b = n;
            ans += b;
        }
        reverse(ans);
        return ans;
    }
};