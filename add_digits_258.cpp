class Solution {
public:
    int addDigits(int num) {
        if (!(num / 10)) return num;

        int res = 0;
        while (num / 10)
        {
        	res += num % 10;
        	num /= 10;
        }
        res += num;
        return addDigits(res);
    }
};

//awesome solution from the disscuss
//https://en.wikipedia.org/wiki/Digital_root
class Solution {
public:
    int addDigits(int num) {
        return (num-1)%9+1;
    }
};