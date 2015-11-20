class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len = s.length();
        if (len <= 1)
        	return true;
        string sToOrder = "";
        string tToOrder = "";
        map<char, int> s_map;
        map<char, int> t_map;
        s_map[s[0]] = 1;
        t_map[t[0]] = 1;
        int s_index = 2;
        int t_index = 2;
        for (int i = 0; i < len; i++)
        {
        	map<char, int>::iterator temp;
        	temp = s_map.find(s[i]);
        	if (temp != s_map.end())
        		sToOrder += temp->second;
        	else
        	{
        		s_map[s[i]] = s_index;
        		sToOrder += s_index + '0';
        		s_index ++;
        	}

        	temp = t_map.find(t[i]);
        	if (temp != t_map.end())
        		tToOrder += temp->second;
        	else
        	{
        		t_map[t[i]] = t_index;
        		tToOrder += t_index + '0';
        		t_index ++;
        	}
        }
        return (sToOrder == tToOrder);
    }
};