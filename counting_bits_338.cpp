class Solution {
public:
	//awesome solution from the discuss
    vector<int> countBits(int num) {
        vector<int> res(num + 1);
        res[0] = 0;
        for (int i = 1; i <= num; i++)
        {
        	res[i] = res[i & (i - 1)] + 1;
        }
        return res;
    }
};


//this stupid solution is MLE..
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        if (num <= 1)
        {
        	if (num >= 0)
        	{
        		res.push_back(0);
        	}
        	if (num >= 1)
        	{
        		res.push_back(1);
        	}
        	return res;
        }
       	res.push_back(0);
       	res.push_back(1);
        int sq = sqrt(num);
        int part = num - pow(2, sq);
        while (sq > 1)
        {
        	int size = res.size();
        	for (int i = 0; i < size; i++)
        	{
        		res.push_back(res[i] + 1);
        	}
        	sq--;
        }
        for (int i = 0; i <= part; i++)
        {
        	res.push_back(res[i] + 1);
        }
        return res;
    }
};