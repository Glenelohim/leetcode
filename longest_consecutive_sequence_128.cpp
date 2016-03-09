class Solution {
public:
	int longestConsecutive(vector<int>& nums)
	{
		int nums_size = nums.size();
		if (!nums_size)
			return 0;
		if (1 == nums_size)
			return 1;
		int res = 1;
		unordered_set<int> u_set;
		for (int i : nums)
			u_set.insert(i);
		while (!u_set.empty())
		{
			int cur = *u_set.begin();
			int pos_cur = cur + 1, neg_cur = cur - 1;
			int count = 1;
			u_set.erase(cur);
			for (; u_set.find(pos_cur) != u_set.end(); pos_cur++)
			{
				count++;
				u_set.erase(pos_cur);
			}
			for (; u_set.find(neg_cur) != u_set.end(); neg_cur--)
			{
				count++;
				u_set.erase(neg_cur);
			}
			res = max(res, count);
		}
		return res;
	}

	//tle...--
    int longestConsecutive(vector<int>& nums) {
        int nums_size = nums.size();
        if (!nums_size)
        	return 0;
        if (1 == nums_size)
        	return 1;
        int res = 1;
        unordered_map<int, bool> u_map;
        for (int i : nums)
        	u_map[i] = false;

        for (int i : nums)
        {
        	if (!u_map[i])
        	{
        		int cur_lenth = 1;
        		u_map[i] = true;
        		for (int j = i+1; u_map.find(j) != u_map.end(); j++)
        			cur_lenth++;
        		for (int j = i-1; u_map.find(j) != u_map.end(); j--)
        			cur_lenth++;
        		res = max(res, cur_lenth);
        	}
        }
        return res;
    }
};