class Solution
{
public:
    void binar(MountainArray &mountainArr, int start, int end, int &val)
    {
        if (start > end)
            return;
        int check = (start + end) / 2;
        if (check < 0 or check >= mountainArr.length())
            return;
        int a = mountainArr.get(check);
        cout << a << " ";
        if (check + 1 < 0 or check + 1 >= mountainArr.length())
            return;
        int b = mountainArr.get(check + 1);
        if (check - 1 < 0 or check - 1 >= mountainArr.length())
            return;
        int c = mountainArr.get(check - 1);
        if (a > b and a > c)
        {
            val = check;
            return;
        }
        else if (a > c)
            binar(mountainArr, check, end, val);
        else if (a > b)
            binar(mountainArr, start, check, val);
    }
    void binar1(MountainArray &mountainArr, int start, int end, int &val, int target)
    {
        if (start > end)
            return;
        int check = (start + end) / 2;
        if (check < 0 or check >= mountainArr.length())
            return;
        int a = mountainArr.get(check);
        if (a == target)
        {
            val = check;
            return;
        }
        else if (a < target)
            binar1(mountainArr, check + 1, end, val, target);
        else if (a > target)
            binar1(mountainArr, start, check - 1, val, target);
    }
    void binar2(MountainArray &mountainArr, int start, int end, int &val, int target)
    {
        if (start > end)
            return;
        int check = (start + end) / 2;
        if (check < 0 or check >= mountainArr.length())
            return;
        int a = mountainArr.get(check);
        if (a == target)
        {
            val = check;
            return;
        }
        else if (a < target)
            binar2(mountainArr, start, check - 1, val, target);
        else if (a > target)
            binar2(mountainArr, check + 1, end, val, target);
    }
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int start = 0, end = mountainArr.length();
        int idx = -1, hold = -1;
        binar(mountainArr, start, end, idx);
        if (mountainArr.get(idx) == target)
            return idx;
        else
        {
            binar1(mountainArr, start, idx - 1, hold, target);
            if (hold != -1)
                return hold;
            else
                binar2(mountainArr, idx + 1, end, hold, target);
            if (hold == -1)
                return -1;
        }
        return hold;
    }
};