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
	static bool compare(Interval& t1, Interval& t2)
	{
		return t1.start < t2.start;
	}
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        int intervals_size = intervals.size();
        if (!intervals_size)
        	return res;
        std::sort(intervals.begin(), intervals.end(), compare);
        int i = 0;
        while (i < intervals_size)
        {
        	int j = i+1;
        	while (j < intervals_size && intervals[j].start <= intervals[i].end)
        	{
        		intervals[i].end = std::max(intervals[i].end, intervals[j].end);
        		j++;
        	}
        	res.push_back(intervals[i]);
        	i = j;
        }
        return res;
    }
};

//fuck my tle solution,,,-_-
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if (!intervals.size())
        	return res;
        vector<Interval> intervals_mir = intervals;
        vector<Interval>::iterator base = intervals_mir.begin();
        vector<Interval>::iterator next;
        int gap = 0, gap1 = 1;
        while (base != intervals_mir.end())
        {
        	next = base+1;
        	while (next != intervals_mir.end())
        	{
        		if ((*next).start > (*base).end || (*next).end < (*base).start)
        		{
        			gap1++;
        			next = intervals_mir.begin()+gap1;
        			continue;
        		}
        		if ((*next).start < (*base).start)
        			(*base).start = (*next).start;
        		if ((*next).end > (*base).end)
        			(*base).end = (*next).end;
        		vector<Interval>::iterator temp = next+1;
        		intervals_mir.erase(next);
        		next = temp;
        	}
        	res.push_back(*base);
        	gap++;
        	gap1 = gap+1;
        	base = intervals_mir.begin()+gap;
        }
        return res;
    }
};