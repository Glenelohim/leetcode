/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
	static bool cmp(Interval& t1, Interval& t2)
	{
		return t1.start < t2.start;
	}

    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        int intervals_size = intervals.size();
        if (!intervals_size)
        {
        	res.push_back(newInterval);
        	return res;
        }
        sort(intervals.begin(), intervals.end(), cmp);
        
        int i = 0;
        while (i < intervals_size)
        {
        	Interval temp = intervals[i];
        	if (temp.end < newInterval.start)
        	{
        		res.push_back(temp);
        		i++;
        	}
        	else
        	{
        		break;
        	}
        }
        if (i >= intervals_size)
        {
        	res.push_back(newInterval);
        }
        else
        {
        	newInterval.start = min(newInterval.start, intervals[i].start);
        	while (i < intervals_size)
        	{
        		Interval temp = intervals[i];
        		if (newInterval.end < temp.start)
        		{
        			newInterval.end = max(newInterval.end, intervals[i-1].end);
        			res.push_back(newInterval);
        			break;
        		}
        		i++;
        	}
        	if (i == intervals_size)
        	{
        		newInterval.end = max(newInterval.end, intervals[intervals_size-1].end);
        		res.push_back(newInterval);
        	}
        	else
        	{
        		while (i < intervals_size)
        		{
        			res.push_back(intervals[i]);
        			i++;
        		}
        	}
        }
        return res;
    }
};