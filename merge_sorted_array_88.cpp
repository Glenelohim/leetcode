class Solution {  //has something wrong---:( see another solution
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (!n)
        	return;
        if (!m)
        {
        	nums1 = nums2;
        	return;
        }

        vector<int>::iterator it1 = nums1.begin();
        vector<int>::iterator it2 = nums2.begin();
        while (it1 != nums1.end())
        {
        	if (it2 == nums2.end())
        		break;
        	if (*it2 < *it1)
        	{
        		nums1.insert(it1, *it2);
        		it1 ++;
        		it2 ++;
        	}
        	else
        		it1 ++;
        }
        if (it1 == nums1.end())
        {
        	while (it2 != nums2.end())
        	{
        		nums1.push_back(*it2);
        		it2 ++;
        	}
        }
    }
};

//an awesome solution 
class Solution
{
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
	{
		if (!n)
        	return;
        if (!m)
        {
        	nums1 = nums2;
        	return;
        }
		int k = m + n - 1;
  		for(; k >= 0; k --)
	    {
	        if ((nums1[m - 1] > nums2[n - 1] && m > 0) || n <= 0)
	        {
	            nums1[m + n - 1] = nums1[m - 1];
	            m --;
	        }
	        else
	        {
	            nums1[m + n - 1] = nums2[n - 1];
	            n --;
	        }
	    }
	}
};