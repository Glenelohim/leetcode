#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

class Fun1
{
public:
	Fun1()
	{
		cout << "default constructor" << endl;
	}
	
	int removeDuplicates(int A[], int n)
	{
		if (n == 0)  return 0;
		int index = 0;
		for (int i = 1; i != n; i++)
		{
			if (A[index] != A[i])
				A[++index] = A[i];
		}
		return index + 1;
	}
	
	~Fun1()
	{
		cout << "default destructor" << endl;
	}

};

class Fun2
{
public:
	Fun2()
	{
		cout << "fun2 default constructor" << endl;
	}

	int removeDuplicates(int A[], int n)
	{
		return distance(A, unique(A, A+n));
	}

	~Fun2()
	{
		cout << "fun2 default destructor" << endl;
	}
};

int main()
{
	int A[] = {1, 1, 1, 2, 2, 3, 3};
	Fun1 test;
	Fun2 test2;
	cout << test2.removeDuplicates(A, 7) << endl;
	for (int i = 0; i != 7; i++)
		cout << A[i] << " ";
	cout << endl;
	return 0;
}