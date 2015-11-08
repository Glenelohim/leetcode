class Solution
{
public:
	int removeElement(vector<int>& nums, int val)
	{
		if (!nums.size())
			return 0;
		for (vector<int>::iterator i = nums.begin(); i != nums.end();)
		{
			if (*i == val)
				i = nums.erase(i);
			else
				i ++;
		}
		return nums.size();
	}
};