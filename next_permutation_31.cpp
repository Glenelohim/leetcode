class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int nums_size = nums.size();
        if (nums_size <= 1)
        	return;
        int i = nums_size-1, j = i-1;
        while (j >= 0)
        {
        	if (nums[j] < nums[i])
        		break;
        	j--;
        	i--;
        }
        if (j < 0)
        {
        	std::sort(nums.begin(), nums.end(), less<int>());
        	return;
        }
        int index = nums_size-1;
        for (; index >= i; index--)
        {
        	if (nums[index] > nums[j])
        		break;
        }
        int temp = nums[j];
        nums[j] = nums[index];
        nums[index] = temp;
        std::sort(nums.begin()+i, nums.end(), less<int>());
    }
};