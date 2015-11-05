#include <iostream>
using namespace std;

class mySolution
{
public:
	mySolution(){};
	~mySolution(){};
	
	int binarySearch(int A[], int n, int target)
	{
		if (n <= 0) return -1;

		int first = 0, last = n;
		while (first != last)
		{
			int mid = (first + last) / 2;
			if (A[mid] == target)
				return mid;
			if (A[first] <= A[mid])
			{
				if (A[first] <= target && target < A[mid])
					last = mid;
				else
					first = mid + 1;
			}
			else
			{
				if (A[mid] < target && target <= A[last - 1])
					first = mid + 1;
				else
					last = mid;
			}
		}
		return -1;
	}


};

int main(int argc, char const *argv[])
{
	/* code */
	int A[] = {4, 5, 6, 1, 2, 3};
	mySolution test;
	cout << test.binarySearch(A, 6, 3) << endl;
	return 0;
}