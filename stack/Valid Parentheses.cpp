#include <stack>
#include <string>
class Solution
{
public:
    char getMatchingBrace(char ch)
    {
        if (ch == ')')
        {
            return '(';
        }
        if (ch == ']')
        {
            return '[';
        }
        if (ch == '}')
        {
            return '{';
        }
        return ch;
    }
    bool isValid(std::string s)
    {
        std::stack<char> stk;
        if (s.empty())
        {
            return true;
        }
        if (s.size() % 2 != 0)
        {
            return false;
        }
        for (auto ch : s)
        {
            if (ch == '(' || ch == '{' || ch == '[')
            {
                stk.push(ch);
            }
            else
            {
                if (stk.empty())
                {
                    return false;
                }
                if (getMatchingBrace(ch) != stk.top())
                {
                    return false;
                }
                stk.pop();
            }
        }
        if (stk.empty())
        {
            return true;
        }
        return false;
    }
};