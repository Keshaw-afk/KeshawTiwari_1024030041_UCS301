#include <stdio.h>
#include <stdlib.h>
// 1 <= n <= 1e9
// 1<= a_i <= 1e9
//Sample input for examiner
// 5 1
// 3 2 1 5 4

void sort(int* arr, int size){
    for (int i = 0; i<size; i++){
        for (int j = 0; j<size-i-1; j++){
            if (arr[j+1] < arr[j]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    //printf("%d %d\n", n, k);
    int* arr = malloc(sizeof(int)*1e9);
    for (int i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    // for (int i = 0; i<n; i++){
    //     printf("%d ", arr[i]);
    // }
    sort(arr, n);
    int count = 0;
    for (int i = 0; i<n-1; i++){
        for (int j = i+1; j<n; j++){
            int diff = abs(arr[j]-arr[i]);
            if (diff == k){
                count++;
            }
        }
    }
    printf("%d\n", count);
    

    return 0;
}
