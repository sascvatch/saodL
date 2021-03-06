#include "stdafx.h"
#include <time.h>
#include<stdlib.h>// for srand
#include <iostream>
#include<conio.h>//for _getch()
#include<clocale>//как подгрузить функции из другого проекта?
//#include <graphics.h>

using namespace std;
int m = 0, c = 0, mf = 0, cf = 0;
int random(int N) { return rand() % N; }/* разобрался наконец-то как это работает.
										Сюда подаётся N, которая представляет из себя отличие а от b.
										От rand() в итоге отсекается число*
										...пока могу думать только о положительных... так ранд только положительные и выдаёт...
										*от нуля до b-a(например если а = -5,
										b = 10, то rand() % N; выдаст число от нуля до 15. В вызывающем методе ещё прибавится а, т.е. -5.
										Т.о. и выдаётся результат от -5 до 10.*/
int l = 0, z = 99;
void FillInc(int *a, int n) {

	a[0] = random(z - l + 1) + l;
	for (int i = 1; i < n; i++)
	{
		a[i] = a[i - 1] + random(z - l + 1) + l;
	}
}
void FillDec(int *a, int n) {
	if (n > 0) a[0] = random(z - l + 1) + l; else return;
	for (int i = 1; i < n; i++)
	{
		a[i] = a[i - 1] - random(z - l + 1) + l;
	}
}
void FillRand(int *a, int n) {
	for (int i = 0; i < n; i++)
	{
		a[i] = random(z - l + 1) + l;
	}
}
int CheckSum(int*a, int n) {// подсчёт контрольной суммы
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
	}
	printf("Контрольная сумма: %d", sum); return sum;
}

int RunNumber(int*a, int n) {//подсчёт серий
	int x = 0, k = 1;
	if (n > 1) {
		for (int i = 0; i < n - 1; i++) {
			if (a[i] > a[i + 1]) {
				k++;
			}
		}
		printf("Количество серий: %d", k); return k;
	}
	else { printf("Количество серий: %d", k); return k; }
}
void PrintMas(int*a, int n) {
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}//printf("\n");
}

