#include<stdio.h>
#include<malloc.h>
#include<cstdlib>
#define ARR_SIZE 500
#define LIMIT 10      //size of array when use insertion sort
#define MIN(A,B) ((A) <= (B) ? (A) : (B))
#define MAX(A,B) ((A) >= (B) ? (A) : (B))

void printArr(int *ARR, int begin, int end)
{
	for (int i = begin; i <= end; i++)
		printf("%i ", ARR[i]);
}

int median(int a, int b, int c)
{
	return a + b + c - MIN(MIN(a, b), c) - MAX(MAX(a, b),c);
} //for determinating pivotal element

void swap(int *first, int *second)
{
	int temp = *first;
	*first = *second;
	*second = temp;
}

void insert_sort(int* arr, int l, int r)
{
	for (int i = l; i <= r; i++) {
		int j = i;
		int temp;
		while (j > 0 && arr[j] < arr[j - 1]) {
			swap(&arr[j], &arr[j - 1]);
			j--;
		}
	}
}  //use instead of quicksort when size of array <=LIMIT

int compare(const void *x1, const void *x2)
{
	return (*(int*)x1 - *(int*)x2);
}//utility func for standart qsort

bool test_0(int* arr, int* test_arr) //test on random data
{
	for (int i = 0; i<ARR_SIZE; i++)
	{
		if (arr[i] != test_arr[i]) return false;
	}
	return true;
}  //compare arrays which was sorted by my qsort and by standart qsort


void quicksort(int* arr, int left_border, int right_border)
{
	if (left_border - right_border <= LIMIT) {       //use insertion to avoid extra recursion
		insert_sort(arr, left_border, right_border);
		return;
	}
	int pivot = median(arr[rand() % right_border + left_border], arr[rand() % ((left_border + right_border) / 2) + left_border], arr[rand() % right_border + left_border]); 
	//pivotal as median of 3 random elements
	int i = left_border;
	int j = right_border;
	while (i <= j)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			swap(&arr[i], &arr[j]);
			i++; j--;
		}
	}
	if (i < right_border) quicksort(arr, i, right_border);
	if (left_border < j) quicksort(arr, left_border, j);
}

void test_1()
{
	int A_3[3] = { 1,-1,12222 };
	printf("Size 3 expected result -1,1,12222\n");
	quicksort(A_3, 0, 2);
	printArr(A_3, 0, 2);
	printf("\n");
	printf("Size 2 expected result -1,1\n");
	int A_2[2] = { 1,-1 };
	quicksort(A_2, 0, 1);
	printArr(A_2, 0, 1);
	printf("\n");
	printf("Size 1 expected result -1\n");
	int A_1[1] = { -1 };
	quicksort(A_1, 0, 0);
	printArr(A_1, 0, 0);
	printf("\n");
	printf("Size 0 expected result nothing");
	int n = 0;
	int *A_0 = (int*)malloc(n * sizeof(int));
	quicksort(A_0, 0, n - 1);
	printArr(A_0, 0, n - 1);
	printf("\n");
}

void test_2() // sorted and reversly sorted arrays test
{
	int A[10] = { -1,-1,1,67,89,89,100,111111,111111,222222 };
	printf("Expected result:\n-1,-1,1,67,89,89,100,111111,111111,222222 \n");
	quicksort(A, 0, 9);
	printArr(A, 0, 9);
	printf("\n");
	printf("Expected result:\n-1,-1,1,67,89,89,100,111111,111111,222222 \n");
	int B[10] = { 222222 ,111111 ,111111,100,89,89,67 ,1 ,-1, -1 };
	quicksort(B, 0, 9);
	printArr(B, 0, 9);
	printf("\n");
}


int main()
{
	int *arr = (int*)malloc(ARR_SIZE * sizeof(int));
	int *test_arr = (int*)malloc(ARR_SIZE * sizeof(int));
	for (int i = 0; i < ARR_SIZE; i++) {
		arr[i] = rand();
		test_arr[i] = arr[i];
	}
	quicksort(arr, 0, ARR_SIZE-1);
	qsort(test_arr, ARR_SIZE, sizeof(int), compare);
	if (test_0(arr, test_arr)) 
		printf("Succesfully sorted.");
	else printf("Bad sorting.");
	test_1();
	test_2();
}
