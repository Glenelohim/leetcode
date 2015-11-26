class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        map<int, int> mymap;
        for (int i = 0; i < nums.size(); i++)
        {
        	auto it =  mymap.find(target - nums[i]);
        	if (it != mymap.end())
        	{
        		res.push_back(it->second);
        		res.push_back(i + 1);
        		break;
        	}
        	mymap[nums[i]] = i + 1;
        }
        return res;
    }
};