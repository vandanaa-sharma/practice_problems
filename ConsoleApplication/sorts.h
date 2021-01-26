#pragma once


void selectionSort(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		int min = arr[i];
		int index = i;
		for (int j = i; j < size; j++) {
			if (arr[j] < min) {
				min = arr[j];
				index = j;
			}
		}
		if (arr[i] != min) {
			int temp = arr[i];
			arr[i] = min;
			arr[index] = temp;
		}
	}
}


void bubbleSort(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void insertionSort(int arr[], int size) {
	int i, j;
	int key;
	for (i = 1; i < size; i++) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}
