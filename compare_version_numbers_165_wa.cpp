class Solution {
public:
	std::vector<int> splitDoc(string version)
	{
		std::vector<int> res;
		for (int i = 0; i < version.length(); i++)
		{
			if (version[i] == '.')
				res.push_back(i);
		}
		return res;
	}

	int compareString(string v1, string v2)
	{
		int v1_len = v1.length();
		int v2_len = v2.length();
		int v1_zero = 0;
		int v2_zero = 0;
		for (; v1_zero < v1_len; v1_zero++)
		{
			if (v1[v1_zero] != '0')
				break;
		}
		for (; v2_zero < v2_len; v2_zero++)
		{
			if (v2[v2_zero] != '0')
				break;
		}

		if ((v1_len - v1_zero) < (v2_len - v2_zero))
			return -1;
		else if ((v1_len - v1_zero) > (v2_len - v2_zero))
			return 1;
		else
		{
			for (int i = v1_zero, j = v2_zero; i < v1_len, j < v2_len; i++, j++)
			{
				if (v1[i] == v2[j])
					continue;
				if (v1[i] < v2[j])
					return -1;
				else
					return 1;
			}
			return 0;
		}
	}

    int compareVersion(string version1, string version2) {
        std::vector<int> v1 = splitDoc(version1);
        std::vector<int> v2 = splitDoc(version2);
        if (v1.empty() && v2.empty())
        	return compareString(version1, version2);
        if (v1.empty())
        {
        	string temp1 = version2.substr(0, v2.front() + 1);
        	return compareString(version1, temp1);
        }
        else if (v2.empty())
        {
        	string temp2 = version1.substr(0, v1.front() + 1);
        	return compareString(temp2, version2);
        }
        else  //both have '.'
        {
        	string t_ver1 = version1.substr(0, v1[0] + 1);
        	string t_ver2 = version2.substr(0, v2[0] + 1);
        	int res = compareString(t_ver1, t_ver2);
        	if (res != 0)
        		return res;

        	int v1_size = v1.size() - 1;
        	int v2_size = v2.size() - 1;
        	int min = v1_size < v2_size ? v1_size : v2_size;
        	for (int i = 1; i <= min - 1; i ++)
        	{
        		string t1 = version1.substr(v1[i-1] + 1, v1[i] - v1[i-1] - 1);
        		string t2 = version2.substr(v2[i-1] + 1, v2[i] - v2[i-1] - 1);
        		res = compareString(t1, t2);
        		if (res != 0)
        			return res;
        	}
        	if (v1_size < v2_size) //version2 is longer
        	{
        		string t1 = version1.substr(v1[min] + 1, version1.length() - v1[min] - 1);
        		string t2 = version2.substr(v2[min] + 1, v2[min+1] - v2[min] - 1);
        		res = compareString(t1, t2);
        		if (res != 0)
        			return res;
        		//...
        	}
        	else if (v1_size > v2_size) //version1 is longer
        	{
        		string t1 = version1.substr(v1[min] + 1, v1[min+1] - v1[min] - 1);
        		string t2 = version2.substr(v2[min] + 1, version2.length() - v2[min] - 1);
        		res = compareString(t1, t2);
        		if (res != 0)
        			return res;
        		//...
        	}
        	else
        	{
        		string t1 = version1.substr(v1[min] + 1, version1.length() - v1[min] - 1);
        		string t2 = version2.substr(v2[min] + 1, version2.length() - v2[min] - 1);
        		res = compareString(t1, t2);
        		return res;
        	}
        }
    }
};