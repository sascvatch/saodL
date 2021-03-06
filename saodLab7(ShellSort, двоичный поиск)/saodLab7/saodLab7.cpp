// saodLab7.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <time.h>
#include <iostream>//  for cout
#include<conio.h>// for _getch()
#include<stdlib.h>// for srand
#include<conio.h>//for _getch()
#include<clocale>

using namespace std;// for cout

int random(int N) { return rand() % N; }
int l = 0, z = 90, nOfxes = 0;
void FillInc(int *a, int n) {

	a[0] = random(z - l + 1) + l;
	for (int i = 1; i < n; i++)
	{
		a[i] = a[i - 1] + random(z - l + 1) + l;
	}
}
void BSearch1(int *a, int r, int x, int&c1) {
	int m, l = 0;
	while (l <= r) {

		m = (l + r) / 2;
		c1++;
		if (a[m] == x) {
			//cout << "found"; 
			break;
		}
		c1++;
		if (a[m] < x) l = m + 1;
		else r = m - 1;
	}//if(a[m]!=x)cout << "not found";
}

void BSearch2(int *a, int r, int x, int&c2) {
	int l = 0, m = 0;
	while (l < r) {
		m = (l + r) / 2;
		c2++;
		if (a[m] < x) l = m + 1;
		else r = m;
	}
	c2++;
	/*if (a[r] == x) cout << "found";
	else cout << "not found";*/
}
void BSearchAll1(int*a, int r, int x, int&c1, int & nOfxes) {
	int m, l = 0, mTmp;
	//c1++;
	while (l <= r) {

		m = (l + r) / 2;
		c1++;
		if (a[m] == x) {
			mTmp = m;
			//cout << "found"; 
			c1++;
			while (a[mTmp++] == x) {
				c1++;
				nOfxes++;
			}mTmp = m - 1;
			c1++;
			while (a[mTmp--] == x) {
				c1++;
				nOfxes++;
			}
			break;
		}
		c1++;
		if (a[m] < x) l = m + 1;
		else r = m - 1;
	}//if(a[m]!=x)cout << "not found";
}
void BSearchAll2(int*a, int r, int x, int&c2, int & nOfxes) {
	//int m, l = 0, mTmp;
	int l = 0, m = 0, mTmp; 
	c2++;
	while (l < r) {
		m = (l + r) / 2;
		c2++;
		if (a[m] < x) l = m + 1;
		else r = m;
	}
	c2++;
	if (a[r] == x) {
		mTmp = r;
		//cout << "found"; 
		c2++;
		while (a[mTmp++] == x) {
			c2++;
			nOfxes++;
		}mTmp = r - 1;
		
	}
}


void PrintMas(int*a, int n) {
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}
void FillRand(int* A, int n) {
	int i;
	for (i = 0; i < n; i++) A[i] = random(z - l + 1) + l;
}
int shellSort(int arr[], int n)
{
	// Start with a big gap, then reduce the gap
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		// Do a gapped insertion sort for this gap size.
		// The first gap elements a[0..gap-1] are already in gapped order
		// keep adding one more element until the entire array is
		// gap sorted 
		for (int i = gap; i < n; i += 1)
		{
			// add a[i] to the elements that have been gap sorted
			// save a[i] in temp and make a hole at position i
			int temp = arr[i];

			// shift earlier gap-sorted elements up until the correct 
			// location for a[i] is found
			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];

			//  put temp (the original a[i]) in its correct location
			arr[j] = temp;
		}
	}
	return 0;
}
int main()
{
	int c1 = 0, c2 = 0, x = 37;

	srand(time(NULL));
	cout << " n	" << "	I version " << "			II version" << "		NumOfXes" << endl;
	for (int n = 100; n <= 1000; n += 100)
	{
		int *a = new int[n];
		FillRand(a, n);
		shellSort(a, n);
		//PrintMas(a, n); cout << endl;
		//BSearch1(a, n, x, c1); //cout << " c = " << c << endl;
		//BSearch2(a, n, x, c2);
		//cout << n << "		" << c1 << "				" << c2 <<endl;
		nOfxes = 0;
		BSearchAll1(a, n, x, c1, nOfxes); //cout << " c = " << c << endl;
		cout << n << "		" << c1 << "				" << "_" << "			" << nOfxes << endl;
		nOfxes = 0;
		BSearchAll2(a, n, x, c2, nOfxes);
		cout << n << "		" << c1 << "				" << c2 << "			" << nOfxes << endl;
		c1 = 0, c2 = 0;
	}



	_getch();
	return 0;
}