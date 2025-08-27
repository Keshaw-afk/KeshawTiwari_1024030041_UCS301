#include <iostream>

//Implementation of stack data structure with a maximum integer capacity of 100 elements. Implemented using array. 

typedef struct Stack{
    int* arr;
    int size;
    int numberOfElements;
    Stack(){
        arr = new int[100];
        numberOfElements = 0;
        size = 100;
    }
    ~Stack(){
        delete[] arr;
    }
} Stack;

void push(Stack* stack, int item);
int pop(Stack* stack);
int isEmpty(Stack* stack);
void displayStack(Stack* stack);
int peek(Stack* stack);
int isFull(Stack* stack);

int isFull(Stack* stack){
    return (stack->numberOfElements == stack->size);
}

int peek(Stack* stack){
    return stack->arr[stack->numberOfElements-1];
}

int isEmpty(Stack* stack){
    return stack->numberOfElements==0;
}

void displayStack(Stack* stack){ std::cout << "-------" << std::endl;
    for (int i = 0; i<stack->numberOfElements; i++){
        std::cout << "|  " << stack->arr[i] << "  |" << std::endl;
    }
    std::cout << "-------" << std::endl;
}

void push(Stack* stack, int item){
    stack->numberOfElements++;
    stack->arr[stack->numberOfElements-1] = item;
}

int pop(Stack* stack){
    int item = stack->arr[stack->numberOfElements-1]; 
    stack->numberOfElements--;

    return item;
}

int main(){
    Stack stack; 
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    
    std::cout << "Size: " << stack.size << std::endl;
    displayStack(&stack);
    std::cout << "Number of elements: " << stack.numberOfElements << std::endl;
    std::cout << "Popped item: " << pop(&stack) << std::endl;
    displayStack(&stack);
    std::cout << "Popped item: " << pop(&stack) << std::endl;
    displayStack(&stack);
    std::cout << "Popped item: " << pop(&stack) << std::endl;
    displayStack(&stack);
    std::cout << "Size: " << stack.size << std::endl;
    if (isEmpty(&stack)){
        std::cout << "Stack is empty" << std::endl;
    }
    return 0; 
}
