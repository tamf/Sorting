#include <iostream>

using namespace std;

void selectionSortRecurHelper(int array[], int start, int end);

/*
Selection Sort using Recursion
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
	return selectionSortRecurHelper(array, start + 1, end);
}

/*
Selection Sort using Iteration
*/

void selectionSortIter(int array[], int length) {
	for (int start = 0; start < length - 1; start++) {
		int smallestElement = array[start];
		int smallestElementIndex = start;
		for (int i = start + 1; i <= length - 1; i++) {
			if (array[i] < smallestElement) {
				smallestElementIndex = i;
				smallestElement = array[i];
			}
		}
		int temp = array[start];
		array[start] = smallestElement;
		array[smallestElementIndex] = temp;
	}
}

/*
Insertion Sort
*/

void insertionSort(int array[], int length) {

	for (int i = 1; i < length; i++) {
		int numToSort = array[i];
		int j = i;
		while (j > 0 && numToSort < array[j - 1]) {
			array[j] = array[j - 1];
			j--;
		}
		array[j] = numToSort;

	}
}

int main() {
	//Testing iterative selection sort
	int array1[10] = { 2, 1, 5, 6, 8, 3, 4, 9, 7, 10 };
	selectionSortIter(array1, 10);
	cout << "Iterative selection sort, result: ";
	for (int i = 0; i < 10; i++) {
		cout << array1[i] << " ";
	}
	cout << endl;


	//Testing recursive selection sort
	int array2[10] = { 1, 3, 5, 2, 4, 6, 10, 9, 8, 7 };
	selectionSortRecur(array2, 10);
	cout << "Recursive selection sort, result: ";
	for (int i = 0; i < 10; i++) {
		cout << array1[i] << " ";
	}
	cout << endl;


	//Testing insertion sort
	int array3[10] = { 1, 3, 5, 2, 4, 6, 10, 9, 8, 7 };
	insertionSort(array3, 10);
	cout << "Iterative insertion sort, result: ";
	for (int i = 0; i < 10; i++) {
		cout << array1[i] << " ";
	}
	cout << endl;

	cin.get();
	return 0;
}