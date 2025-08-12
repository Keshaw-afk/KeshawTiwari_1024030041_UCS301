#include <iostream>

int countInversions(int* array, int size){
    int count = 0;
    for (int i = 0; i<size; i++){
        for (int j = 0; j<size-i-1; j++){
            if (array[j] > array[j+1]){
                count++;
            }
        }
    }
    return count;
}

void printArray(int* array, int size){
    for (int i = 0; i<size; i++){
        std::cout << *array << " ";
        array++;
    }
    std::cout << std::endl;
}


int main(){
    int arr[] = {8, 4, 2, 1};
    int size = sizeof(arr)/sizeof(int);
    std::cout << "Array: " << std::endl;
    printArray(arr, size);
    std::cout << "Number of inversions: " << countInversions(arr, size) << std::endl;




    return 0;
}
