#include <iostream>

typedef struct SparseMatrixCell{
    int rowIdx;
    int colIdx;
    int val;
} SMC;

bool isLessSparseMatrix(SMC& a, SMC& b);
void sortMatrix(SMC* matrix, int size);
void transpose(SMC* matrix, int size);
void printSparseMatrix(SMC* matrix, int size);
int addition(SMC* matrix1, int size1, SMC* matrix2, int size2, SMC* result);

void sortMatrix(SMC* matrix, int size){
    for (int i = 0; i<size; i++){
        for (int j = 0; j<size-i-1; j++){
            if (isLessSparseMatrix(matrix[j+1], matrix[j])){
                SMC temp = matrix[j]; 
                matrix[j] = matrix[j+1];
                matrix[j+1] = temp;
            }
        }  
    }
}


int addition(SMC* matrix1, int size1, SMC* matrix2, int size2, SMC* result){
    int i = 0; int j = 0; int k = 0;
    while(i<size1 && j<size2){
        if (isLessSparseMatrix(matrix1[i], matrix2[j])){
            result[k] = matrix1[i];
            k++;
            i++;
        } else if (isLessSparseMatrix(matrix2[j], matrix1[i])){
            result[k] = matrix2[j];
            k++;
            j++;
        } else {
            int val = matrix1[i].val + matrix2[j].val;
            if (val != 0){
                result[k] = {matrix1[i].rowIdx, matrix1[i].colIdx, val};
                k++;
            }
            i++;
            j++;
        }
    }
    while(i<size1){
        result[k] = matrix1[i];
        k++;
        i++;
    }
    while(j<size2){
        result[k] = matrix2[j];
        k++;
        j++;
    }
    return k;
}

bool isLessSparseMatrix(SMC& a, SMC& b){
    if (a.rowIdx < b.rowIdx) return true;
    if (a.rowIdx == b.rowIdx && a.colIdx < b.colIdx) return true;
    return false;
}

void transpose(SMC* matrix, int size){
    for (int i = 0; i<size; i++){
        int temp = matrix[i].colIdx;
        matrix[i].colIdx = matrix[i].rowIdx;
        matrix[i].rowIdx = temp;
    }

    sortMatrix(matrix, size);
}

void printSparseMatrix(SMC* matrix, int size){
    for (int i = 0; i<size; i++){
        int a = matrix[i].rowIdx;
        int b = matrix[i].colIdx;
        int c = matrix[i].val;
        std::cout << "(" << a << ", " << b << ", " << c << ")" << std::endl;
    }
}

int main(){
    SMC* a = new SMC[3]; 
    int size = 3;
    a[0] = {1, 2, 1};
    a[1] = {2, 3, 4};
    a[2] = {2, 2, 5};
    SMC* b = new SMC[size];
    b = a;
    std::cout << "Initial Sparse matrix: " << std::endl;
    printSparseMatrix(b, size);
    transpose(b, size);
    std::cout << "Transposed Sparse matrix: " << std::endl;
    printSparseMatrix(b, size);

    std::cout << "Matrix a: " << std::endl;
    printSparseMatrix(a, size);
    std::cout << "Matrix b: " << std::endl;
    printSparseMatrix(b, size);
    SMC* resultMatrix = new SMC[size+size];
    int resultSize = addition(a, size, b, size, resultMatrix);
    std::cout << "Addition of a and b: " << std::endl;
    printSparseMatrix(resultMatrix, resultSize);

    return 0;

}
