#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 // tamanho máximo da pilha e fila

// Estrutura de dados para a pilha
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

// Função para inicializar a pilha
void initializeStack(Stack* stack) {
    stack->top = -1;
}

// Função para verificar se a pilha está cheia
int isFullStack(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Função para verificar se a pilha está vazia
int isEmptyStack(Stack* stack) {
    return stack->top == -1;
}

// Função para inserir um elemento na pilha
void push(Stack* stack, int item) {
    if (isFullStack(stack)) {
        printf("Stack Overflow\n");
    } else {
        stack->top++;
        stack->items[stack->top] = item;
    }
}

// Função para remover um elemento da pilha
int pop(Stack* stack) {
    if (isEmptyStack(stack)) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        int item = stack->items[stack->top];
        stack->top--;
        return item;
    }
}

// Estrutura de dados para a fila
typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Função para inicializar a fila
void initializeQueue(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Função para verificar se a fila está cheia
int isFullQueue(Queue* queue) {
    return queue->rear == MAX_SIZE - 1;
}

// Função para verificar se a fila está vazia
int isEmptyQueue(Queue* queue) {
    return queue->front == -1 && queue->rear == -1;
}

// Função para inserir um elemento na fila
void enqueue(Queue* queue, int item) {
    if (isFullQueue(queue)) {
        printf("Queue Overflow\n");
    } else {
        if (isEmptyQueue(queue)) {
            queue->front = 0;
        }
        queue->rear++;
        queue->items[queue->rear] = item;
    }
}

// Função para remover um elemento da fila
int dequeue(Queue* queue) {
    if (isEmptyQueue(queue)) {
        printf("Queue Underflow\n");
        return -1;
    } else {
        int item = queue->items[queue->front];
        if (queue->front >= queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        } else {
            queue->front++;
        }
        return item;
    }
}

int main() {
    Stack stack;
    Queue queue;

    // inicializa a pilha e a fila
    initializeStack(&stack);
    initializeQueue(&queue);

    // insere alguns elementos na pilha e na fila
    for(int i = 0; i < MAX_SIZE; i++){
        push(&stack, i);
        printf("Elemento adicionado na pilha: %d\n", i);
        enqueue(&queue, i);
        printf("Elemento adicionado na fila: %d\n", i);
    }
    printf("\n");

    // remove alguns elementos da pilha e da fila
    int x = pop(&stack);
    printf("Elemento removido da pilha: %d\n", x);
    x = dequeue(&queue);
    printf("Elemento removido da fila: %d\n", x);
    
    printf("\n\n");
    
    x = pop(&stack);
    printf("Elemento removido da pilha: %d\n", x);
    x = dequeue(&queue);
    printf("Elemento removido da fila: %d\n", x);
    
    printf("\n\n");

    // tenta inserir mais elementos do que o tamanho máximo da pilha ou da fila
    for(int i = 0; i < MAX_SIZE; i++){
        printf("Tenta adicionar na pilha: %d\n", i + MAX_SIZE);
        push(&stack, i + MAX_SIZE);
        printf("Tenta adicionar na fila: %d\n", i + MAX_SIZE);
        enqueue(&queue, i + MAX_SIZE);
        printf("\n");
    }

    // remove todos os elementos restantes da pilha e da fila
    while (!isEmptyStack(&stack)) {
        x = pop(&stack);
        printf("Elemento removido da pilha: %d\n", x);
    }
    while (!isEmptyQueue(&queue)) {
        x = dequeue(&queue);
        printf("Elemento removido da fila: %d\n", x);
    }

    // tenta remover mais elementos do que existem na pilha ou na fila
    x = pop(&stack);
    x = dequeue(&queue);
    
    printf("\n");
    
     for(int i = 0; i < MAX_SIZE; i++){
        push(&stack, i);
        printf("Elemento adicionado na pilha: %d\n", i);
        enqueue(&queue, i);
        printf("Elemento adicionado na fila: %d\n", i);
    }
    printf("\n");
    
     for(int i = 0; i < MAX_SIZE; i++){
        printf("Elemento adicionado na pilha: %d\n", i);
        push(&stack, i);
       
        printf("Elemento adicionado na fila: %d\n", i);
        enqueue(&queue, i);
    }
    printf("\n");
    
    // remove todos os elementos restantes da pilha e da fila
    while (!isEmptyStack(&stack)) {
        x = pop(&stack);
        printf("Elemento removido da pilha: %d\n", x);
    }
    while (!isEmptyQueue(&queue)) {
        x = dequeue(&queue);
        printf("Elemento removido da fila: %d\n", x);
    }
    
    return 0;
}
