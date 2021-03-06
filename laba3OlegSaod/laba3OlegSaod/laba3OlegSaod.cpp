#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>//  for cout
using namespace std;// for cout
char x, y; int M, C;
void FillInc(int* A, int n) {
	A[0] = rand() % 20; int i;
	for (i = 1; i<n; i++) {
		A[i] = rand() % 20; if (A[i - 1]>A[i]) A[i]= A[i-1]+ rand() % 20 + 1;
	}
}
void FillDec(int* A, int n) {
	A[0] = rand() % 20; int i;
	for (i = 1; i<n; i++) {
		A[i] = rand() % 20; if (A[i - 1]<A[i]) A[i]=A[i-1]-(rand() % 20 + 1);
	}
}
void FillRand(int* A, int n) {
	int i;
	for (i = 0; i<n; i++) A[i] = rand() % n;
}
void CheckSum(int* A, int n) {
	int i, S = 0;
	for (i = 0; i<n; i++) S += A[i];
	printf("Control sum - %d", S);
}
void RunNumber(int* A, int n) {
	int i, m = 1;
	for (i = 0; i<n - 1; i++)
		if (A[i]>A[i + 1]) m++;
	printf("Series - %d", m); printf("\n");
	if (x) printf("A FillInc seq has %d series", m);
	else if (y) printf("A FillDec seq has %d series", m);
}
void PrintMas(int* A, int n) {
	int i; for (i = 0; i<n; i++) printf("%d ", A[i]);
}
void BubleSort(int* A, int n) {
	int k = 0, i, P;
 while (k<(n - 1)) {
		for (i = n - 1; i>k; i--)
			if (A[i]<A[i - 1])  P = A[i], A[i] = A[i - 1], A[i - 1] = P;
		k++;
	}
}
void fact(int n) {
	C = (n*(n - 1)) / 2; M = 3 * C / 2;
	printf("M: %d C: %d \n", M, C); M = C = 0;
}
void BubleFact(int* A, int n) {
	int k = 0, i, P; 
		while (k<n - 1) {
			for (i = n - 1; i > k; i--) {
				C++;
				if (A[i] < A[i - 1])  P = A[i], A[i] = A[i - 1], A[i - 1] = P, M += 3;
			}
			k++;
		}
		cout.width(5); cout << " |M: "; cout.width(10); cout << M; cout.width(5); cout << " |C: ";
		cout.width(10); cout << C; cout.width(5); cout << " |T: "; cout.width(10);cout << (M + C);
		M = C = 0;
	//printf(" I |M: %d |C: %d |T: %d ", M, C, M + C);
}
void DoTable(int* A) {
	int n; printf("\n n    T(formuli)                        FD;                                FR                                              FI  ");
	for (n = 100; n<600; n += 100) {
		printf("\n %d", n);
		free(A);
		A = (int *)malloc(n * sizeof(int));
		C = (n*(n - 1)) / 2; M = 3 * C / 2; cout.width(10); cout << (M + C); //printf(" %d", M + C);
		FillDec(A, n); BubleFact(A, n);
		FillRand(A, n); BubleFact(A, n);
		FillInc(A, n); BubleFact(A, n);
	}
}
int main() {
	int n, t; int* A;
	printf("Write a number of elements \n"), scanf_s("%d", &n);
	A = (int *)malloc(n * sizeof(int));
	srand(time(NULL));
	printf("Welkcom	e. Menu: \n");
	printf("1 - PrintMas \n");
	printf("2 - FillRand (start work here) \n");
	printf("3 - FillInc \n");
	printf("4 - FillDec \n");
	printf("5 - CheckSum \n");
	printf("6 - RunNumber \n");
	printf("7 - BubleSort \n");
	printf("8 - fact \n");
	printf("9 - BubleFact \n");
	printf("10 - DoTable \n");
	printf("0 - exit \n");
	t = 1;
	while (t) {
		scanf_s("%d", &t);
		switch (t) {
		case 1: { PrintMas(A, n);	break;	}
		case 2: { FillRand(A, n);	break; }
		case 3: { FillInc(A, n);	break; }
		case 4: { FillDec(A, n);	break; }
		case 5: { CheckSum(A, n);	break; }
		case 6: { RunNumber(A, n);	break; }
		case 7: { BubleSort(A, n); break; }
		case 8: { fact(n); break; }
		case 9: { BubleFact(A, n); break; }
		case 10: { DoTable(A); break; }
		}
		printf("\n");
	}
}
