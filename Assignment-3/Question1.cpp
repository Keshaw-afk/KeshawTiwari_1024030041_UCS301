#include <iostream>

// Comments on isFull() method as demanded in question:
// The following implementation is a resizable stack and it will never be full as long as the computer can provide memory.

typedef struct Stack{
    int* arr;
    int size;
    int numberOfElements;
    Stack(){
        arr = new int[1];
        numberOfElements = 0;
        size = 1;
    }
    ~Stack(){
        delete[] arr;
    }
} Stack;

void resizeStack(Stack* stack, int size);
void push(Stack* stack, int item);
int pop(Stack* stack);
int isEmpty(Stack* stack);
void displayStack(Stack* stack);
int peek(Stack* stack);

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
    if (stack->numberOfElements == stack->size) resizeStack(stack, 2*stack->size);
    stack->arr[stack->numberOfElements-1] = item;
}

int pop(Stack* stack){
    int item = stack->arr[stack->numberOfElements-1]; 
    stack->numberOfElements--;
    if (stack->numberOfElements <= stack->size / 4){
        resizeStack(stack, stack->size / 2);
    }

    return item;
}

void resizeStack(Stack* stack, int size){
    int* arr = new int[size];
    for (int i = 0; i<size; i++){
        arr[i] = 0;
    }
    int numberOfElements = (size > stack->size) ? stack->size : size;
    for (int i = 0; i<numberOfElements; i++){
        arr[i] = stack->arr[i];
    }
    delete[] stack->arr;
    stack->arr = arr;
    stack->size = size;
};

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
