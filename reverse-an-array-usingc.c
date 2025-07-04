#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->data[++s->top] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->data[s->top--];
}

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[MAX_SIZE];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    Stack s;
    initialize(&s);
    
    // Push all elements onto the stack
    for (int i = 0; i < n; i++) {
        push(&s, arr[i]);
    }
    
    // Pop all elements to get the reversed array
    int reversed_arr[MAX_SIZE];
    for (int i = 0; i < n; i++) {
        reversed_arr[i] = pop(&s);
    }
    
    // Output the reversed array
    for (int i = 0; i < n; i++) {
        printf("%d ", reversed_arr[i]);
    }
    printf("\n");
    
    return 0;
}