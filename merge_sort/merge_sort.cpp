#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"


void Merge(int *A, int begin, int mid, int end);

void printArr(int *A, int begin, int end)
{
	for (int i = begin; i <= end; i++)
		printf("%i ", A[i]);
}

void  MergeSort(int *A, int begin, int end)
{
	if (begin < end)
	{
		int mid = ((end + begin) / 2);
		MergeSort(A, begin, mid);
		MergeSort(A, mid + 1, end);
		Merge(A, begin, mid, end);
	}
}

void Merge(int *A, int begin, int mid, int end)
{
	int *Arr = (int*)malloc((end - begin + 1) * sizeof(int));
	int lArr = 0;
	int l = begin, p = mid + 1;

	for (int i = begin; i <= end; i++) {
		if (l > mid)      //левая часть дошла ли до конца
		{
			Arr[lArr++] = A[p++];
		}

		else if (p > end)   //правая часть дошла ли до конца
		{
			Arr[lArr++] = A[l++];
		}

		else if (A[l] < A[p])     //сравниваем элементы правой и левой части
		{
			Arr[lArr++] = A[l++];
		}
		else
		{
			Arr[lArr++] = A[p++];
		}
	}
	for (int i = 0; i< lArr; i++) //формируем отсортированный массив
		A[begin++] = Arr[i];
	free(Arr);
}
void test_0() // просто массив случайных данных
{
	int n = 15;
	int *A = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		A[i] = rand() % 100;
	}
	MergeSort(A, 0, n - 1);
	printArr(A, 0, n - 1);
	for (int i = 0; i < n - 1; i++)
		if (A[i] > A[i + 1])
		{
			printf("\nerror\n"); break;
		}
	free(A);
}

void test_1() //массив размера 0,1,2,3
{
	int A_3[3] = { 1,-1,12222 };
	printf("Size 3 expected result -1,1,12222\n");
	MergeSort(A_3, 0, 2);
	printArr(A_3, 0, 2);
	printf("\n");
	printf("Size 2 expected result -1,1\n");
	int A_2[2] = { 1,-1 };
	MergeSort(A_2, 0, 1);
	printArr(A_2, 0, 1);
	printf("\n");
	printf("Size 1 expected result -1\n");
	int A_1[1] = { -1 };
	MergeSort(A_1, 0, 0);
	printArr(A_1, 0, 0);
	printf("\n");
	printf("Size 0 expected result nothing");
	int n = 0;
	int *A_0 = (int*)malloc(n * sizeof(int));
	MergeSort(A_0, 0, n - 1);
	printArr(A_0, 0, n - 1);
	printf("\n");
}

void test_2() //отсортированный и обратно отсортированный массивы
{
	int A[10] = { -1,-1,1,67,89,89,100,111111,111111,222222 };
	printf("Expected result:\n-1,-1,1,67,89,89,100,111111,111111,222222 \n");
	MergeSort(A, 0, 9);
	printArr(A, 0, 9);
	printf("\n");
	printf("Expected result:\n-1,-1,1,67,89,89,100,111111,111111,222222 \n");
	int B[10] = { 222222 ,111111 ,111111,100,89,89,67 ,1 ,-1, - 1 };
	MergeSort(B, 0, 9);
	printArr(B, 0, 9);
	printf("\n");
}
int begin, end;
void main()
{


	//test_0();
	test_2();

}

