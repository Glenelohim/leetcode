class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() <= 2)
        	return nums[0];
        std::map<int, int> _map;
        _map[nums[0]] = 1;
        for (int i = 1; i < nums.size(); i++)
        {
        	std::map<int, int>::iterator it = _map.find(nums[i]);
        	if (it != _map.end())
        		_map[nums[i]] ++;
        	else
        		_map[nums[i]] = 1;

        	if (_map[nums[i]] > nums.size()/2)
        		return nums[i];
        }
        return 0;
    }
};

class Solution {
public:
//wtf...awesome solution from the discuss
    int majorityElement(vector<int>& nums) {
        int winner = 0, count = 0;
        for (int n : nums) {
            count || (winner = n);
            n == winner ? ++count : --count;
        }
        return winner;
    }
};