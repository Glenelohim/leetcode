class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        int size = s.length();
        if (size <= 10)
        {
        	return res;
        }
        unordered_map<string, int> u_map;
        for (int i = 0; i < size - 9; i++)
        {
        	string temp = s.substr(i, 10);
        	if (u_map.find(temp) != u_map.end())
        	{
        		if (u_map[temp] == 1)
        		{
        			u_map[temp] = 2;
        			res.push_back(temp);
        		}
        	}
        	else
        	{
        		u_map[temp] = 1;
        	}
        }
        return res;
    }
};

class Solution {
public:
	//brute force. but TLE!!
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        int size = s.length();
        if (size <= 10)
        {
        	return res;
        }

        string patt1, patt2;
        for (int i = 0; i < size - 10; i++)
        {
        	patt1 = s.substr(i, 10);
        	for (int j = i + 1; j < size - 9; j++)
        	{
        		patt2 = s.substr(j, 10);
        		if (patt1 == patt2)
        		{
        			res.push_back(patt1);
        		}
        	}
        }
        return res;
    }
};