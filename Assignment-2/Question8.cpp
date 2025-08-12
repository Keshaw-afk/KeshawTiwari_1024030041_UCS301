#include <iostream>

int countDistinct(int* array, int size){
    int* dummy = new int[size];
    int count = 0;

    for (int i = 0; i<size; i++){
        bool found = false;
        for (int j = 0; j<count; j++){
            if (array[i] == dummy[j]){
                found = true;
                break;
            }
        }
        if (!found){
            dummy[count] = array[i];
            count++;
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
    int n = 4;
    int arr[4] = {-1, -1, 0, 2};
    std::cout << "Array: " << std::endl;
    printArray(arr, n);
    std::cout << "Unique elements: " << countDistinct(arr, n) << std::endl;
    
}
