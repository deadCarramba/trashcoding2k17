#include<stdio.h>
#include<malloc.h>
#include<cstdlib>
#define ARR_SIZE 500
#define LIMIT 10      //size of array when use insertion sort
#define MIN(A,B) ((A) <= (B) ? (A) : (B))
#define MAX(A,B) ((A) >= (B) ? (A) : (B))
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

bool test(int* arr, int* test_arr)
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
	if (test(arr, test_arr)) 
		printf("Succesfully sorted.");
	else printf("Bad sorting.");
}

