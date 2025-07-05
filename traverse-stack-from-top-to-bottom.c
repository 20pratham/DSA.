
#define MAX 100
int stack[MAX];
int top = -1;
void push(int value) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = value;
    }
}
void printStack() {
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int n, value;
     scanf("%d", &n);
     for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(value);
    }

    printStack();
   return 0;
}