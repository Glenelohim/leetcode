class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int len = nums.size();
        if (len <= 1)
        	return false;
        multimap<long, int> nums_multimap;  //using long because doing the minus maybe overflow
        for (int i = 0; i < len; i++)
        	nums_multimap.insert(make_pair(nums[i], i));

        multimap<long, int>::iterator p = nums_multimap.begin();
        while (p != nums_multimap.end())
        {
            multimap<long, int>::iterator temp = p;
            temp++;
        	while (temp != nums_multimap.end() && temp->first - p->first <= t)
        	{
        		if (std::abs(temp->second - p->second) <= k)
        			return true;
        		temp++;
        	}
        	p++;
        }
        return false;
    }
};