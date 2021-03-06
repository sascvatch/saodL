#include "stdafx.h"
#include "saodLab1.cpp"
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void CocktailSort(int a[], int n)
{
	bool swapped = true;
	int start = 0;
	int end = n - 1;

	while (swapped)
	{
		swapped = false;

		for (int i = start; i < end; ++i)
		{
			c++;
			if (a[i] > a[i + 1])
			{
				m += 3;
				swap(a[i], a[i + 1]);
				swapped = true;
			}
		}

		if (!swapped)
			break;
		swapped = false;
		--end;

		for (int i = end - 1; i >= start; --i)
		{
			c++;
			if (a[i] > a[i + 1])
			{
				m += 3;
				swap(a[i], a[i + 1]);
				swapped = true;
			}
		}

		++start;
	}
}

void pritnTabl() {
	cout << "i   " << "             Bubble          " << "                    Shaker          " << endl;
	cout << "        desc      rand        asc " << "          desc      rand        asc " << endl;
}
int main()
{
	int *a;
	pritnTabl();
	for (int n = 100; n <= 500; n += 100)
	{

		cout << n << " ";
		a = new int[n];

		FillDec(a, n);
		BubbleSort(a, n); sum = m + c;
		cout.width(10); cout << sum; m = 0, c = 0, sum = 0;

		FillRand(a, n);
		BubbleSort(a, n); sum = m + c;
		cout.width(10); cout << sum; m = 0, c = 0;

		FillInc(a, n);
		BubbleSort(a, n); sum = m + c;
		cout.width(10); cout << sum << "     "; m = 0, c = 0;

		FillDec(a, n);
		CocktailSort(a, n); sum = m + c;
		cout.width(10); cout << sum; m = 0, c = 0;

		FillRand(a, n);
		CocktailSort(a, n); sum = m + c;
		cout.width(10); cout << sum; m = 0, c = 0;

		FillInc(a, n);
		CocktailSort(a, n); sum = m + c;
		cout.width(10); cout << sum; m = 0, c = 0;
		/*shakerSort(a, n);

		m = 0, c = 0;
		FillRand(a, n);*/
		cout << endl;
	}



	_getch();
	return 0;
}

