#include <iostream>

// Result: the number of elements smaller than a[i]
int countLessThan (int a[], int length, int i)
{
	int j, count = 0;

	for (j=0; j<length; j++)
	{
		if (a[j] < a[i] || (a[j] == a[i] && i < j))
		{
			count++;
		}
	}
	return count;
}


// Action: sort table a[]
void sortByCounting (int a[], int length)
{
	int i, lessThan;
	int *b = new int[length];

	for (i=0; i<length; i++)
	{
		lessThan = countLessThan (a, length, i);
		b[lessThan] = a[i];
	}

	for (i=0; i<length; i++)
	{
		a[i] = b[i];
	}

	delete [] b;
}


int main (void)
{
	int i, length;
	int *a;

	std::cout << "Insert the array size" << std::endl;
	std::cin >> length;

	a = new int[length];

	std::cout << "Insert the array elements, one per line" << std::endl;
	for (i = 0; i < length; i++)
	{
		std::cin >> a[i];
	}

	sortByCounting (a, length);

	std::cout << "The sorted array is:" << std::endl;
	for (i = 0; i < length; i++)
	{
		std::cout << a[i] << std::endl;
	}

	return 0;
}


