#include <stdio.h>
#include <stdlib.h>

//Sample input for examiner
// 5
// 0 2 1 2 0

void sort(int* arr, int n){
    int lo = 0;
    int mid = 0;
    int hi = n-1;
    while(mid <= hi){
        if (arr[mid] == 0){
            int temp = arr[lo];
            arr[lo] = arr[mid];
            arr[mid] = temp;
            lo++;
            mid++;
        }
        else if (arr[mid] == 1){
            mid++;
        } else if (arr[mid] == 2){
            int temp = arr[mid];
            arr[mid] = arr[hi];
            arr[hi] = temp;
            hi--;
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int* arr = malloc(sizeof(int) * 1e9);
    for (int i = 0; i<n; i++){
        scanf("%d ", &arr[i]);
    }
    // for (int i = 0; i<n; i++){
    //     printf("%d ", arr[i]);
    // }
    
    sort(arr, n);
    for (int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }   

    return 0;
}
