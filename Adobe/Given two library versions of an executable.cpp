#include <bits/stdc++.h>
using namespace std;
int sol(string s1, string s2)
{
    vector<int> v1;
    vector<int> v2;
    int a = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] == '.')
        {
            v1.push_back(a);
            a = 0;
        }
        else
        {
            a = a * 10;
            a += s1[i] - '0';
        }
    }
    v1.push_back(a);
    a = 0;
    for (int i = 0; i < s2.size(); i++)
    {
        if (s2[i] == '.')
        {
            v2.push_back(a);
            a = 0;
        }
        else
        {
            a = a * 10;
            a += s2[i] - '0';
        }
    }
    v2.push_back(a);
    a = 0;
    int k = min(v1.size(), v2.size());
    for (int i = 0; i < k; i++)
    {
        cout << v1[i] << " " << v2[i] << endl;
        if (v1[i] > v2[i])
        {
            a = 1;
            break;
        }
        else if (v1[i] < v2[i])
        {
            a = 2;
            break;
        }
    }
    if (a == 0)
    {
        if (v1.size() == v2.size())
            return 0;
        else if (v1.size() > v2.size())
            return 1;
        else
            return 2;
    }
    return a;
}
int main()
{
    string s1 = "10.1";
    string s2 = "10.1";
    cout << sol(s1, s2);
    return 0;
}