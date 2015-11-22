class Solution {
public:
	string int2string(int i)
	{
		string res;
		char temp[11];
		sprintf(temp, "%d", i);
		res = temp;
		return res;
	}
	//consider the nums[i] may be negative
    vector<string> summaryRanges(vector<int>& nums) {
        int nums_len = nums.size();
        vector<string> res;
        if (nums_len == 0)
        	return res;

        int count = 1;
        string temp = "";
        temp += int2string(nums[0]);
        for (int i = 1; i < nums_len; i++)
        {
        	if (nums[i] - nums[i - 1] == 1)
        		count ++;
        	else
        	{
        		if (count > 1)
        		{
        			temp += "->";
        			temp += int2string(nums[i - 1]);
        		}
        		res.push_back(temp);
        		temp = "";
        		temp += int2string(nums[i]);
        		count = 1;
        	}
        }
        if (count > 1)
        {
            temp += "->";
            temp += int2string(nums[nums_len - 1]);
        }
        res.push_back(temp);
        return res;
    }


    //another concise solution
    //however, the runtime is the same
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        for (int i=0; i<nums.size(); i++) {
            int pre = nums[i];
            while (i+1<nums.size() && nums[i+1]==nums[i]+1)  
                i++;
            if (pre == nums[i])
                ret.push_back(to_string(pre));
            else
                ret.push_back(to_string(pre)+"->"+to_string(nums[i]));
        }
        return ret;
    }
};

