#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100000

typedef struct {
    int data[MAX];
    int top;
} Stack;

void push(Stack *s, int value) {
    s->data[++(s->top)] = value;
}

int pop(Stack *s) {
    if (s->top == -1) return -1; // empty stack
    return s->data[(s->top)--];
}

int peek(Stack *s) {
    if (s->top == -1) return -1; // empty stack
    return s->data[s->top];
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int main() {

    int q;
    scanf("%d", &q);

    Stack stackEnqueue, stackDequeue;
    stackEnqueue.top = -1;
    stackDequeue.top = -1;

    for (int i = 0; i < q; i++) {
        int queryType;
        scanf("%d", &queryType);

        if (queryType == 1) {
            int x;
            scanf("%d", &x);
            push(&stackEnqueue, x);
        } else if (queryType == 2) {
            if (isEmpty(&stackDequeue)) {
                while (!isEmpty(&stackEnqueue)) {
                    int val = pop(&stackEnqueue);
                    push(&stackDequeue, val);
                }
            }
            pop(&stackDequeue);
        } else if (queryType == 3) {
            if (isEmpty(&stackDequeue)) {
                while (!isEmpty(&stackEnqueue)) {
                    int val = pop(&stackEnqueue);
                    push(&stackDequeue, val);
                }
            }
            int front = peek(&stackDequeue);
            printf("%d\n", front);
        }
    }

    return 0;
}