void SelectSort(int *a, int n, int &m, int &c) {
	int mf = 3 * (n - 1), cf = (n*n - n) / 2;
	for (int i = 0; i < n; i++)
	{
		c++;
		int min = i;
		for (int q = i + 1; q < n; q++)
		{
			if (a[min] > a[q]) {
				min = q;
			}
		}
		m += 3;
		int temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
	printf("m = %d, c = %d, m по формулам = %d, c по формулам = %d ", m, c, mf, cf);
}
void SelectSortImproved(int *a, int n, int &m, int &c) {
	int mf = 3 * (n - 1), cf = (n*n - n) / 2;
	for (int i = 0; i < n; i++)
	{
		int min = i;
		for (int q = i + 1; q < n; q++)
		{
			c++;
			if (a[min] > a[q]) {
				min = q;
			}
		}

		if (i != min) {//здесь убираю фиктивные перестановки
			int temp = a[i];
			a[i] = a[min];
			a[min] = temp;
			m += 3;
		}
	}
	printf("m (оптимизированные перестановки) = %d, c = %d, m по формулам = %d, c по формулам = %d ", m, c, mf, cf);
}
void CheckAverage() {
	double sum = 0;//среднее
	int n = 10, d = 100;// размер массива, 
	int*a = new int[n];
	for (int i = 0; i < d; i++)
	{
		FillRand(a, n);
		sum += RunNumber(a, n);
		cout << endl;
	}
	printf("средняя длина серии = %f  ", (d*n) / sum);
}

void BubbleSort(int *a, int n) {
	for (int i = 0; i < n - 1; i++)
	{
		for (int q = i + 1; q < n; q++)
		{
			c++;
			if (a[i] > a[q]) {
				int temp = a[i];
				a[i] = a[q];
				a[q] = temp;
				m += 3;
			}
		}
	}
}
void printTable() {
	cout << "n    " << "  Трудо-тьФрмл  " << "  Трудо-тьУбывающ  " << "  Трудо-тьВозрастающ" << "  Трудо-тьРандомного  " << endl;
}
void CountFormulas(int n, int &mf, int &cf) {//считаем трудоёмкость по формулам... амперсанды в принципе не нужны, как и передача этих параметров... просто напоминалка о том, как работает передача адресов для работы со ссылками переменных
	mf = 3 * (n - 1), cf = (n*n - n) / 2;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	int *a, n = 10;
	printTable();
	for (int i = 100; i <= 500; i += 100)
	{
		a = new int[i];
		
		FillDec(a, i);
		BubbleSort(a, i);
		CountFormulas(i, mf, cf);
		cout.width(4); cout << i; cout.width(8); cout << (mf + cf);
		FillInc(a, i);
		BubbleSort(a, i);

			m = c = mf = cf = 0;

	}

	/*printTable();
	FillRand(a, n);
	BubbleSort(a, n);
	PrintMas(a, n);*/

	_getch();
	return 0;
}

/*//CheckAverage();// это код для main первой и второй лабы
	//FillInc(a, n);
	//PrintMas(a, n);
	//cout << RunNumber(a, n) << endl;// CheckSum(a, n);
	//FillDec(a, n);
	//PrintMas(a, n);
	//cout << RunNumber(a, n) << endl;
	//for (int i = 0; i < 10; i++)
	//{
	//	FillRand(a, n);
	//	PrintMas(a, n);
	//	cout << RunNumber(a, n)<<endl<<endl;
	//}

	for (int i = 0; i < 1; i++)
	{

		FillRand(a, n);
		PrintMas(a, n);
		cout << "Рандомный массив" << endl;
		CheckSum(a, n);
		cout << endl;
		RunNumber(a, n);
		cout << endl;
		SelectSort(a, n, m, c);
		m = 0; c = 0;
		cout << endl;
		PrintMas(a, n);
		cout << endl;
		CheckSum(a, n);
		cout << endl;
		RunNumber(a, n);
		cout << endl;
		cout << endl;
	}
	for (int i = 0; i < 1; i++)
	{

		FillInc(a, n);
		PrintMas(a, n);
		cout << "Возрастающий массив" << endl;
		CheckSum(a, n);
		cout << endl;
		RunNumber(a, n);
		cout << endl;
		SelectSort(a, n, m, c);
		m = 0; c = 0;
		cout << endl;
		PrintMas(a, n);
		cout << endl;
		CheckSum(a, n);
		cout << endl;
		RunNumber(a, n);
		cout << endl;
		cout << endl;
	}
	for (int i = 0; i < 1; i++)
	{

		FillDec(a, n);
		PrintMas(a, n);
		cout << "Убывающий массив" << endl;
		CheckSum(a, n);
		cout << endl;
		RunNumber(a, n);
		cout << endl;
		SelectSort(a, n, m, c);
		m = 0; c = 0;
		cout << endl;
		PrintMas(a, n);
		cout << endl;
		CheckSum(a, n);
		cout << endl;
		RunNumber(a, n);
		cout << endl;
		cout << endl;
	}
	for (int i = 0; i < 1; i++)
	{

		FillRand(a, n);
		PrintMas(a, n);
		cout << "Рандомный массив" << endl;
		CheckSum(a, n);
		cout << endl;
		RunNumber(a, n);
		cout << endl;
		SelectSortImproved(a, n, m, c);
		m = 0; c = 0;
		cout << endl;
		PrintMas(a, n);
		cout << endl;
		CheckSum(a, n);
		cout << endl;
		RunNumber(a, n);
		cout << endl;
		cout << endl;
	}
	for (int i = 0; i < 1; i++)
	{

		FillInc(a, n);
		PrintMas(a, n);
		cout << "Возрастающий массив" << endl;
		CheckSum(a, n);
		cout << endl;
		RunNumber(a, n);
		cout << endl;
		SelectSortImproved(a, n, m, c);
		m = 0; c = 0;
		cout << endl;
		PrintMas(a, n);
		cout << endl;
		CheckSum(a, n);
		cout << endl;
		RunNumber(a, n);
		cout << endl;
		cout << endl;
	}
	for (int i = 0; i < 1; i++)
	{

		FillDec(a, n);
		PrintMas(a, n);
		cout << "Убывающий массив" << endl;
		CheckSum(a, n);
		cout << endl;
		RunNumber(a, n);
		cout << endl;
		SelectSortImproved(a, n, m, c);
		m = 0; c = 0;
		cout << endl;
		PrintMas(a, n);
		cout << endl;
		CheckSum(a, n);
		cout << endl;
		RunNumber(a, n);
		cout << endl;
		cout << endl;
	}*/
	/*Лабораторная работа № 1

	1). Дан массив А из n целых чисел.
	Разработать шесть сервисных процедур, которые будут использованы в следующих лабораторных работах:
	a) процедуру FillInc, заполняющую массив А возрастающими числами.
	b) процедуру FillDec, заполняющую массив А убывающими числами.
	c) процедуру FillRand, заполняющую массив А случайными числами.
	d) функцию CheckSum для подсчета контрольной суммы элементов массива А.
	e) функцию RunNumber  для подсчета серий в массиве А.
	f) процедуру PrintMas для вывода  на  экран  элементов  массива А.

	Массив А и кол-во n – параметры процедур !!!
	*/
	/*2). Экспериментально определить:
	• кол-во серий в возрастающем массиве
	• кол-во серий в убывающем массиве

	Определение.  Серией называется неубывающая последовательность максимальной длины.
	Пример:  23145314  23  145  3  14   т.е. 4 серии

	3).  Дополнительное задание (на 5+):
	Экспериментально определить среднюю длину серии в случайном массиве.*/

	//int RunNumber(int*a, int n) {// Здесь сделано не так, как надо. Здесь я считаю только серии из нескольких чисел, а надо считать даже и числа не входящие в цепочку.
	//	int x = 0, k = 0;
	//	if (a[0] < a[1]) x = 1; else x = 0;
	//	for (int i = 1; i < n - 1; i++)
	//	{
	//		if (a[i] <= a[i + 1]) {
	//			x = 1;
	//			//continue;
	//		}
	//		else { k += x; x = 0; }
	//		if (a[i] == n - 1)k += x;//Это я пробую исправить ситуацию, когда в конце было 90 70 70 и эта последняя серия не посчиталась
	//	}return k;
	//}