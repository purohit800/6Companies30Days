class Solution
{
public:
    int doOverlap(int L1[], int R1[], int L2[], int R2[])
    {
        int s_1 = L1[0];
        int e_1 = R1[0];
        int s_2 = L2[0];
        int e_2 = R2[0];
        int st_1 = L1[1];
        int en_1 = R1[1];
        int st_2 = L2[1];
        int en_2 = R2[1];
        bool a;
        if (e_1 > e_2)
            a = s_1 > e_2;
        else
            a = s_2 > e_1;
        bool b;
        if (en_2 > en_1)
            b = en_2 > st_1;
        else
            b = en_1 > st_2;
        a = a || b;
        return !a;
    }
};