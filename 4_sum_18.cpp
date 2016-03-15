class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
        int size = nums.size();
        if (size < 4)
        {
        	return res;
        }
        sort(nums.begin(), nums.end(), less<int>());

        //it is very strange. when these variables are
        //set in the loop, it will be TLE.
        int target_3sum = 0, target_2sum = 0;
        int i = 0, j = 0, m = 0, n = 0;

        for (i = 0; i < size - 3; i++)
        {
        	if (i != 0 && nums[i] == nums[i - 1])
        		continue;

        	target_3sum = target - nums[i];
        	for (j = i + 1; j < size - 2; j++)
        	{
        		if (j != (i + 1) && nums[j] == nums[j - 1])
        			continue;

        		target_2sum = target_3sum - nums[j];
        		m = j + 1;
        		n = size - 1;

        		while (m < n)
        		{
        			int temp = nums[m] + nums[n];
        			if (temp == target_2sum)
        			{
        				vector<int> tt;
        				tt.push_back(nums[i]);
        				tt.push_back(nums[j]);
        				tt.push_back(nums[m]);
        				tt.push_back(nums[n]);
        				res.push_back(tt);
        				while (m < n && nums[m + 1] == nums[m])
        					m++;
        				while (m < n && nums[n] == nums[n - 1])
        					n--;
        				m++;
        				n--;
        			}
        			else if (temp > target_2sum)
        			{
        				n--;
        			}
        			else
        			{
        				m++;
        			}
        		}
        	}
        }
        return res;
    }
};