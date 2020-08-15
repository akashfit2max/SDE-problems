class Solution
{
public:
    string intToRoman(int num)
    {
        string table[4][10] = {{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
                               {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                               {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                               {"", "M", "MM", "MMM"}};
        int count = 0;
        string ans = "";
        while (num > 0)
        {
            int temp = num % 10;
            ans = table[count][temp] + ans;
            num = num / 10;
            count++;
        }
        // reverse(ans.begin(),ans.end());
        return ans;
    }
};