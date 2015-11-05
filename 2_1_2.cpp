#include <iostream>
using namespace std;

class Fun1
{
public:
	int removeDuplicates2(int A[], int n)
	{
		if (n == 0) return 0;
		int index = 0, count = 0;
		for (int i = 0; i != n; i++)
		{
			if (A[index] == A[i])
				count++;
			else
				switch (count)
				{
					case 0:
						A[++index] = A[i];
						break;
					case 1:
						index = i;
						break;
					default:
						A[index+1] = A[index];
						A[index+2] = A[i];
						index += 2;
						count = 0;
						break;
				}
		}
		return index + 1;
	}

	int awesomeSolution(int A[], int n)
	{
		if (n <= 2) return n;
		int index = 2;
		for (int i = 2; i != n; i++)
		{
			if (A[index-2] != A[i])
				A[index++] = A[i];
		}
		return index;
	}
};

int main()
{
	int A[] = {1, 1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4};
	Fun1 test;
	cout << test.awesomeSolution(A, 12) << endl;
	for (int i = 0; i != 12; i++)
		cout << A[i] << " ";
	cout << endl;
	return 0;
}