class Solution {
private:
	map<char, vector<char>> phone;
	vector<string> res;
public:

	void init()
	{
		phone.clear();
		phone['2'].push_back('a');
		phone['2'].push_back('b');
		phone['2'].push_back('c');
		phone['3'].push_back('d');
		phone['3'].push_back('e');
		phone['3'].push_back('f');
		phone['4'].push_back('g');
		phone['4'].push_back('h');
		phone['4'].push_back('i');
		phone['5'].push_back('j');
		phone['5'].push_back('k');
		phone['5'].push_back('l');
		phone['6'].push_back('m');
		phone['6'].push_back('n');
		phone['6'].push_back('o');
		phone['7'].push_back('p');
		phone['7'].push_back('q');
		phone['7'].push_back('r');
		phone['7'].push_back('s');
		phone['8'].push_back('t');
		phone['8'].push_back('u');
		phone['8'].push_back('v');
		phone['9'].push_back('w');
		phone['9'].push_back('x');
		phone['9'].push_back('y');
		phone['9'].push_back('z');
	}

	void dfs(int depth, int maxdep, const string& digits, string str)
	{
		if (depth == maxdep)
		{
			res.push_back(str);
			return;
		}

		for (int i=0, bound=phone[digits[depth]].size(); i<bound; i++)
		{
			dfs(depth+1, maxdep, digits, str+phone[digits[depth]][i]);
		}
	}

    vector<string> letterCombinations(string digits) {
    	res.clear();
        int len = digits.size();
        if (0 == len)
        {
        	return res;
        }
        
        init();
        dfs(0, len, digits, "");

        return res;
    }
};