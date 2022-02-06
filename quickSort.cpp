/* C++ implementation of QuickSort */
#include <bits/stdc++.h>
using namespace std;

// A utility function to swap two elements
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition (int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot
		if (arr[j] < pivot)
		{
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

/* Function to print an array */
void printArray(int* arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}
void merge(int nums1[], int m,int nums2[], int n, int nums3[]){
    for (int i=0; i<m; i++) {
        nums3[i] = nums1[i];
    }
    for (int i=0; i<n; i++) {
        nums3[i+m] = nums2[i];
    }
}

// Driver Code
int main()
{
	int arr1[] = {10, 7, 8, 9, 1, 5};
    int arr2[] = {34,66,22,88,2};
    
    int m = sizeof(arr1) / sizeof(arr1[0]);
	int n = sizeof(arr2) / sizeof(arr2[0]);
    int arr3[m+n];
    merge(arr1, m, arr2, n, arr3);
    int l = sizeof(arr3) / sizeof(arr3[0]);
    cout<<"after merge arr1 length:"<< l <<endl;
	quickSort(arr3, 0, l - 1);
	cout << "Sorted array: \n";
	printArray(arr3, l);
	return 0;
}

// This code is contributed by rathbhupendra
