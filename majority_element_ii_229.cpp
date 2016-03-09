class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int nums_size = nums.size();
        vector<int> res;
        if (!nums_size)
        	return res;
        if (nums_size == 1)
        	return nums;
        unordered_map<int, int> u_map;
        int count = 0;
        for (int i : nums)
        {
        	unordered_map<int, int>::iterator p = u_map.find(i);
        	if (p != u_map.end())
        	{
        		u_map[i]++;
        	}
        	else
        	{
        		u_map[i] = 1;
        	}
        	if (u_map[i] > (nums_size / 3))
        	{
        		if (res.empty())
        		{
        			res.push_back(i);
        			count++;
        		}
        		else if (count == 1 && i != res[0])
        		{
        			res.push_back(i);
        			count++;
        		}
        		if (count == 2)
        			return res;
        	}
        }
        return res;
    }
};