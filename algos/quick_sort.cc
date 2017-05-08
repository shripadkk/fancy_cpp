#include <iostream>

void swap(int* arr, int leftIndex, int rightIndex) {
    int temp   = arr[leftIndex];
    arr[leftIndex]  = arr[rightIndex];
    arr[rightIndex] = temp;
}

int partitionFunc (int* arr, int left, int right) {
    int leftIndex = left, rightIndex = right - 1, pivot = arr[right];
    while(1) {
        while(arr[leftIndex] < pivot && leftIndex < right) {
            leftIndex++;
        }

        while(arr[rightIndex] > pivot && rightIndex > 0) {
            rightIndex--;
        }

        if(leftIndex >= rightIndex) {
            break;
        } else {
            swap(arr, leftIndex, rightIndex);
        }
    }

    swap(arr,leftIndex,right);
    return leftIndex;
}

int quick_sort(int* arr, int left, int right) {
    if(left >= right)
        return 0;

    int pivotIndex = partitionFunc(arr, left, right);
    if(pivotIndex > 1)
    {
        quick_sort(arr, left, pivotIndex - 1);
    }

    if(pivotIndex < right)
    {
        quick_sort(arr, pivotIndex + 1, right);
    }

    return 0;
}

int main() {
    int arr[] = {2,9,4,3,1};
    quick_sort(arr,0,4);
    for (int i = 0;i < 5;i++) {
        std::cout <<arr[i]<<" ";
    }
}
