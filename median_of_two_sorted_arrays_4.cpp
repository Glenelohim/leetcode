class Solution {
public:
	int findKthMin(vector<int> nums1, vector<int> nums2, int k)
	{
		int len1 = nums1.size();
        int len2 = nums2.size();
        if (!len1 && !len2)	return 0;
        if (len1 < len2) return findKthMin(nums2, nums1, k);
        if (!len2) return nums1[k - 1];
        if (k == 1) return min(nums1[0], nums2[0]);

        int nums2_index = min(k/2, len2);
        int nums1_index = k - nums2_index;
        if (nums1[nums1_index - 1] == nums2[nums2_index - 1])
        	return nums1[nums1_index - 1];
        else if(nums1[nums1_index - 1] > nums2[nums2_index - 1])
        {
        	nums2.erase(nums2.begin(), nums2.begin() + nums2_index);
        	return findKthMin(nums1, nums2, k - nums2_index);
        }
        else
        {
        	nums1.erase(nums1.begin(), nums1.begin() + nums1_index);
        	return findKthMin(nums1, nums2, k - nums1_index);
        }

	}
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        if (!len1 && !len2)	return 0;
        if (len1 < len2) return findMedianSortedArrays(nums2, nums1);
        if (!len2) return len1%2 ? nums1[len1/2] : (double)(nums1[len1/2]+nums1[len1/2-1]) / 2;

        int total_len = len1 + len2;
        //odd
        if (total_len % 2)
        	return findKthMin(nums1, nums2, total_len/2+1);
        else //even
        	return (double)(findKthMin(nums1, nums2, total_len/2) + findKthMin(nums1, nums2, total_len/2 + 1)) / 2;

    }
};


//something wrong...
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(), size2 = nums2.size();
        if (!size1 && !size2)
        {
        	return 0;
        }
        int i = 0, j = 0, mid1 = (size1 + size2) / 2, mid2 = 0, count = 0;
        if ((size1 + size2) % 2)
        {
        	mid2 = mid1 - 1;
        }
        int r1 = 0, r2 = 0;
        while (i < size1 && j < size2)
        {
        	if (nums1[i] < nums2[j])
        	{
        		count++;
        		if (0 == mid2) //odd
        		{
        			if (count == mid1 + 1)
        			{
        				r1 = nums1[i];
        				return r1;
        			}
        		}
        		else  //even
        		{
        			if (count == mid2 + 1)
        			{
        				r2 = nums1[i];
        			}
        			else if (count == mid1 + 1)
        			{
        				r1 = nums1[i];
        				return ((double)(r1 + r2)) / 2;
        			}
        		}
        		i++;
        	}
        	else
        	{
        		count++;
        		if (0 == mid2)
        		{
        			if (count == mid1 + 1)
        			{
        				r1 = nums2[j];
        				return r1;
        			}
        		}
        		else
        		{
        			if (count == mid2 + 1)
        			{
        				r2 = nums2[j];
        			}
        			else if (count == mid1 + 1)
        			{
        				r1 = nums2[j];
        				return ((double)(r1 + r2)) / 2;
        			}
        		}
        		j++;
        	}
        }
        if (i == size1)
        {
        	while (j < size2)
        	{
        		count++;
        		if (0 == mid2)
        		{
        			if (count == mid1 + 1)
        			{
        				r1 = nums2[j];
        				break;
        			}
        		}
        		else
        		{
        			if (count == mid2 + 1)
        			{
        				r2 = nums2[j];
        			}
        			else if (count == mid1 + 1)
        			{
        				r1 = nums2[j];
        				break;
        			}
        		}
        		j++;
        	}
        	return ((double)(r1 + r2)) / 2;
        }
        else if (j == size2)
        {
        	while (i < size1)
        	{
        		count++;
        		if (0 == mid2) //odd
        		{
        			if (count == mid1 + 1)
        			{
        				r1 = nums1[i];
        				break;
        			}
        		}
        		else  //even
        		{
        			if (count == mid2 + 1)
        			{
        				r2 = nums1[i];
        			}
        			else if (count == mid1 + 1)
        			{
        				r1 = nums1[i];
        				break;
        			}
        		}
        		i++;
        	}
        	return ((double)(r1 + r2)) / 2;
        }
    }
};
