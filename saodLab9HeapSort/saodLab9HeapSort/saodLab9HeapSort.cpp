#include "stdafx.h"
#include <stdio.h>
#include <time.h>
#include<stdlib.h>// for srand
#include <iostream>
#include<conio.h>//for _getch()
#include<clocale>
#include <time.h>

int random(int N) { return rand() % N; }

//void SiftDown(int* arr, int i, int l) {
//	int left = 2 * i + 1;
//	int right = 2 * i + 2;
//	//ищем большего сына, если таковой есть
//	int largest = i;
//	if (left<l && arr[left]>arr[i])
//		largest = left;
//}

void iswap(int &n1, int &n2) {
	int temp = n1;
	n1 = n2;
	n2 = temp;
}

int main() {
	int k, y = 10, z = 99;

	srand(NULL);
	unsigned const n = 100u;// что это за u?
	int a[n];

	// Для наглядности заполняем массив числами от n до 0.
	for (unsigned i = 0u; i < n; ++i) {
		a[i]  = random (z - y + 1) ;
		std::cout << a[i] << ' ';
	}

	// ----------- Сортировка ------------
	// Сортирует по возрастанию. Чтобы получить сортировку по убыванию,
	// поменяйте знаки сравнения в строчках, помеченных /*(знак)*/
	unsigned sh = 0u; // Смещение
	bool b;
	do {
		b = false;
		for (unsigned i = 0u; i < n; ++i) {
			if (i * 2 + 2 + sh < n) {
				if ((a[i + sh] > /*<*/ a[i * 2 + 1 + sh]) || (a[i + sh] > /*<*/ a[i * 2 + 2 + sh])) {
					if (a[i * 2 + 1 + sh] < /*>*/ a[i * 2 + 2 + sh]) {
						iswap(a[i + sh], a[i * 2 + 1 + sh]);
						b = true;
					}
					else if (a[i * 2 + 2 + sh] < /*>*/ a[i * 2 + 1 + sh]) {
						iswap(a[i + sh], a[i * 2 + 2 + sh]);
						b = true;
					}
				}
				// Дополнительная проверка для последних двух элементов;
				// с её помощью можно отсортировать пирамиду
				// состоящую всего лишь из трёх элементов
				if (a[i * 2 + 2 + sh] < /*>*/ a[i * 2 + 1 + sh]) {
					iswap(a[i * 2 + 1 + sh], a[i * 2 + 2 + sh]);
					b = true;
				}
			}
			else if (i * 2 + 1 + sh < n) {
				if (a[i + sh] > /*<*/ a[i * 2 + 1 + sh]) {
					iswap(a[i + sh], a[i * 2 + 1 + sh]);
					b = true;
				}
			}
		}
		if (!b)
			++sh; // Смещение увеличивается, когда на текущем этапе сортировать больше нечего
	} while (sh + 2 < n); // Конец сортировки

	std::cout << std::endl << std::endl;
	for (unsigned i = 0u; i < n; ++i)
		std::cout << a[i] << ' ';
	_getch();
	return 0;
}


//Проталкивание элемента вниз. arr - целочисленный массив
//void SiftDown(int& arr, int i, int l) {
//	int left = 2 * i + 1;
//	int right = 2 * i + 2;
//	//ищем большего сына, если таковой есть
//	int largest = i;
//	if (left<l && arr[left]>arr[i])
//		largest = left;
//}
//
//int main()
//{
//    return 0;
//}
//void iswap(int &n1, int &n2) {
//	int temp = n1;
//	n1 = n2;
//	n2 = temp;
//}
//
//int main() {
//	unsigned const n = 100u;
//	int a[n];
//
//	// Для наглядности заполняем массив числами от n до 0.
//	for (unsigned i = 0u; i < n; ++i) {
//		a[i] = n - i;
//		std::cout << a[i] << ' ';
//	}
//
//	// ----------- Сортировка ------------
//	// Сортирует по возрастанию. Чтобы получить сортировку по убыванию,
//	// поменяйте знаки сравнения в строчках, помеченных /*(знак)*/
//	unsigned sh = 0u; // Смещение
//	bool b;
//	do {
//		b = false;
//		for (unsigned i = 0u; i < n; ++i) {
//			if (i * 2 + 2 + sh < n) {
//				if ((a[i + sh] > /*<*/ a[i * 2 + 1 + sh]) || (a[i + sh] > /*<*/ a[i * 2 + 2 + sh])) {
//					if (a[i * 2 + 1 + sh] < /*>*/ a[i * 2 + 2 + sh]) {
//						iswap(a[i + sh], a[i * 2 + 1 + sh]);
//						b = true;
//					}
//					else if (a[i * 2 + 2 + sh] < /*>*/ a[i * 2 + 1 + sh]) {
//						iswap(a[i + sh], a[i * 2 + 2 + sh]);
//						b = true;
//					}
//				}
//				// Дополнительная проверка для последних двух элементов;
//				// с её помощью можно отсортировать пирамиду
//				// состоящую всего лишь из трёх элементов
//				if (a[i * 2 + 2 + sh] < /*>*/ a[i * 2 + 1 + sh]) {
//					iswap(a[i * 2 + 1 + sh], a[i * 2 + 2 + sh]);
//					b = true;
//				}
//			}
//			else if (i * 2 + 1 + sh < n) {
//				if (a[i + sh] > /*<*/ a[i * 2 + 1 + sh]) {
//					iswap(a[i + sh], a[i * 2 + 1 + sh]);
//					b = true;
//				}
//			}
//		}
//		if (!b)
//			++sh; // Смещение увеличивается, когда на текущем этапе сортировать больше нечего
//	} while (sh + 2 < n); // Конец сортировки
//
//	std::cout << std::endl << std::endl;
//	for (unsigned i = 0u; i < n; ++i)
//		std::cout << a[i] << ' ';
//
//	return 0;
//}
