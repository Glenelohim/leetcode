class Solution {
public:
	// I'm right, and the OJ is stupid in this title!
	static bool cmp(string s1, string s2)
	{
		return s1[0] < s2[0];
	}

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        int size = strs.size();
        if (!size)
        {
        	return res;
        }
        unordered_map<string, vector<string>> u_map;
        string temp;
        for (int i = 0; i < size; i++)
        {
        	temp = strs[i];
        	sort(temp.begin(), temp.end(), less<char>());
        	if (u_map.find(temp) != u_map.end())
        	{
        		u_map[temp].push_back(strs[i]);
        	}
        	else
        	{
        		vector<string> r;
        		r.push_back(strs[i]);
        		u_map[temp] = r;
        	}
        }
        for (auto i = u_map.begin(); i != u_map.end(); i++)
        {
        	sort((i->second).begin(), (i->second).end(), cmp);
        	res.push_back(i->second);
        }
        return res;
    }
};


	//?????? could not ac ??????? SB test!!!
case: ["poe","why","man","rio","tom","mob","jar","hon","den","red","beg","her","saw","shy","bee","ram","ina","bun","brr","gen","fry","aye","che","pop","cod","ivy","ham","pyx","zed","tor","why","pun","pup","mid","lad","nov","nag","ike","jam","rat","sky","lob","pis","win","and","toe","man","flu","van","lid","guy","ltd","spa","wyo","law","ian"]
myoutput : 		[["law"],["wyo"],["lid"],["aye"],["brr"],["bun"],["pop"],["guy"],["fry"],["ina","ian"],["ram"],["den"],["jar"],["hon"],["pis"],["rat"],["lob"],["gen"],["ltd"],["mid"],["saw"],["her"],["beg"],["tom"],["jam"],["mob"],["man","man"],["van"],["bee"],["why","why"],["rio"],["spa"],["pyx"],["red"],["che"],["pun"],["nag"],["and"],["ivy"],["cod"],["zed"],["tor"],["pup"],["lad"],["nov"],["poe"],["ike"],["win"],["shy"],["sky"],["flu"],["ham"],["toe"]]
expectedoutput: [["law"],["wyo"],["lid"],["aye"],["brr"],["bun"],["pop"],["guy"],["fry"],["ian","ina"],["ram"],["den"],["jar"],["hon"],["pis"],["rat"],["lob"],["gen"],["ltd"],["mid"],["saw"],["her"],["beg"],["tom"],["jam"],["mob"],["man","man"],["van"],["bee"],["why","why"],["rio"],["spa"],["pyx"],["red"],["che"],["pun"],["nag"],["and"],["ivy"],["cod"],["zed"],["tor"],["pup"],["lad"],["nov"],["poe"],["ike"],["flu"],["shy"],["sky"],["win"],["ham"],["toe"]]