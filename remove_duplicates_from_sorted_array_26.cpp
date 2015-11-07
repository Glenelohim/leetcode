class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (!nums.size())
        	return 0;
        if (nums.size() == 1)
        	return 1;
        int res = 1;
        int mirror = nums[0];
        int i = 1;
        int j = 1;

        for (; i < nums.size(); i++)
        {
        	if (nums[i] != mirror)
        	{
        		mirror = nums[i];
        		nums[j++] = mirror;
        		res ++;
        	}
        }
        return res;
    }
};