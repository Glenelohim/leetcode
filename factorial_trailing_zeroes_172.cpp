//such an awesome solution from the wiki
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while (n >= 5)
        {
        	n /= 5;
        	res += n;
        }
        return res;
    }
};

n!结果末尾的连续0的个数 = n!中(2*5)因子对的个数
而2的因子个数必然是比5的因子个数多，
所以只需求n!结果中5因子的个数。

5因子个数 == n/5 + n/(5^2) + n/(5^3) + ... + n/(5^k)
==> n/5表示n!中第一重5因子的个数总和（因为有的i含有多个5因子，比如25就有2个5因子
==> n/25表示第二重5因子的个数总和
...同理
再对它们求和，即可得出所有5因子个数的总和
