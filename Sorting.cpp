#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void selectionSortRecurHelper(int array[], int start, int end);

/*
Selection Sort (Recursive)
*/
void selectionSortRecur(int array[], int length) {
	selectionSortRecurHelper(array, 0, length - 1);
}
void selectionSortRecurHelper(int array[], int start, int end) {

	// if the array to sort is empty, already sorted
	if (start == end) {
		return;
	}

	// set the smallest element to the first element
	int smallestElement = array[start];
	int smallestElementIndex = start;

	// go through rest of elements, find the smallest element
	for (int i = start + 1; i <= end; i++) {
		if (array[i] < smallestElement) {
			smallestElementIndex = i;
			smallestElement = array[i];
		}
	}

	// swapping the first element with the smallest element
	int temp = array[start];
	array[start] = smallestElement;
	array[smallestElementIndex] = temp;

	// recursive call to sort rest of the array
	selectionSortRecurHelper(array, start + 1, end);
}

/*
Selection Sort (Iterative)
*/

void selectionSortIter(int array[], int length) {

	// for every 'sub-array' that ends at the end of the initial array...
	for (int start = 0; start < length - 1; start++) {
		// Set the smallest element to the first element
		int smallestElement = array[start];
		int smallestElementIndex = start;

		// Now find the real smallest element in the 'sub-array' from i to the end
		for (int i = start + 1; i <= length - 1; i++) {
			if (array[i] < smallestElement) {
				smallestElementIndex = i;
				smallestElement = array[i];
			}
		}
		// swap first element of sub-array with smallest element
		int temp = array[start];
		array[start] = smallestElement;
		array[smallestElementIndex] = temp;
	}
}

/*
Insertion Sort (Iterative)

First element is a sorted 'sub-array'. Take second element and insert it in the correct place in the sub-array consisting of the first element.
Now the first two elements are sorted. Take third element and insert in correct place in the sorted sub-array consisting of the first two elements. 
Now the first three elements are sorted. Continue until all elements have been inserted in the right place into a sorted sub-array.
*/

void insertionSort(int array[], int length) {
	
	for (int i = 1; i < length; i++) {
		int numToSort = array[i];
		// j represents the current spot the number to sorted will be placed in if there are no elements in the rest of the sub-array that are larger than it
		int j = i;

		// if the number to sort is less than the last element of the sorted 'sub-array', we move the last element further down
		// repeat with second last element etc until we find an element larger than the number to sort, or we get to the beginning (no more elements)
		while (j > 0 && numToSort < array[j - 1]) {
			array[j] = array[j - 1];
			j--;
		}
		array[j] = numToSort;

	}
}

/*
Swap values at two indices in an array of integers
*/

void swap(int array[], int x, int y) {
	int temp = array[x];
	array[x] = array[y];
	array[y] = temp;
}

/*
Quick Sort (Recursive)
*/

void quickSortHelper(int array[], int start, int end);

void quickSort(int array[], int length) {
	quickSortHelper(array, 0, length - 1);
}

void quickSortHelper(int array[], int start, int end) {
	// base case
	if (start >= end) {
		return;
	}
	// choose a random index to get the pivot
	srand(time(NULL));
	int pivotIndex = rand() % (end - start + 1) + start;
	int pivot = array[pivotIndex];

	// move the pivot to the front
	swap(array, start, pivotIndex);

	// m represents where the pivot will go after all the elements have been compared
	int m = start;

	// we will put all elements that are smaller than the pivot at the front of the array
	for (int i = start + 1; i <= end; i++) {
		if (pivot > array[i]) {
			swap(array, ++m, i);
		}
	}
	// swapping the pivot to index m will result in all elements to the left of m being smaller or equal to m, and all elements to the right being larger or equal
	swap(array, start, m);

	// recursive calls
	quickSortHelper(array, start, m - 1);
	quickSortHelper(array, m + 1, end);
}

int main() {
	//Testing iterative selection sort
	int array1[10] = { 2, 1, 5, 2, 8, 3, 4, 9, 7, 10 };
	selectionSortIter(array1, 10);
	cout << "Iterative selection sort, result: " << endl;
	for (int i = 0; i < 10; i++) {
		cout << array1[i] << " ";
	}
	cout << endl;


	//Testing recursive selection sort
	int array2[10] = { 1, 3, 5, 2, 4, 4, 10, 9, 8, 7 };
	selectionSortRecur(array2, 10);
	cout << "Recursive selection sort, result: " << endl;
	for (int i = 0; i < 10; i++) {
		cout << array2[i] << " ";
	}
	cout << endl;


	//Testing insertion sort
	int array3[10] = { 1, 3, 5, 2, 4, 6, 10, 3, 8, 7 };
	insertionSort(array3, 10);
	cout << "Iterative insertion sort, result: " << endl;
	for (int i = 0; i < 10; i++) {
		cout << array3[i] << " ";
	}
	cout << endl;
	
	//Testing quick sort
	int array4[10] = { 1, 3, 5, 2, 4, 6, 10, 3, 8, 7 };
	quickSort(array4, 10);
	cout << "Iterative quick sort, result: " << endl;
	for (int i = 0; i < 10; i++) {
		cout << array4[i] << " ";
	}
	cout << endl;

	



	cin.get();
	return 0;
}