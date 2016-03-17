class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        if (!size)
        {
        	return 0;
        }
        sort(citations.begin(), citations.end(), less<int>());
        int count = 0, mark = 0;
        for (int i = size - 1; i >= 0; i--)
        {
        	count++;
        	if (citations[i] >= count)
        	{
        		mark = count;
        	}
        }
        return mark;
    }
};