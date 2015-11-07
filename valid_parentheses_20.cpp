class Solution
{
public:
	bool isValid(string s)
	{
		if (!s.length())
			return true;
		std::stack<char> s1;
		std::stack<char> s2;
		for (int i = 0; i < s.length(); i++)
			s1.push(s[i]);
		while (!s1.empty())
		{
			char temp = s1.top();
			if (temp == ')' || temp == ']' || temp == '}')
			{
				s2.push(temp);
				s1.pop();
			}
			if (temp == '(')
			{
				if (s2.empty() || s2.top() != ')')
					return false;
				s1.pop();
				s2.pop();
			}

			if (temp == '[')
			{
				if (s2.empty() || s2.top() != ']')
					return false;
				s1.pop();
				s2.pop();
			}

			if (temp == '{')
			{
				if (s2.empty() || s2.top() != '}')
					return false;
				s1.pop();
				s2.pop();
			}
		}
		if (!s2.empty())
		    return false;
		return true;
	}
};