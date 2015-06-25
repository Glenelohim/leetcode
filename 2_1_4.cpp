#include <iostream>
using namespace std;

class Fun
{
public:
	bool mySolution(int A[], int n, int target)
	{
		if (n <= 0)  return false;

		int first = 0, last = n;
		while (first != last)
		{
			int mid = (first + last) / 2;
			if (A[mid] == target)
				return true;

			if (A[first] < A[mid])
			{
				if (A[first] <= target && target < A[mid])
					last = mid;
				else
					first = mid + 1;
			}
			else if(A[first] > A[mid])
			{
				if (A[mid] < target && target <= A[last - 1])
					first = mid + 1;
				else
					last = mid;
			}
			else
			{
				first++;
			}
		}
		return false;
	}
	
};

int main(int argc, char const *argv[])
{
	/* code */
	int A[] = {1, 3, 1, 1, 1};
	Fun test;
	cout << test.mySolution(A, 5, 0) << endl;
	return 0;
}