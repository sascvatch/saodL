#include "stdafx.h"
#include <iostream>//  for cout
#include<conio.h>//for _getch()
using namespace std;// for cout
struct abonent { int num; int phone; char firstName[20]; char secondName[20]; };
int shellSort1(abonent mas[], int arr[], int n)//sort by phone
{
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i += 1) {
			int temp = arr[i];
			int j;
			for (j = i; j >= gap && mas[arr[j - gap]].phone > mas[temp].phone; j -= gap)
				arr[j] = arr[j - gap];
			arr[j] = temp;
		}
	}
	return 0;
}
int shellSort2(abonent mas[], int index[], int n)//sort by firstName
{
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i += 1) {
			int temp = index[i];
			int j;
			for (j = i; j >= gap &&
				strcmp(mas[index[j - gap]].firstName, mas[temp].firstName) > 0; j -= gap)
				index[j] = index[j - gap];

			index[j] = temp;
		}
	}
	return 0;
}
int main()
{	const int n = 5;
	abonent mas[n];	mas[0] = { 1, 8, "Stepan", "Alekseev" };	mas[1] = { 2, 8912, "Ivan", "Frolov" };
	mas[2] = { 3, 0, "Grigory", "Yablokov" };	mas[3] = { 4, -1, "Fedor", "Krestov" };
	mas[4] = { 5, 20, "Anatoliy", "Kipa" };

	int index[n];
	for (int i = 0; i < n; i++)
	{
		index[i] = i;
	}
	shellSort1(mas, index, n);
	/*for (int i =0; i<n; i++)
	{
		cout << mas[index1[i]].firstName << endl;
	}*/
	for (int i = 0; i < n; i++)
	{
		cout << mas[index[i]].firstName << ' ' << mas[index[i]].phone << endl;
	}
	cout << endl;
	shellSort2(mas, index, n);
	for (int i = 0; i < n; i++)
	{
		cout << mas[index[i]].firstName << ' ' << mas[index[i]].phone << endl;
	}
	_getch();
	return 0;
}