#include <iostream>

void printArray(int* array, int size);
void bubbleSort(int* array, int size);
int binarySearch(int * array, int size, int target);

int binarySearch(int* array, int size, int target){
    int lo = 0;
    int hi = size-1;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if (array[mid] == target){
            return mid;
        }
        else if (array[mid] < target){
            lo = mid+1;
        } else if (array[mid] > target){
            hi = mid-1;
        }
    }
    return -1;
}

void printArray(int* array, int size){
    for (int i = 0; i<size; i++){
        std::cout << *array << " ";
        array++;
    }
    std::cout << std::endl;
}


void bubbleSort(int* array, int size){
    for (int i = 0; i<size; i++){
        for (int j = 0; j<size-i-1; j++){
            if (array[j] > array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int main(){
    int array[] = {23, 87, 4, 15, 99, 46, 10, 67, 55, 1};
    int size = sizeof(array)/sizeof(int);

    std::cout << "Unsorted array: " << std::endl;
    printArray(array, size);
    bubbleSort(array, size);
    std::cout << "Sorted array: " << std::endl;
    printArray(array, size); 
    int target = 46;
    std::cout << "Sample target element: " << target << std::endl;
    int index = binarySearch(array, size, target);
    if (index == -1){
        std::cout << "Target not found" << std::endl;
    } else {
        std::cout << "Target " << target << " found at " << index << std::endl;
    }
    

    return 0; 
}
