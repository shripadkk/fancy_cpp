#include <iostream>

void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void bubbleSort(int* arr, int arrSize) {
    for(int i = 0;i<arrSize;i++) {
        for(int j = i+1;j<arrSize;j++) {
            if(arr[j] < arr[i])
                swap(arr,i,j);
        }
    }
}


void selectionSort(int* arr, int arrSize) {
    for (int i =0;i< arrSize;i++) {
        int min = i;
        for(int j = i+1;j < arrSize; j++) {
            if(arr[j] < arr[min])
                min = j;
        }

        if(min != i)
            swap(arr,min,i);
    }
}

int main()
{
    int arr[] = {2,4,5,6,3,1,2};
    std::cout <<"Unsorted array"<<std::endl;
    for(int k = 0;k < 7;k++) {
        std::cout<<arr[k]<<" ";
    }
    //bubbleSort(arr,7);
    selectionSort(arr,7);

    std::cout <<std::endl<<"Sorted array"<<std::endl;
    for(int k = 0;k < 7;k++) {
        std::cout<<arr[k]<<" ";
    }
}


