string encode(string src)
{
    int s = 1;
    char a = src[0];
    string ans = "";
    for (int i = 1; i < src.size(); i++)
    {
        if (a != src[i])
        {
            ans += a;
            ans += to_string(s);
            s = 1;
            a = src[i];
        }
        else
            s++;
    }
    ans += a;
    ans += to_string(s);
    return ans;
}