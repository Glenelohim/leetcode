class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int len = nums.size();
        if (len <= 1)
        	return false;
        unordered_map<int, int> nums_map;
        nums_map[nums[0]] = 0;
        for (int i = 1; i < len; i++)
        {
        	if (nums_map.find(nums[i]) != nums_map.end() && i - nums_map[nums[i]] <= k)
        		return true;
        	nums_map[nums[i]] = i;
        }
        return false;
    }
};