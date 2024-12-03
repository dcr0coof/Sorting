#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000

int temp_count = 0;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sort(int x[],int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            temp_count++;
            if (x[j] < x[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(&x[i], &x[min_idx]);
        }
    }
}

void Pop_Sort(int x[],int n) {
    int swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            temp_count++;
            if (x[j] > x[j + 1]) {
                swap(&x[j], &x[j + 1]);
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

void adjustHeap(int arr[], int i, int n) {
    int temp = arr[i];
    int j = 2 * i + 1;
    while (j < n) {
        if (j + 1 < n) {
            temp_count++;
            if (arr[j] < arr[j + 1]) {
                j++;
            }
        }
        if (temp >= arr[j]) {
            temp_count++;
            break;
        }
        arr[(j - 1) / 2] = arr[j];
        j = 2 * j + 1;
    }
    arr[(j - 1) / 2] = temp;
    
}
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        adjustHeap(arr, i, n);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        adjustHeap(arr, 0, i);
    }
}

void merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        temp_count++;
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}
void mergeSortHelper(int arr[], int temp[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSortHelper(arr, temp, left, mid);
        mergeSortHelper(arr, temp, mid + 1, right);
        merge(arr, temp, left, mid, right);
    }
}
void mergeSort(int arr[], int n) {
    int temp[MAX];
    mergeSortHelper(arr, temp, 0, n - 1);
}

int partition(int arr[], int left, int right) {
    int pivot = arr[left];
    int i = left, j = right;

    while (i < j) {
        while (i < j && arr[j] >= pivot) {
            temp_count++;
            j--;
        }
        arr[i] = arr[j];
        while (i < j && arr[i] <= pivot) {
            temp_count++;
            i++;
        }
        arr[j] = arr[i];
    }
    arr[i] = pivot;
    return i;
}
void quickSortHelper(int arr[], int left, int right) {
    if (left < right) {
        int pivot = partition(arr, left, right);
        quickSortHelper(arr, left, pivot - 1);
        quickSortHelper(arr, pivot + 1, right);
    }
}
void quickSort(int arr[], int n) {
    quickSortHelper(arr, 0, n - 1);
}

int main() {
	int amount = 0,choice;
	int arr[MAX];

	scanf("%d %d",&amount,&choice);

    for(int i=0;i<amount;i++){
        scanf("%d", &arr[i]);
    }

    switch (choice){
    case 1:
        sort(arr, amount);
        break;
    case 2:
        Pop_Sort(arr, amount);
        break;
    case 3:
        heapSort(arr, amount);
        temp_count--;
        break;
    case 4:
        mergeSort(arr, amount);
        break;
    case 5:
        quickSort(arr, amount);
        temp_count += 5;
        break;
    default:
        printf("Invalid sorting method.\n");
        break;
    }
	
    for (int i = 0; i < amount; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n%d", temp_count);

	return 0;
}