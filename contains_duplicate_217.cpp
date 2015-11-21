class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1)
        	return false;
        set<int> nums_set;
        nums_set.insert(nums[0]);
        for (int i = 1; i < len; i ++)
        {
        	set<int>::iterator temp;
        	temp = nums_set.find(nums[i]);
        	if (temp != nums_set.end())
        		return true;
        	nums_set.insert(nums[i]);
        }
        return false;
    }
};

class Solution {
public:
    //an awesome solution from the discuss
    bool containsDuplicate(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        return s.size() != nums.size();
    }
};