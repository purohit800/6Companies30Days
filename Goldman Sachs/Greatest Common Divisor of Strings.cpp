class Solution
{
public:
    bool checker(string str, string x)
    {
        int a = str.size() / x.size();
        string s = "";
        for (int i = 0; i < a; i++)
            s += x;
        return s == str;
    }
    string gcdOfStrings(string str1, string str2)
    {
        string sel = str1;
        if (str1.size() > str2.size())
            sel = str2;
        string ans = "";
        for (int pos = 1; pos <= sel.size(); pos++)
        {
            string x = sel.substr(0, pos);
            if (checker(str2, x) && checker(str1, x))
            {
                ans = x;
            }
        }
        return ans;
    }
};