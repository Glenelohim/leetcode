//febonachi solution but cause tle
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
        	return 1;
        if (n == 2)
        	return 2;
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

//my solution_2
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2)
        	return n;
        int pre = 1;
        int aft = 2;
        int res = 0;
        for (int i = 3; i <= n; i ++)
        {
        	res = pre + aft;
        	pre = aft;
        	aft = res;
        }
        return res;
    }
};

//using dp
class Solution {
public:
    int climbStairs(int n) {
        int k;
        auto iter = map.find(n);
        if(iter != map.end())
        {
            k = iter->second;
        }
        else
        {
            if(n <= 0)
                k = 0;
            else
                k = n < 3? n : climbStairs(n - 1) + climbStairs(n - 2);
            map.insert(make_pair(n, k));
        }
        return k;
    }
private:
    std::map<int, int> map;
};