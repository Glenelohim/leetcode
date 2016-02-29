class Solution {
public:
    void sortColors(vector<int>& nums) {
        int nums_size = nums.size();
        if (!nums_size)
        	return;
        int num0 = 0, num1 = 0, num2 = 0;
        for (int i = 0; i < nums_size; i++)
        {
        	if (nums[i] == 0)
        		num0++;
        	else if (nums[i] == 1)
        		num1++;
        	else
        		num2++;
        }
        for (int i = 0; i < nums_size; i++)
        {
        	if (i < num0)
        		nums[i] = 0;
        	else if (i < (num0 + num1))
        		nums[i] = 1;
        	else
        		nums[i] = 2;
        }
    }
};