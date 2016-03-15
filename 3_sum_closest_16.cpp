class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        if (size < 3)
        {
        	return 0;
        }
        sort(nums.begin(), nums.end(), less<int>());
        int res = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < size - 2; i++)
        {
        	int j = i + 1, k = size - 1;
        	while (j < k)
        	{
        		int temp = nums[i] + nums[j] + nums[k];
        		if (abs(target - res) > abs(target - temp))
        		{
        			res = temp;
        		}
        		if (temp > target)
        		{
        			k--;
        		}
        		else
        		{
        			j++;
        		}
        	}
        }
        return res;
    }
};