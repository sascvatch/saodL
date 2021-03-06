// SaodLab6Ol.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char x, y; int M, C;
void FillInc(int* A, int n) {
	srand(time(NULL));
	A[0] = rand() % n; int i;
	for (i = 1; i < n; i++) {
		A[i] = rand() % n; if (A[i - 1] > A[i]) A[i] = A[i - 1] + (rand() % n);
	}
}
void FillDec(int* A, int n) {
	srand(time(NULL));
	A[0] = rand() % n; int i;
	for (i = 1; i < n; i++) {
		A[i] = rand() % n; if (A[i - 1] < A[i]) A[i] = A[i - 1] - rand() % n;
	}
}
void FillRand(int* A, int n) {
	srand(time(NULL));
	int i;
	for (i = 0; i < n; i++) A[i] = rand() % n;
}
void CheckSum(int* A, int n) {
	int i, S = 0;
	for (i = 0; i < n; i++) S += A[i];
	printf("Control sum - %d", S);
}
void RunNumber(int* A, int n) {
	int i, m = 1;
	for (i = 0; i < n - 1; i++)
		if (A[i] > A[i + 1]) m++;
	printf("Series - %d", m); printf("\n");
	if (x) printf("A FillInc seq has %d series", m);
	else if (y) printf("A FillDec seq has %d series", m);
}
void PrintMas(int* A, int n) {
	int i; for (i = 0; i < n; i++) printf("%d ", A[i]);
}
int l(int k) {
	short int g = -1;
	while (k) {
		k = (k - k % 2) / 2; g++;
	}
	return g;
}
void ShellSort(int* A, int n) {
	int t, i, j, k; k = l(n);
	while (k) {
		for (i = k ; i < n; i++) {
			t = A[i], j = i - k;
			while ((j > -1) && (t < A[j])) A[j + 1] = A[j], j -= k;
			A[j + k] = t;
		} k = (k - k % 2) / 2;
	}
}
void InsertFact(int* A, int n) {
	int t, i, j; M = C = 0;
	for (i = 1; i < n; i++) {
		t = A[i], j = i - 1; M++; C++;
		while ((j > -1) && (t < A[j])) C++, A[j + 1] = A[j], M++, j -= 1;
		A[j + 1] = t; M++;
	}
	printf(" M: %d C: %d T: %d ", M, C, M + C); M = C = 0;
}
void TrueInsert(int* A, int n) {
	int t, i, j; M = C = 0;
	for (i = 1; i < n; i++) {
		t = A[i], j = i - 1; M++; C++;
		while ((j > -1) && (t < A[j])) C++, A[j + 1] = A[j], M++, j -= 1;
		A[j + 1] = t; M++;
	}
	printf("%12d ", M + C); M = C = 0;
}
void TrueShell(int* A, int n) {
	int t, i, j, k, h = 0; k = l(n); M = C = 0;
	while (k) {
		h++;
		for (i = k ; i < n; i++) {
			t = A[i], j = i - k; M++; C++;
			while ((j > -1) && (t < A[j])) C++, A[j + 1] = A[j], M++, j -= k;
			A[j + k] = t; M++;
		} k = (k - k % 2) / 2;
	}
	printf(" %d %12d", h, M + C);
}
void Table(int* A) {
	int n, i, k; scanf_s("%d", &k); printf("\n n  h  ShellSort  InsertSort");
	for (i = 1; i < k; i++) {
		n = 100 * i; printf("\n%3d ", n);
		A = (int *)malloc(n * sizeof(int));
		FillRand(A, n); TrueShell(A, n);
		FillRand(A, n); TrueInsert(A, n);
		free(A);
	}
}
int main() {
	int n, t; int* A;
	printf("Write a number of elements \n"), scanf_s("%d", &n);
	A = (int *)malloc(n * sizeof(int));
	srand(time(NULL));
	printf("Welkcome. Menu: \n");
	printf("1 - PrintMas \n");
	printf("2 - FillRand (start work here) \n");
	printf("3 - FillInc \n");
	printf("4 - FillDec \n");
	printf("5 - CheckSum \n");
	printf("6 - RunNumber \n");
	printf("7 - InsertSort \n");
	printf("8 - InsertFact \n");
	printf("9 - Table \n");
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
		case 7: { ShellSort(A, n); break; }
		case 8: { InsertFact(A, n); break; }
		case 9: { Table(A); break; }
		}
		printf("\n");
	}
}
