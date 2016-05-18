class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int len1 = nums1.size();
        int len2 = nums2.size();

        if ((0==len1) || (0==len2))
        {
        	return res;
        }

        std::set<int> num1, num2;
        for (int i=0; i<len1; i++)
        	num1.insert(nums1[i]);

        for (int i=0; i<len2; i++)
        	num2.insert(nums2[i]);

        std::set<int>::iterator it = num1.begin();

        for (; it!=num1.end(); it++)
        {
        	if (num2.find(*it) != num2.end())
        	{
        		res.push_back(*it);
        	}
        }

        return res;
    }
};