class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int nums_size = nums.size();
        if (!nums_size)
        	return -1;
        long long sum = (nums_size+1) * nums_size / 2;
        for (int i = 0; i < nums_size; i++)
        	sum -= nums[i];
        return sum;
    }
};