#include "stdafx.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int M, C;
void FillInc(int* A, int n) {
	A[0] = rand() % n; int i;
	for (i = 1; i<n; i++) {
		A[i] = A[i - 1] + rand() % n;
	}
}void FillDec(int* A, int n) {
	A[0] = rand() % n; int i;
	for (i = 1; i<n; i++) {
		A[i] = A[i - 1] - (rand() % n);
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
}
void PrintMas(int* A, int n) {
	int i; for (i = 0; i<n; i++) printf("%d ", A[i]);
}
void SelectSort(int* A, int n) {
	int i, j = 0, R, P; char u;
	printf("+ or -? (1 or 0) \n");
	scanf_s("%d", &u);
	if (u)
		while (j<n - 1) {
			R = j;
			for (i = j + 1; i<n; i++) { if (A[i]<A[R]) R = i; }
			P = A[j], A[j] = A[R], A[R] = P; j++;
		}
	else while (j<n - 1) {
		R = j;
		for (i = j + 1; i<n; i++) { if (A[i]>A[R]) R = i; }
		P = A[j], A[j] = A[R], A[R] = P; j++;
	}
}
void SelectSortCM(int* A, int n) {
	int i, j = 0, R, P; char u;
	printf("+ or -? (1 or 0) \n");
	scanf_s("%d", &u);
	if (u)
		while (j<n - 1) {
			R = j;
			for (i = j + 1; i<n; i++) { C++; if (A[i]<A[R]) R = i; }
			P = A[j], A[j] = A[R], A[R] = P; M += 3; j++;
		}
	else while (j<n - 1) {
		R = j;
		for (i = j + 1; i<n; i++) { C++; if (A[i]>A[R]) R = i; }
		P = A[j], A[j] = A[R], A[R] = P; M += 3; j++;
	}
	printf("M= %d, C= %d.", M, C); M = C = 0;
}
void SelectSortOpt(int* A, int n) {
	int i, j = 0, R, P; char u;
	printf("+ or -? (1 or 0) \n");
	scanf_s("%d", &u);
	if (u)
		while (j<n - 1) {
			R = j;
			for (i = j + 1; i<n; i++) { C++; if (A[i]<A[R]) R = i; }
			if (R != j) { P = A[j], A[j] = A[R], A[R] = P; M += 3; } j++;
		}
	else while (j<n - 1) {
		R = j;
		for (i = j + 1; i<n; i++) { C++; if (A[i]>A[R]) R = i; }
		if (R != j) { P = A[j], A[j] = A[R], A[R] = P; M += 3; } j++;
	}
	printf("M= %d, C= %d.", M, C); M = C = 0;
}
void fact(int n) {
	C = (n*(n - 1)) / 2; M = 3 * (n - 1);
	printf("In theor C= %d, M= %d", C, M); C = M = 0;
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
	printf("7 - SelectSort \n");
	printf("8 - SelectSortwithCM \n");
	printf("9 - fact \n");
	printf("10 - SelectSort Opt\n");
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
		case 7: { SelectSort(A, n); break; }
		case 8: { SelectSortCM(A, n); break; }
		case 9: { fact(n); break; }
		case 10: { SelectSortOpt(A, n); break; }
		}
		printf("\n");
	}
}
