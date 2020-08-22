#include<iostream>
using namespace std;
#define SIZE 10

void merge(int arr[], int low, int middle, int high) {
	int n1 = middle - low+1;
	int n2 = high - middle;

	int left_arr[SIZE];
	int right_arr[SIZE];

	for (int i = 0; i < n1; i++) 	
		left_arr[i] = arr[low+i];
	for (int j = 0; j < n2; j++)
		right_arr[j] = arr[middle+1+j];
	
	left_arr[n1] = 999;
	right_arr[n2] = 999;

	int i, j, k;
	i = j = 0;
	for (k = low; k <= high; k++) {
		if ((left_arr[i] <= right_arr[j])) {
			arr[k] = left_arr[i];
			i++;
		}
		else {
			arr[k] = right_arr[j];
			j++;
		}
	}
}
void mergeSort(int arr[], int low, int high) {
	if (low < high) {
		int middle = (low + (high-1)) / 2;
		mergeSort(arr, low, middle);
		mergeSort(arr, middle + 1, high);
		merge(arr, low, middle, high);
	}
}
void mySwap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}
int partition(int arr[], int low, int high) {
	int pivot = arr[low];
	int q = low;
	for (int s = low+1; s <= high; s++) {
		if (arr[s] < pivot) {
			q++;
			mySwap(&arr[q], &arr[s]);
		}
	}
	mySwap(&arr[low], &arr[q]);
	return q;
}
void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int q = partition(arr, low, high);
		quickSort(arr, low, q - 1);
		quickSort(arr, q + 1, high);
	}
}
void printArray(int arr[],int num) {
	for (int i = 0; i < num; i++) 
		cout << arr[i] << "  ";
}
void bubbleSort(int arr[],int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-i - 1; j++) {
			if (arr[j] > arr[j + 1])
				mySwap(&arr[j], &arr[j + 1]);
		}
	}
}
void selectionSort(int arr[], int n) {
	int min_index;
	for (int i = 0; i < n - 1; i++) {
		min_index = i;
		for (int j = i+1; j < n ; j++) {
			if (arr[j] < arr[min_index])
				min_index = j;
		}
		mySwap(&arr[min_index], &arr[i]);
	}
}
void insertionSort(int arr[], int n) {
	for (int i = 1; i < n; i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

int main() {
	int array[SIZE];
	int num;
	int choice = 0;
	bool flag = false;
	while (true) {
		cout << "\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << "\t\t\t                MENU                \n";
		cout << "\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << "\t\t\t          1. New				       \n";
		cout << "\t\t\t          2. Bubble Sort            \n";
		cout << "\t\t\t          3. Selection Sort         \n";
		cout << "\t\t\t          4. Insertion Sort         \n";
		cout << "\t\t\t          5. Merge Sort             \n";
		cout << "\t\t\t          6. Quick Sort             \n";
		cout << "\t\t\t          7. EXIT                   \n";
		cout << "\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
		cout << "Enter your choice:";
		cin >> choice;
		switch (choice) {
		case 1:
			do {
				cout << "Enter number of elements(MAX SIZE = 10) in an array:";
				cin >> num;
				if (num >= 10)
					cout << "ERROR ! Size must be under 10\n";
				else
					break;
			} while (true);
			cout << "Enter an array to be sorted:";
			for (int i = 0; i < num; i++) 
				cin >> array[i];
			flag = true;
			break;
		case 2:
			if (flag) {
				cout << "Unsorted Array: ";
				printArray(array, num);
				cout << endl;
				bubbleSort(array, num);
				cout << "Sorted Array: ";
				printArray(array, num);
				cout << endl;
			}
			else
				cout << "ERROR! First create a new array\n";
			break;
		case 3:
			if (flag) {
			cout << "Unsorted Array: ";
			printArray(array, num);
			cout << endl;
			selectionSort(array, num);
			cout << "Sorted Array: ";
			printArray(array, num);
			cout << endl;
			}
			else
				cout << "ERROR! First create a new array\n";
			break;
		case 4: 
			if (flag) {
			cout << "Unsorted Array: ";
			printArray(array, num);
			cout << endl;
			insertionSort(array, num);
			cout << "Sorted Array: ";
			printArray(array, num);
			cout << endl;
			}
			else
				cout << "ERROR! First create a new array\n";
			break;
		case 5: 
			if (flag) {
			cout << "Unsorted Array: ";
			printArray(array, num);
			cout << endl;
			mergeSort(array, 0, num - 1);
			cout << "Sorted Array: ";
			printArray(array, num);
			cout << endl;
			}
			else
				cout << "ERROR! First create a new array\n";
			break;
		case 6:
			if (flag) {
			cout << "Unsorted Array: ";
			printArray(array, num);
			cout << endl;
			quickSort(array, 0, num - 1);
			cout << "Sorted Array: ";
			printArray(array, num);
			cout << endl;
			}
			else
				cout << "ERROR! First create a new array\n";
			break;
		case 7:
			exit(-1);
		default:
			cout << "Invalid command!\n";
		}
	}

	system("pause");
	return 0;
}