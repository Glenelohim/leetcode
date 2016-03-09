class Solution {
public:
	//awesome...O(nlogn)time+O(1)space
    int findDuplicate(vector<int>& nums) {
        int nums_size = nums.size();
        if (!nums_size)
        	return 0;
        int low = 1, high = nums_size-1;
        while (low < high)
        {
        	int mid = (low + high) / 2;
        	int count = 0;
        	for (int i = 0; i < nums_size; i++)
        	{
        		if (nums[i] <= mid)
        		{
        			count++;
        		}
        	}
        	if (count > mid)
        	{
        		high = mid;
        	}
        	else
        	{
        		low = mid + 1;
        	}
        }
        return low;

    }
};