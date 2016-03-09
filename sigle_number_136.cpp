class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int nums_size = nums.size();
        if (!nums_size)
        	return 0;
        int res = nums[0];
        for (int i = 1; i < nums_size; i++)
        {
        	res ^= nums[i];
        }
        return res;
    }
};