// Given an input string, reverse the string word by word.
class Solution
{
public:
    string reverseWords(string s)
    {
        vector<string> v;
        stringstream ss(s);
        string word;
        while (ss >> word)
        {
            v.push_back(word);
        }
        string ans;
        for (int i = v.size() - 1; i >= 0; i--)
        {
            if (i != 0)
                ans += v[i] + " ";
            else
            {
                ans += v[i];
            }
        }
        return ans;
    }
};