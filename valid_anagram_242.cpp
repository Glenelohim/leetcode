class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_len = s.length();
        int t_len = t.length();
        if (s_len != t_len)
        	return false;
        if (!s_len)
        	return true;

        map<char, int> chMap;
        for (int i = 0; i < s_len; i++)
        {
        	if (chMap.find(s[i]) == chMap.end())
        		chMap[s[i]] = 1;
        	else
        		chMap[s[i]]++;
        }

        for (int i = 0; i < t_len; i++)
        {
        	if (chMap.find(t[i]) == chMap.end())
        		return false;
        	else
        	{
        		if (chMap[t[i]] == 0)
        			return false;
        		else
        			chMap[t[i]]--;
        	}
        }

        return true;
    }
};

//another easy solution using C
bool isAnagram(char* s, char* t) {
    if(s==NULL && t==NULL) return true;
    if(strlen(s) != strlen(t)) return false;

    int a[26]={0};
    for(int i=0;i<strlen(s);i++){
        a[s[i]-'a']++;
        a[t[i]-'a']--;
    }

    for(int i=0;i<26;i++){
        if(a[i]<0) return false;
    }
    return true;
}