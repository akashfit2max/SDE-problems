class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            // Can't be empty at this point...
            if (st.empty())
                return false;
            if (s[i] == ')')
            {
                int x = st.top();
                st.pop();
                if (x != '(')
                    return false;
            }
            else if (s[i] == '}')
            {
                int x = st.top();
                st.pop();
                if (x != '{')
                    return false;
            }
            else if (s[i] == ']')
            {
                int x = st.top();
                st.pop();
                if (x != '[')
                    return false;
            }
        }

        return st.empty();
    }
};