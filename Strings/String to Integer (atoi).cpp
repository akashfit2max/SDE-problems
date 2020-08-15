class Solution
{
public:
    int myAtoi(string str)
    {
        if (str.length() == 0)
        {
            return 0;
        }
        int sign = 1, i = 0, n = str.length();
        //skip the spaces
        while (i < n && str[i] == ' ')
        {
            i++;
        }
        //if i reaches the end all the elements are spaces
        if (i >= n)
        {
            return 0;
        }
        //find the sign
        if (str[i] == '+' || str[i] == '-')
        {
            sign = str[i] == '+' ? 1 : -1;
            i++;
        }
        long res = 0;
        //convert string to integer
        while (i < n && isdigit(str[i]) == true)
        {
            res = res * 10 + (str[i] - '0');
            i++;
            //value is greater than INT_MAX or INT_MIN
            if (res * sign > INT_MAX || res * sign < INT_MIN)
            {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
        }
        return (int)(res * sign);
    }
};